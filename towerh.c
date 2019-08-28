#include<stdio.h>
#include<stdlib.h>
void tower_hanoi(int n,char src,char temp,char dest);
int main()
{
     int n;
     char src,temp,dest;
     printf("enter the number of disks=");
     scanf("%d",&n);
     tower_hanoi(n,'a','b','c');
     return 0;
}
void tower_hanoi(int n,char src,char temp,char dest)
{
	if(n==1)
	{
		printf("move %d disc from %c to %c\n",n,src,dest);
		return;
	}
		tower_hanoi(n-1,src,dest,temp);
		printf("move %d disc from %c to %c \n",n,src,dest);
		tower_hanoi(n-1,temp,src,dest);
}
