all:
	gcc -Wall -m32 -g -DDARRAY_TEST darray.c -o darray_test
	gcc -Wall -m32 -g -DDLIST_TEST dlist.c -o dlist_test
	gcc -Wall -m32 -g -shared darray.c  dlist.c  linear_container_darray.c linear_container_dlist.c queue.c -o libcontainer.so
	gcc -Wall -m32 -g linear_container_test.c -L./ -lcontainer -o container_test
	gcc -Wall -m32 -g queue.c linear_container_dlist.c dlist.c -DQUEUE_TEST -o queue_test
	gcc -Wall -m32 -g module_linux.c module_test.c -ldl -o module_test
	gcc -Wall -m32 -g module_linux.c queue.c queue_test.c -ldl -o queue_dynamic_test
	gcc -m32 -g call_cos.c -ldl -o call_cos

clean:
	rm *test *.so call_cos
