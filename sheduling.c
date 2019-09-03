
#include<stdio.h>

void insert(int item,int *r,int q[]);
void insert(int item,int *r,int q[])
{
	if(*r==99)
	{
		printf("queue overflow\n");
		return;
	}
	q[++(*r)]=item;
}
int main()
{
	int bt[100];
	int i,n,it;
	int re=-1;
	printf("enter the no.of process\n");
	scanf("%d",&n);
	printf("enter the burst time of each process\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&it);
		insert(it,&re,bt);
	}
	printf("process 1 starts at 0th and ends at %d th second \n",bt[0]);	
	for(i=1;i<n;i++)
	{
		bt[i]=bt[i-1]+bt[i];
		printf("process %d starts at %d th and ends at %dth second \n",(i+1),bt[i-1],bt[i]);
	}
	return 0;
}	
