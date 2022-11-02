#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty,x=0;
void producer()
{
	--mutex;
	++full;
	--empty;
	printf("Producer produces item %d\n",++x);
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("Consumer consumes item %d\n",x);
	--x;
}
void main()
{
	printf("Enter the size of the bucket ");
	scanf("%d",&empty);
	while(1)
	{
		int n= rand();
		if(n%2==0)
		{
			if(empty!=0)
			{
				producer();
			}
		}
		else
		{
			if(full!=0)
			{
				consumer();
			}
		}
	}
}
