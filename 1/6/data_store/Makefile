ARCH=-m32
all:
	gcc -g ${ARCH} toupper.c -o toupper_test
	gcc -g ${ARCH} dlist.c dlist_toupper.c -o dlist_toupper_test
	gcc -g ${ARCH} bss.c -o bss.exe
	gcc -g ${ARCH} data.c -o data.exe
	gcc -g ${ARCH} heap_error.c -o heap_error_test
clean:
	rm -f *test *.exe
