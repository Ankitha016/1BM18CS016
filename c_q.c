#include<stdio.h>
#define size 10
void insertion(int item,int *r,int q[],int *f)
{
	if((*f==*r+1)||(*f==0&&*r==size-1))
	{
		printf("Queue overflow\n");
		return;
	}
	if(*f==-1)
		*f=0;
	*r=(*r+1)%size;
	q[*r]=item;
}
int delete(int q[],int *f,int *r)
{
	int item;
	if(*f==-1)
	{
		printf("queue is empty");
		return -999;
	}
	else
	{
		item=q[*f];
		if(*f==*r)
		{
			*f=-1;
			*r=-1;
		}
		else
			*f=(*f+1)%size;
			return item;
	}
}
void display(int q[],int *r,int *f)
{
	int i;
	if(*f==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		printf("contents of queue\n");
		for(i=*f;i!=*r;(i++)%size)
		{
			printf("%d",q[i]);
		}
	}
}
int main()
{
	int front=0, rear=-1,item;
	int q[size],ch_op,ch_q;
	do
	{
		printf("enter 1 to insert,2 to delete, and3 to display");
		scanf("%d",&ch_op);
		switch(ch_op)
		{
			case 1:printf("enter the element to be inserted");
			scanf("%d",&item);
			void insertion(int item,int *rear,int q[],int*front)	
			case 2:ele=int delete(int q[],int *f,int *r);
				printf("deleted element is %d",ele);
			case 3:void display(int q[],int *r,int *f);
		}
		printf("Do you want to continue(0/1)?\n");
		scanf("%d",&ch_q);
	}while(ch_q!=0)
}
					
				








