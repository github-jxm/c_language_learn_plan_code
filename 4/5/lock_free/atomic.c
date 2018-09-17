/*
 * File:    atomic.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "iatomic.h"

#ifdef ATOMIC_TEST

atomic_t g_count = {0};

static void* thread_inc(void* param)
{
	int i = 0;
	for(i = 0; i < 1000000; i++){
		atomic_inc(&g_count);
	}

	return NULL;
}

static void* thread_dec(void* param)
{
	int i = 0;
	for(i = 0; i < 1000000; i++){
		atomic_dec(&g_count);
	}

	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t inc_tid = 0;
	pthread_t dec_tid = 0;

	pthread_create(&inc_tid, NULL, thread_inc, NULL);
	pthread_create(&dec_tid, NULL, thread_dec, NULL);

	pthread_join(inc_tid, NULL);
	pthread_join(dec_tid, NULL);

	printf("count=%d\n", g_count.counter);

	return 0;
}
#endif/*ATOMIC_TEST*/
