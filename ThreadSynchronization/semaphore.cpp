#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>

using namespace std;

void *thread_fun_1(void *arg);
void *thread_fun_2(void *arg);

int shared = 4;
sem_t s;

int main()
{
    pthread_t thread1, thread2;
    sem_init(&s, 0, 1); // Initialize semaphore with value 1
    pthread_create(&thread1, NULL, thread_fun_1, NULL);
    pthread_create(&thread2, NULL, thread_fun_2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared variable: %d\n", shared);
    sem_destroy(&s); // Destroy the semaphore
    return 0;
}

void *thread_fun_1(void *arg)
{
    sem_wait(&s); // Wait (decrement) the semaphore
    printf("Thread 1: Entering critical section\n");
    int temp = shared;
    sleep(1); // Simulate some work in the critical section
    shared = temp + 1;
    printf("Thread 1: Exiting critical section, shared = %d\n", shared);
    sem_post(&s); // Signal (increment) the semaphore
    return NULL;
}

void *thread_fun_2(void *arg)
{
    sem_wait(&s); // Wait (decrement) the semaphore
    printf("Thread 2: Entering critical section\n");
    int temp = shared;
    sleep(1); // Simulate some work in the critical section
    shared = temp + 2;
    printf("Thread 2: Exiting critical section, shared = %d\n", shared);
    sem_post(&s); // Signal (increment) the semaphore
    return NULL;
}