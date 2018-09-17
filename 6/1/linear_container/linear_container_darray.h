/*
 * File:    linear_container_darray.h
 */

#ifndef LINEAR_CONTAINER_DARRAY_H
#define LINEAR_CONTAINER_DARRAY_H

#include "linear_container.h"

DECLS_BEGIN

LinearContainer* linear_container_darray_create(DataDestroyFunc data_destroy, void* ctx);

DECLS_END

#endif/*LINEAR_CONTAINER_DARRAY_H*/

