ARCH=-m32
all:
	gcc -g ${ARCH} -fPIC -shared dlist.c -o libdlist.so 
	gcc -g ${ARCH} -DDLIST_TEST dlist.c  -o dlist_test

clean:
	rm -f *test *.exe *.so
