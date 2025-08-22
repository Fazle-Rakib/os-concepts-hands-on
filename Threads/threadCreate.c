#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_fun(void *arg);
int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,thread_fun,NULL);
	pthread_join(thread1,NULL);
	printf("Back to main process\n");
	for(int i=15;i<20;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
}
void *thread_fun(void *arg){
	printf("Inside thread\n");
	for(int j=0;j<5;j++)
	{
		printf("%d\n",j);
		sleep(1);
	}
	return NULL;
}