#include "dlist.h"
#include <string.h>
#include <stdio.h>

static DListRet str_toupper(void* ctx, void* data)
{
	char* p = (char*)data;
	if(p != NULL)
	{
		while(*p != '\0')
		{
			if(islower(*p))
			{
				*p = toupper(*p);
			}
			p++;
		}
	}

	return DLIST_RET_OK;
}

static DListRet str_print(void* ctx, void* data)
{
	printf("%s\n", data);
	
	return DLIST_RET_OK;
}

/* 双向链表中存放常量字符串，转换时出现段错误*/
static void demo_const(void)
{
	DList* dlist = dlist_create(NULL, NULL);
	dlist_append(dlist, "It");
	dlist_append(dlist, "is");
	dlist_append(dlist, "OK");
	dlist_append(dlist, "!");
	dlist_foreach(dlist, str_toupper, NULL);
	dlist_destroy(dlist);

	return ;
}

/* 双向链表中存放的是临时变量，转换后发现所有字符串都一样*/
static void demo_temp(void)
{
	char str[256] = {0};
	DList* dlist = dlist_create(NULL, NULL);
	strcpy(str, "It");
	dlist_append(dlist, str);
	strcpy(str, "is");
	dlist_append(dlist, str);
	strcpy(str, "OK");
	dlist_append(dlist, str);
	strcpy(str, "!");
	dlist_append(dlist, str);
	dlist_foreach(dlist, str_toupper, NULL);
	dlist_foreach(dlist, str_print, NULL);
	dlist_destroy(dlist);

	return ;
}

static void data_free(void* ctx, void* data)
{
	free(data);

	return;
}

/*存放时，复制了数据，但没有释放所分配的内存*/
static void demo_heap(void)
{
	DList* dlist = dlist_create(data_free, NULL);
	dlist_append(dlist, strdup("It"));
	dlist_append(dlist, strdup("is"));
	dlist_append(dlist, strdup("OK"));
	dlist_append(dlist, strdup("!"));
	dlist_foreach(dlist, str_toupper, NULL);
	dlist_foreach(dlist, str_print, NULL);
	dlist_destroy(dlist);

	return ;
}

int main(int argc, char* argv[])
{
	demo_temp();
	demo_heap();
	demo_const();

	return 0;
}
