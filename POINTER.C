#include<stdio.h>
#include<conio.h>
void swap(int *,int *);
int main()
{
	int a,b;
	printf("enter the values of a and b\n");
	scanf("%d%d",&a,&b);
	printf("The values of a and b before swapping are %d %d",a,b);
	swap(&a,&b);
	printf("the values after swapping are %d %d",a,b);
	return 0;
	getch();
}
void swap(int*x,int*y)
{
	int t=0;
	t=*x;
	*x=*y;
	*y=t;
}