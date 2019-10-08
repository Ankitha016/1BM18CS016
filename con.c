#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display1(NODE head);
void display2(NODE head1);
NODE getnode();
NODE insert_list1(int item,NODE head);
NODE insert_list2(int item,NODE head1);
NODE concatenate(NODE head,NODE head1);
int main()
{
	NODE head=NULL, head1=NULL,head3=NULL;
	int n,ele,p,i;
	printf("Enter 1 to create list1,2 tocreate list2 ,3 to concatenate,4 to display list1,5 to display list2=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&ele);
					head=insert_list1(ele,head);
				}
			break;
		case 2:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&ele);
					head1=insert_list2(ele,head1);
				}
			break;
		case 3:head3=concatenate(head,head1);
				display2(head3);
				break;
		case 4:display1(head);
			break;
		case 5:display2(head1);
			break;

	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
return 0;
}
void display1(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	printf("contents of list=\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void display2(NODE head1)
{
	NODE q;
	if(head1==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	q=head1;
	printf("contents of list=\n");
	while(q!=NULL)
	{
		printf("%d\n",q->data);
		q=q->next;
	}
}
NODE insert_list1(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
	{
		return p;
	}
	else
	{
		printf("Memory couldnt be allocated");
		exit(0);
	}
	return 0;
}
NODE concatenate(NODE head,NODE head1)
{
	NODE p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		
	}
	p->next=head1;
	return head;
}
NODE insert_list2(int item,NODE head1)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head1;
	head1=p;
	return head1;
}
