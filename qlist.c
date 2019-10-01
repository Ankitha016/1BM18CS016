#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
void insert(NODE head,int item);
NODE delete_front(NODE head);
NODE insert_front(int item,NODE head)
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
		return p;
	else
		printf("Memory couldnt be allocated");
		exit(0);
}
NODE delete_front(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("list is empty");
		return head;
	}
	printf("deleted ele=%d\n",p->data);
	head=p->next;
	free(p);
	return head;
	
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	p=head;
	printf("Contents of the list\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
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
int main()
{
	NODE head=NULL;
	int ch,ele,e;
	printf("Enter 1 to insert first element,2 to insert next element,3 to delete,4 to display,0 to exit=\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			insert(head,ele);
			break;
		case 3:head=delete_front(head);
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to create a list,2 to push,3 to pop,4 to display,0 to exit=\n");
	scanf("%d",&ch);
	}
}
	
