#include<stdio.h>
#include<conio.h>
struct stack
{
	int s[100];
	int top;
};
void push(struct stack *st,int ele);
int pop(struct stack *st);
void display(struct stack st);
int main()
{
	struct stack st;
	int e;
	st.top=-1;
	clrscr();
	push(&st,1);
	push(&st,2);
	display(st);
	e=pop(&st);
	printf("popped element is%d",e);
	display(st);
	getch();
	return 0;
}
void push(struct stack *st,int ele)
{
	if(st->top==99)
	{
		printf("Stack overflow\n");
		return;
	}
	else
	{
			st->top=st->top+1;
			st->s[st->top]=ele;
	}
}
void display(struct stack st)
{
	int i;
      if(st.top==-1)
	{
		printf("empty");
		return;
	}
	for(i=st.top;i>=0;i--)
	{
		printf("%d\n",st.s[i]);
	}
}
int pop(struct stack *st)
{
	int ele;
	if(st->top==-1)
	{
	printf("underflow");
	return -9999;
	}
	ele=st->s[st->top];
	st->top=st->top-1;
	return ele;
}



