all:
	gcc -g -m32 fifo_ring.c  -DFIFO_RING_TEST -o fifo_ring_test -lpthread
	gcc -g -m32 swmr_dlist.c dlist.c -DSWMR_DLIST_TEST -o swmr_dlist_test -lpthread
	gcc -g -m32 atomic.c -lpthread -DATOMIC_TEST -o atomic_test
clean:
	rm -f *test

