#include<stdio.h>
void tower_hanoi(int n,char src,char temp,char dest);
void tower_hanoi(int n,char src,char temp,char dest)
{
	if(n==1)
	{
		printf("Move %d disk from %c to %c.\n",n,src,dest);
		return;
	}
	tower_hanoi(n-1,src,dest,temp);
	printf("Move %d from %c to %c\n",n,src,dest);
	tower_hanoi(n-1,temp,src,dest);
}
int main()
{
	int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);
	tower_hanoi(n,'A','B','C');
	return 0;
}
	
