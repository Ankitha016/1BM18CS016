#include<stdio.h>
#include<conio.h>
int main()
{
	struct stud
	{
		int id,age,marks;
	};
	struct stud s[10];
	int i;
	for(i=0;i<10;i++)
	{
		printf("enter the id,age and marks of student%d\n",i+1);
		scanf("%d%d%d",&s[i].id,&s[i].age,&s[i].marks);
		if(s[i].age>20&&s[i].marks>=0&&s[i].marks<=100)
		{
			if(s[i].marks>=65)
				printf("eligible for admission\n");
			else
				printf("not eligible\n");
		}
		else
		printf("invalid data\n");
		}
		getch();
		return 0;


}