#include<stdio.h>
#include<stdlib.h>
int pop(int s[100],int *t);
int display(int s[100],int t,int small);
void push(int ele,int s[100],int *t);
int s(int s[100],int t);
int main()
{
	int stack[100],top=-1,x,sta[100],top1=-1,n,i,small,item,j,count;
	printf("Enter the num of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the  element\n");
		scanf("%d",&item);
		push(item,stack,&top);
	}
	small=s(stack,top);
	printf("small:%d\n",small);
	count=display(stack,top,small);
	for(j=0;j<count;j++)
	{
		printf("%d\n",small);
	}
	
	return 0;
	
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
int display(int s[100],int t,int small)
{
	int i,count=0;
	if(t==-1)
	{
		printf("Stack is empty\n");
	
	}
	else
	{
		for(i=t;i>=0;i--)
		{
			if(s[i]!=small)
			{
			printf("%d\n",s[i]);
			}
			else
			{
				count++;
			}
		}
	}
	return count;
	
}

int s(int s[100],int t)
{
	int ss=99,i;
	for(i=t;i>=0;i--)
	{
		if(s[i]<ss)
		{
			ss=s[i];
		}
	}
	return ss;
}
