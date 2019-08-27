#include<stdio.h>
#include<stdlib.h>
int fact(int n);
int main()
{
	int n,f;
	printf("Enter the number:");
	scanf("%d\n",&n);
	f=fact(n);
	printf("Factorial of %d is=%d\n",n,f);
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;
	else
		return(fact(n-1)*n);
}
	
