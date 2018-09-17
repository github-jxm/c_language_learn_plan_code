all:
	gcc -Wall -m32 -g -DDARRAY_TEST darray.c -o darray_test
	gcc -Wall -m32 -g -DDLIST_TEST dlist.c -o dlist_test
	gcc -Wall -m32 -g -shared darray.c  dlist.c  linear_container_darray.c linear_container_dlist.c -o libcontainer.so
	gcc -Wall -m32 -g linear_container_test.c -L./ -lcontainer -o container_test
	gcc -Wall -m32 -g invert_ng.c -DINVERT_TEST -L./ -lcontainer -o invert_ng_test
	gcc -Wall -m32 -g invert.c -DINVERT_TEST -L./ -lcontainer -o invert_test
clean:
	rm *test *.so
