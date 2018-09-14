CFILES=dlist.c  locker_pthread.c locker_nest.c
all:
	gcc -g -m32 -shared -lpthread $(CFILES) -o libdlist.so
	gcc -g -m32 -DDLIST_TEST  $(CFILES)  -o dlist_test -lpthread

clean:
	rm -f *test *.exe *.so
