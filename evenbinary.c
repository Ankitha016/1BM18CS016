#include<stdio.h>


int iseven(int n)
{
	int c=0;
	while(n)
	{
		c+=n&1;
		n>>=1;
	}
	if(c%2==0)
		return 1;
	else
		return 0;
}

int sumDigits(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n=n/10;
	}
	return s;
}

int main()
{
	int n;
	int sum=0;
	printf("Enter the size of the array=");
	scanf("%d",&n);
	printf("Enter the array elements");
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(iseven(a[i]))
			sum=sum+sumDigits(a[i]);
	}
	printf("required sum = %d",sum);
	return 0;
}
	
