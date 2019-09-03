#include<stdio.h>
void insert(int item,int *r,int q[]);
void display(int s, int q[]);
void insert(int item,int *r,int q[])
{
	if(*r==99)
	{
		printf("queue overflow\n");
		return;
	}
	q[++(*r)]=item;
}
void display(int s,int q[])
{
	int i;
	printf("process 1 starts at 0th and ends at %d th second \n",q[0]);	
	for(i=1;i<s;i++)
	{
		q[i]=q[i-1]+q[i];
		printf("process %d starts at %d th and ends at %d th second \n",		(i+1),q[i-1],q[i]);
	}
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
	display(n,bt);
	return 0;
}	
