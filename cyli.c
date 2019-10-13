#include<stdio.h>
#include<stdlib.h>
void display(int s[100],int t);
void push(int ele,int s[100],int *t);
int rem(int st1[100],int st2[100],int st3[100],int n1,int n2,int n3,int sum1,int sum2,int sum3);
int main()
{
	int stack1[100],top1=-1,x,ch,e,n1=0,n2=0,n3=0,sum1=0,sum2=0,sum3=0;
	float d;
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
			n1++;
			sum1+=e;
			push(e,stack1,&top1);
			break;
		case 2:printf("enter the element\n");
			scanf("%d",&e);
			n2++;
			sum2+=e;
			push(e,stack2,&top2);
			break;
		case 3:printf("enter the element\n");
			scanf("%d",&e);
			n3++;
			sum3+=e;
			push(e,stack3,&top3);
			break;
		case 4:display(stack1,top1);
			break;
		case 5 :display(stack2,top2);
			
			break;
		case 6 :display(stack3,top3);
			break;
	
		case 8:d=rem(stack1,stack2,stack3,n1,n2,n3,sum1,sum2,sum3);
				printf("%f",d);
			break;
	}
	printf("enter 1 to enter ele and 2 for exit=\n");
	scanf("%d",&ch);
}
printf("%d\n%d",n1,sum1);
printf("%d\n%d",n2,sum2);
printf("%d\n%d",n3,sum3);
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


int rem(int st1[100],int st2[100],int st3[100],int n1,int n2,int n3,int sum1,int sum2,int sum3)
{
	int top1 =0, top2 = 0, top3 = 0; 
  	int ans = 0; 
  while (1) 
  { 
      
      if (top1 == n1 || top2 == n2 || top3 == n3) 
         return 0; 
  
      
      if (sum1 == sum2 && sum2 == sum3) 
         return sum1; 
      
      if (sum1 >= sum2 && sum1 >= sum3) 
         sum1 -= st1[top1++]; 
      else if (sum2 >= sum3 && sum2 >= sum3) 
         sum2 -= st2[top2++]; 
      else if (sum3 >= sum2 && sum3 >= sum1) 
         sum3 -= st3[top3++] ; 
   } 
} 
