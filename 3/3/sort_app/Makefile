all:
	gcc -g -m32 -DDARRAY_TEST -lpthread darray.c sort.c -o darray_test
	gcc -g -m32 -Wall -DSORT_TEST sort.c -o sort_test
	gcc -g -m32 -Wall -DSEARCH_TEST search.c -o search_test
	gcc -g -m32 -Wall -DUNIQUE_TEST unique.c darray.c sort.c -o unique_test

clean:
	rm -f *test *.exe *.so
