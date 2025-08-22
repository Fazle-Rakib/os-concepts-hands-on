#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_fun(void *arg);
int main()
{
	pthread_t thread1;
	int ara[3] = {1, 2, 3};
	pthread_create(&thread1,NULL,thread_fun,(void *)ara);
	void *sum_p;
	pthread_join(thread1,&sum_p);
	printf("Back to main process\n");
	int *sum = (int *)sum_p;
	printf("Sum of elements: %d\n", *sum);
	return 0;
}
void *thread_fun(void *arg){
	printf("Inside thread\n");
	int *array = (int *)arg;
	int sum = 0;
	for(int i=0;i<3;i++)
	{
		sum += array[i];
		printf("Element %d has been summed. Current sum: %d\n", i, sum);
		sleep(1);
	}
	int *result_p = (int *)malloc(sizeof(int));
	*result_p = sum;
	return (void *)result_p;
}