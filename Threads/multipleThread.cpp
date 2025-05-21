#include<stdio.h>
#include <iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

struct thread_data
{
    int *array;
    int start;
    int end;
};

void *partial_sum(void *arg) {
    int sum=0;
    thread_data *data = (thread_data *)arg;
    for(int i=data->start;i<data->end;i++)
    {
        sum+=data->array[i];
    }
    int *sum_ptr = new int(sum);
    return (void *)sum_ptr;
}


int main()
{
    int array[100];
    for(int i=0;i<100;i++)
    {
        array[i]=i+1;
    }
    thread_data data1, data2;
    data1.array = array;
    data1.start = 0;
    data1.end = sizeof(array)/sizeof(array[0])/2;

    data2.array = array;
    data2.start = sizeof(array)/sizeof(array[0])/2;
    data2.end = sizeof(array)/sizeof(array[0]);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, partial_sum, (void *)&data1);

    pthread_create(&thread2, NULL, partial_sum, (void *)&data2);

    void* sum1, *sum2;
    int* sum_first_half;
    int* sum_second_half;

    pthread_join(thread1, &sum1);
    pthread_join(thread2, &sum2);

    sum_first_half = (int*)sum1;
    sum_second_half = (int*)sum2;

    cout<<"Sum of first half: "<<*sum_first_half<<endl;
    cout<<"Sum of second half: "<<*sum_second_half<<endl;
    cout<<"Total sum: "<<*sum_first_half+*sum_second_half<<endl;

    delete sum_first_half;
    delete sum_second_half;
}