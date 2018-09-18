# 函数库名称
lib_LTLIBRARIES=libbase.la

# 生成libbase.la 所需要的源文件
libbase_la_SOURCES= darray.c \
	darray.h \
	dlist.c \
	dlist.h \
	darray_iterator.h \
	dlist_iterator.h \
	hash_table.c \
	hash_table.h \
	invert.c \
	iterator.h \
	linear_container_darray.c \
	linear_container_darray.h \
	linear_container_dlist.c \
	linear_container_dlist.h \
	linear_container.h \
	queue.c \
	queue.h \
	sort.c \
	sort.h \
	stack.c \
	stack.h \
	typedef.h 

# 指定libbase_la连接所需要的关键字
libbase_la_LDFLAGS=-lpthread

#不需要安装的可执行文件
noinst_PROGRAMS=darray_test dlist_test

darray_test_SOURCES=darray.c
darray_test_CFLAGS=-DDARRAY_TEST

dlist_test_SOURCES=dlist.c
dlist_test_CFLAGS=-DDLIST_TEST

# 头文件安装目录
basedir=$(includedir)/base

# 需要安装的头文件
# xxx_HEADERS 与  xxxdir 配套使用
base_HEADERS=darray.h dlist.h iterator.h linear_container_dlist.h typedef.h \
	darray_iterator.h  dlist_iterator.h  linear_container_darray.h  \
	linear_container.h

EXTRA_DIST=\
	linear_container_test.c \
	invert_ng.c \
	darray_iterator.c \
	dlist_iterator.c \
	test_helper.c 
