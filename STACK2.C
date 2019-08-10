#include<stdio.h>
#include<conio.h>
int pop(int s[100],int *t);
void display(int s[100],int t);
void push(int ele,int s[100],int *t);
int main()
{
	int stack[100],top=-1,x;
	push(1,stack,&top);
	push(2,stack,&top);
	display(stack,top);
	x=pop(stack,&top);
	printf("Popped element is %d\n",x);
	return 0;
	getch();
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
	getch();
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
