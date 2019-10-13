#include<stdio.h>
#include<stdlib.h>
int pop(int s[100],int *t);
void display(int s[100],int t);
void push(int ele,int s[100],int *t);
int main()
{
	int stack1[100],top1=-1,x,ch,e;
	int stack2[100],top2=-1;
	int stack3[100],top3=-1;
	printf("enter 1 to enter ele and 2 for exit=\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	
	
	
	switch(ch)
	{
		case 1:printf("enter the element\n");
			scanf("%d",&e);
			push(e,stack1,&top1);
			break;
		case 2:printf("enter the element\n");
			scanf("%d",&e);
			push(e,stack2,&top3);
			break;
		case 3:printf("enter the element\n");
			scanf("%d",&e);
			push(e,stack2,&top3);
			break;
		case 4:display(stack1,top1);
			display(stack2,top2);
			display(stack3,top3);
			break;
		case 5:e=pop(stack1,&top1);
		if(e!=-9999)
		printf("popped ele is %d\n",e);
	}
	printf("enter 1 to enter ele and 2 for exit=\n");
	scanf("%d",&ch);
}

}
void push(int ele,int s[100],int *t)
{
	if(*t==99)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
		*t=*t+1;
		s[*t]=ele;
	}
}
void display(int s[100],int t)
{
	int i;
	if(t==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	else
	{
		for(i=t;i>=0;i--)
			printf("%d\n",s[i]);
	}
	
}
int pop(int s[100],int *t)
{
	int ele;
	if(*t==-1)
	{
		printf("Stack underflow\n");
		return -9999;
	}
	else
	{
		ele=s[*t];
		*t=*t-1;
		return ele;
	}
}
