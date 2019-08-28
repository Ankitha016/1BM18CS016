#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int compute(char symbol,int op1,int op2);
void main()
{

	int s[100];
	int op1,op2,result;
	int top=-1,i;
	char postfix[20],symbol;
	printf("enter postfix expression=");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		symbol=postfix[i];
		if(symbol>='0'&&symbol<='9')
		{
			s[++top]=symbol;
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			result=compute(symbol,op1,op2);
			s[++top]=result;
		}
	}
	result=s[top--];
	printf("result=%d\n",result);
}
int compute(char symbol,int op1,int op2)
{
	switch(symbol)
	{
		case '+':return (op1+op2);
			break;
		case '-':return (op1-op2);
			 break;
		case '*':return (op1*op2);
			break;
		case '/':return (op1/op2);
			break;
		case '^':return (op1^op2);
			break;
		default:return 0;
			break;
	}

}
