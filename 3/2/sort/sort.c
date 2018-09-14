/*
 * File:    sort.c
 */

#include "sort.h"

Ret bubble_sort(void** p_array, size_t nr, DataCompareFunc cmp)
{
	size_t i     = 0;
	size_t max   = 0;
	size_t right = 0;


	return_val_if_fail(p_array != NULL && cmp != NULL, RET_INVALID_PARAMS);

	if(nr < 2){
		return RET_OK;
	}
	
	intptr_t* array = (intptr_t*)p_array;

	for(right = nr - 1; right > 0; right--){
		for(i = 1, max = 0; i < right; i++){
			if(cmp((void *)(array[i]), (void *)(array[max])) > 0){
				max = i;
			}
		}

		if(cmp((void *)(array[max]), (void *)(array[right])) > 0){
			intptr_t data = array[right];
			array[right] = array[max];
			array[max] = data;
		}
	}

	return RET_OK;
}

void quick_sort_impl(void** p_array, size_t left, size_t right, DataCompareFunc cmp)
{
	size_t save_left  = left;
	size_t save_right = right;
	
	intptr_t * array = (intptr_t *) p_array;    	

	intptr_t x = array[left];
	/*这个循环，让小于x的元素在左边，大于x的元素在右边*/
	while(left < right){
		while(cmp((void*)(array[right]), (void *) x) >= 0 && left < right) right--;
		if(left != right){
			array[left] = array[right];
			left++;
		}

		while(cmp((void *)(array[left]), (void *) x) <= 0 && left < right)	left++;
		if(left != right){
			array[right] = array[left];
			right--;
		}
	}
	array[left] = x;

	if(save_left < left){
		quick_sort_impl((void **)array, save_left, left-1, cmp);
	}

	if(save_right > left){
		quick_sort_impl((void **)array, left+1, save_right, cmp);
	}

	return;
}

Ret quick_sort(void** array, size_t nr, DataCompareFunc cmp)
{
	Ret ret = RET_OK;

	return_val_if_fail(array != NULL && cmp != NULL, RET_INVALID_PARAMS);

	if(nr > 1){
		quick_sort_impl(array, 0, nr - 1, cmp);
	}

	return ret;
}

static Ret merge_sort_impl(void** p_storage, void** p_array, size_t low, size_t mid, size_t high, DataCompareFunc cmp)
{
	size_t i = low;
	size_t j = low;
	size_t k = mid;

	intptr_t* storage = (intptr_t *) p_storage;
	intptr_t* array = (intptr_t *) p_array;
  
	/* 对左半部分排序 */
	if((low + 1) < mid){
		size_t x = low + ((mid - low) >> 1);
		merge_sort_impl(p_storage, p_array, low, x, mid, cmp);
	}
	
	/* 对右半部分排序 */
	if((mid + 1) < high){
		size_t x = mid + ((high - mid) >> 1);
		merge_sort_impl(p_storage, p_array, mid, x, high, cmp);
	}

	/* 合并两个有序数组 */	
	while(j < mid && k < high){
		if(cmp((void *)(array[j]), (void *)(array[k])) <= 0) {
			storage[i++] = array[j++];
		}
		else{
			storage[i++] = array[k++];
		}
	}

	while(j < mid){
		storage[i++] = array[j++];
	}

	while(k < high){
		storage[i++] = array[k++];
	}

	for(i = low; i < high; i++){
		array[i] = storage[i];
	}

	return RET_OK;
}

Ret merge_sort(void** array, size_t nr, DataCompareFunc cmp)
{
	void** storage = NULL;
	Ret ret = RET_OK;

	return_val_if_fail(array != NULL && cmp != NULL, RET_INVALID_PARAMS);

	if(nr > 1)
	{
		storage = (void**)malloc(sizeof(void*) * nr);
		if(storage != NULL)
		{
			ret = merge_sort_impl(storage, array, 0, nr>>1, nr, cmp);

			free(storage);
		}
	}

	return ret;
}


#ifdef SORT_TEST
#include <assert.h>
intptr_t int_cmp(void* a, void* b)
{
	return (intptr_t)a - (intptr_t)b;
}

intptr_t int_cmp_invert(void* a, void* b)
{
	return (intptr_t)b - (intptr_t)a;
}

static void** create_int_array(intptr_t n)
{
	intptr_t i = 0;
	intptr_t* array = (intptr_t*)malloc(sizeof(intptr_t) * n);
	for(i = 0; i < n; i++)
	{
		array[i] = rand();
	}

	return (void**)array;
}

static void sort_test_one_asc(SortFunc sort, intptr_t n)
{
	intptr_t i = 0;
	void** p_array = create_int_array(n);

	sort(p_array, n, int_cmp);

	intptr_t* array =  (intptr_t *)p_array;
	for(i = 1; i < n; i++)
	{
		assert(array[i] >= array[i-1]);
	}

	free(array);

	return;
}

static void sort_test_one_dec(SortFunc sort, intptr_t n)
{
	intptr_t i = 0;
	void** p_array = create_int_array(n);

	sort((void**)p_array, n, int_cmp_invert);


	intptr_t* array =  (intptr_t *)p_array;
	for(i = 1; i < n; i++)
	{
		assert(array[i] <= array[i-1]);
	}

	free(array);

	return;
}

static void sort_test(SortFunc sort)
{
	intptr_t i = 0;
	for(i = 0; i < 1000; i++) {
		sort_test_one_dec(sort, i);
		sort_test_one_asc(sort, i);
	}
	return ;
}

intptr_t main(intptr_t argc, char* argv[])
{
	srand(100);
	sort_test(bubble_sort); // 冒泡排序 测试
	sort_test(quick_sort);  // 快速排序 测试
	sort_test(merge_sort);  // 归并排序 测试

	return 0;
}
#endif/*SORT_TEST*/
