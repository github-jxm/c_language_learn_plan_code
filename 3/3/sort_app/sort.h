/*
 * File:    sort.h
  */

#ifndef SORT_H
#define SORT_H

#include "typedef.h"

DECLS_BEGIN

Ret bubble_sort(void** array, size_t nr, DataCompareFunc cmp);
Ret quick_sort(void** array, size_t nr, DataCompareFunc cmp);
Ret merge_sort(void** array, size_t nr, DataCompareFunc cmp);

DECLS_END

#endif/*SORT_H*/

