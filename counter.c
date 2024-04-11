#include <stdio.h>
#include <pthread.h>

int count = 100000;

void* change(){
	for(int i = 0; i < 10000; i++){
		count = count - 1;
	}
	return NULL;
}

int main(){

	pthread_t throads[10];

	printf("Счётчик равен %i\n", count);

	for (int i = 0; i < 10; i++){
		pthread_create(&throads[i], NULL, change, NULL);
	}

	void* result;

	for (int i = 0; i < 10; i++){
		pthread_join(throads[i], &result);
	
	}
	printf("Счётчик равен %i\n", count);
	return 0;
}
