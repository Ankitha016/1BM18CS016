
#include<stdio.h>
#include<conio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void display();
int main()
{
	int e;
	push(1);
	push(2);
	push(3);
	display();
	e=pop();
	if(e!=-9999)
	{
	printf("popped ele is %d\n",e);
	}
	display();
	getch();
	return 0;
}
void push(int ele)
{
	if(top==99)
	{
		printf("stack is overflow\n");
		return;
	}
	stack[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack is underflow\n");
		return -9999;
	}
	return stack[top--];
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("contents of stack is\n");
	for(i=top;i>=0;i--)
	{
	printf("%d\n",stack[i]);
	}
}