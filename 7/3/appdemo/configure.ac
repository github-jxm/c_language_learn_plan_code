#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([appdemo], [0.1], [cjiangxumin@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

#  ./configure  --enable-debug 时，  CFLAGS="${CFLAGS} -g -O0"
#  ./configure                 时，  CFLAGS="-m32 -g -O2"
AC_ARG_ENABLE([debug],
	      [AS_HELP_STRING([--enable-debug],[debug program(default is no)])],
	      [CFLAGS="${CFLAGS} -m3 -g -O0"],
	      [CFLAGS="-m32 -g -O2"]
	    )


AM_PROG_AR
# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL   # 添加, 解决:appdemo/src/main.c:5: undefined reference to `dlist_create'

# Checks for libraries.
PKG_CHECK_MODULES(BASE, ["base"]) # 检查软件包base, 通过调用pkg-config,生成BASE_CFLAGS,BASE_LIBS
AC_SUBST(BASE_CFLAGS)   # 把所有对BASE_CFLAGS的引用替换成实际的参数,即把Makefile.am中的@BASE_CFLAGS@替换成实际值
AC_SUBST(BASE_LIBS)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
