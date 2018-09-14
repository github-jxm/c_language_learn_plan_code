/*
 * File:    sort.h
 */

#ifndef SORT_H
#define SORT_H

#include "typedef.h"

Ret bubble_sort(void** array, size_t nr, DataCompareFunc cmp);
Ret quick_sort(void** array, size_t nr, DataCompareFunc cmp);
Ret merge_sort(void** array, size_t nr, DataCompareFunc cmp);

#endif/*SORT_H*/

