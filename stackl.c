#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
void insert(NODE head,int item);
NODE getnode();
NODE insert_front(int item,NODE head);
NODE delete(NODE head);
int main()
{
	NODE head=NULL;
	int ch,ele,e;
	printf("Enter 1 to push,2 to pop,3 to display,0 to exit=\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the ele to be inserted=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:head=delete(head);
			break;
		case 3:display(head);
		default:break;
	}
	printf("again 1 to push,2 to pop,3 to display,0 to exit=\n");
	scanf("%d",&ch);
	}
}
void insert(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
}
NODE delete(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("stack is empty\n");
		return head;
	}
	printf("deleted ele is=%d\n",p->data);
	head=p->next;
	free(p);
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
	printf("memory could not be allocated");
	exit(0);
	}
}
void display(NODE head)
{
NODE p;
	if(head==NULL)
	{
		printf("stack is empty\n");
		exit(0);
	}
	p=head;
	printf("list is\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}

