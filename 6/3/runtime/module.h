/*
 * File:    module.h
 */

#ifndef MODULE_H
#define MODULE_H
#include "typedef.h"

DECLS_BEGIN

struct _Module;
typedef struct _Module Module;

typedef enum _ModuleFlags
{
	MODULE_FLAGS_NONE,
	MODULE_FLAGS_DELAY = 1
}ModuleFlags;

Module* module_create(const char* file_name, ModuleFlags flags);
void*   module_sym(Module* thiz, const char* func_name);
void    module_destroy(Module* thiz);

DECLS_END

#endif/*MODULE_H*/

