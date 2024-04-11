#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}
void* function1()
{
	puts("Первая функция запустилась");
	sleep(5);
	puts("Первая функция запустилась");
	return NULL;
}
void* function2()
{
	puts("Вторая функция запустилась");
	sleep(3);
	puts("Вторая функция запустилась");
	return NULL;
}
int main()
{
	
	pthread_t t0;
	pthread_t t1;
	if (pthread_create(&t0, NULL, function1, NULL) == -1){
		error("Не могу создать поток t0");
	}
	if (pthread_create(&t1, NULL, function2, NULL) == -1){
		error("Не могу создать поток t1");
	}

	void* result;
	if (pthread_join(t0, &result) == -1){
		error("Can't join thread t0");
	}
	if (pthread_join(t1, &result) == -1){
		error("Can't join thread t1");
	}
	pthread_join(t0, &result);
	pthread_join(t1, &result);
	
	
	return 0;
}
