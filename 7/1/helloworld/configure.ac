#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([helloworld], [1.0], [jxm_zn@163.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])


#  ./configure  --enable-debug 时，  CFLAGS="${CFLAGS} -g -O0"
#  ./configure                 时，  CFLAGS="-m32 -g -O2"
AC_ARG_ENABLE([debug],
	      [AS_HELP_STRING([--enable-debug],[debug program(default is no)])],
	      [CFLAGS="${CFLAGS} -g -O0"],
	      [CFLAGS="-m32 -g -O2"]
	    )

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
