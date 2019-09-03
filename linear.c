#include<stdio.h>
#define size 10
void insert(int item,int *r,int q[],int *f)
{
	if(*r==size-1)
	{
		printf("Queue overflow\n");
		return;
	}
	*r=*r+1;
	q[*r]=item;
}
int delete(int q[],int *f,int *r)
{
	int ele;
	if(*f>*r)
	{
		printf("Queue underfloe\n");
		return -9999;
	}
	ele=q[*f];
	*f=*f+1;
	return ele;
}
void display(int q[],int f,int r)
{
	int i;
	if(f>r)
	{
		printf("queue is empty\n");
		return;
	}
	printf("Contents of the queue are\n");
	for(i=f;i<=r;i++)
	{
		printf("%d\n",q[i]);
	}
}
int main()
{
	int front=0,rear=-1,item;
	int q[size],ch_op,ch_q;
	do{
		printf("Enter 1 to insert,2 to delete,and 3 to display\n");
		scanf("%d",&ch_op);
		switch(ch_op)
		{
			case 1: printf("Enter the element to be inserted\n");
				scanf("%d",&item);
				insert(item,&rear,q,&front);
				break;
			case 2: item=delete(q,&front,&rear);
				printf("the deleted element is:%d\n",item);
				break;
			case 3: display(q,front,rear);
				break;
		}
		printf("Do you want to continue(0/1)?\n");
		scanf("%d",&ch_q);
	}while(ch_q!=0);
}
				
		
			
	
	

