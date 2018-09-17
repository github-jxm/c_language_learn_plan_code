all:
	# -Wno-unused-function  发现不使用的函数不警告
	#  darray_test
	gcc -Wall -Wno-unused-function -g -m32 -DDARRAY_TEST darray.c -o darray_test
	#  dlist_test
	gcc -Wall -Wno-unused-function -g -m32 -DDLIST_TEST dlist.c -o dlist_test
	#  queue_test
	gcc -Wall -Wno-unused-function -g -m32 -DQUEUE_TEST dlist.c linear_container_dlist.c  queue.c -o queue_test
	# container_test
	gcc -Wall -Wno-unused-function -g -m32 -shared darray.c  dlist.c  linear_container_darray.c linear_container_dlist.c queue.c -o libcontainer.so
	gcc -Wall -Wno-unused-function -g -m32 linear_container_test.c -L./ -lcontainer -o container_test
clean:
	rm *test *.so
