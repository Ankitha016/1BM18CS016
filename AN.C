#include<stdio.h>
#include<conio.h>
void main()
{
 struct stud
 {
	int m1,m2,m3,m4,m5,m6,m7,m8;
 };
 struct stud s1 ;
 printf("enter the marks in maths");
 scanf("%d",&s1.m1);
 printf("enter the marks in ld") ;
 scanf("%d",&s1.m2);
 printf("enter the marks in COA");
 scanf("%d",&s1.m3);
 printf("enter the marks in MP");
 scanf("%d",&s1.m4);
 printf("marks in ds=");
 scanf("%d",&s1.m5);
 printf("marks in java=");
 scanf("%d",&s1.m6);
 printf("marks in project lab=");
 scanf("%d",&s1.m7);
 printf("marks in cipe=");
 scanf("%d",&s1.m8);

 printf("m1=%d\n",s1.m1);
 printf("m2=%d\n",s1.m2);
 printf("m3=%d\n",s1.m3);
 printf("m4=%d\n",s1.m4);
 printf("m5=%d\n",s1.m5);
 printf("m6=%d\n",s1.m6);
 printf("m7=%d\n",s1.m7);
 printf("m8=%d",s1.m8);
 getch();
 }



