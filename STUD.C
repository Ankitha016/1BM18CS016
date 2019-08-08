#include<stdio.h>
#include<conio.h>
void main()
{
	struct student
	{
		int id,age,marks;
	};
	struct student s;
	printf("Enter the student id,age and marks:\n");
	scanf("%d%d%d",&s.id,&s.age,&s.marks);
	if(s.age>20&&s.marks>=0&&s.marks<=100)
	{
		if(s.marks>=65)
			printf("Eligible for admission");
		else
			printf("Not eligible for admission");
	}
	else
	printf("Invalid data");
	getch();
}