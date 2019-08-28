#include<stdio.h>
int fib(int n);
int main()
{
	int f,n;
	printf("enter n=");
	scanf("%d",&n);
	f=fib(n);
	printf("%d\n",f);
	return 0;
}
int fib(int n)
{
	if(n==1)
		return 0;
	else if (n==2)
		return 1;
	else if(n>2)
		return(fib(n-1)+fib(n-2));
}


