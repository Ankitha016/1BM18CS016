#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
NODE insert_pos(NODE head,int item,int pos);
void insert_end(NODE head,int item);
int main()
{
	NODE head=NULL;
	int ch,ele,position,value;
	printf("Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display\n");
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
			insert_end(head,ele);
			break;
		case 3:printf("enter the ele and value=\n");
	 		scanf("%d%d",&ele,&value);
			head=insert_pos(head,ele,value);
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
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
void insert_end(NODE head,int item)
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
NODE insert_pos(NODE head,int item,int value)
{
	int flag=0;
	NODE curr=head;
	NODE prev,q,nex;
	q=getnode();
	q->data=item;
	q->next=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(curr->data==value)
	{
		q->next=NULL;
		head->next=q;
		return head;
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			nex=curr->next;
			flag=1;
			curr->next=q;
			q->next=nex;
			return head;
			break;
		}
		
		curr=curr->next;
		
	}
	if(flag==0)
	{
		printf("value is not found in list\n");
		return head;
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
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
