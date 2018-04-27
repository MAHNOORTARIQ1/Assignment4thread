#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * SumthreadFunc(void * arg);
int sindex=0;
int eindex=99;
int hundredvalsum;

int main(){
	int values[1000];
	int finalsum=0;
	for(int i=0;i<1000;i++)
	{
		values[i]=i+1;
	}

	pthread_t athread[10];
	int threadsum[10];

	for(int j=0;j<10;j++)
	{
		pthread_create(&athread[j],NULL,SumthreadFunc,(void*)values);
		pthread_join(athread[j],NULL);
		sindex=sindex+100;
		eindex=eindex+100;

		threadsum[j]=hundredvalsum;
		finalsum=finalsum+threadsum[j];
	}

	printf("final sum of 10 threads is:%d",finalsum);

	return 0;
	}

void * SumthreadFunc(void * arg)
{
	hundredvalsum=0;
	int *values1=(int*)arg;
	for(int j=sindex;j<=eindex;j++)
	{
		hundredvalsum=hundredvalsum+values1[j];
	}

	pthread_exit(0);
}





























