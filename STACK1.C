#include<stdio.h>
#include<conio.h>
int stack[100],top=-1;
void push(int ele);
void display();
int pop();
int main()
{
	int e;
	push(1);
	push(2);
	push(3);
	display();
	e=pop();
	printf("Popped element is %d\n",e);
	display();
	return 0;

}
void push(int ele)
{
	if(top==99)
	{
		printf("stack is full");
		return;
	}
	else
		stack[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack is empty");
		return -9999;
	}
	else
		return stack[top--];
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty");
		return;
	}
	else
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
}