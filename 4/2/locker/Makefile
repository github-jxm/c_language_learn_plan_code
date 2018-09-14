CFILES=dlist.c  locker_pthread.c 
all:
	gcc -g -m32 -fPIC -shared -lpthread $(CFILES)  -o libdlist.so  
	gcc -g -m32 -DDLIST_TEST  $(CFILES)  -o dlist_test  -lpthread

clean:
	rm -f *test *.exe *.so
