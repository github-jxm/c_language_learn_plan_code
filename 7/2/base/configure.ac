#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([base], [0.1], [cjiangxumin@gmail.com])
AC_CONFIG_SRCDIR([src/sort.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

#  ./configure  --enable-debug 时，  CFLAGS="${CFLAGS} -g -O0"
#  ./configure                 时，  CFLAGS="-m32 -g -O2"
AC_ARG_ENABLE([debug],
	      [AS_HELP_STRING([--enable-debug],[debug program(default is no)])],
	      [CFLAGS="${CFLAGS} -m3 -g -O0"],
	      [CFLAGS="-m32 -g -O2"]
	    )

# Checks for programs.
AM_PROG_AR
AC_PROG_CC
AC_PROG_LIBTOOL  # 检查 libtool

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
#AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])  #检查头文件是否存在

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC  #检查标准malloc函数是否存在
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT(base.pc)
