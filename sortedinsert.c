#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE insert_front(int item,NODE head);
NODE insert_pos(NODE head,int item);
int main()
{
	NODE head=NULL;
	int n,ele,p,i,value;
	int c,j;
	printf("Enter 1 to insert ele,2 to insert left,3 to display=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:
			head=insert_front(10,head);
			head=insert_front(7,head);
			head=insert_front(8,head);
			head=insert_front(3,head);
			break;
		case 2:printf("enter the ele\n");
	 		scanf("%d",&ele);
			head=insert_pos(head,ele);
			break;
		case 3:display(head);
			break;
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}

return 0;
}
NODE insert_pos(NODE head,int item)
{
	int flag=0;
	NODE curr=head,n=NULL;
	NODE q,p;
	q=getnode();
	q->data=item;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	if(head==NULL)
	{
		head=q;
		q->prev=NULL;
		q->next=NULL;
		return head;
	}
	if(head->data>item)
	{
		q->next=head;
		q->prev=NULL;
		head=q;
		return head;
	}
	if(item>curr->data)
	{
		curr->next=q;
		q->prev=curr;	
		q->next=NULL;
		return head;
	}
	else
	{
		p=head;
		while(p!=NULL)
		{
			if(p->data>item)
			{
				q->next=p;
				q->prev=p->prev;
				p->prev->next=q;
				p->prev=q;
				return head;
			}
			p=p->next;
		}
	}
}
		

void display(NODE head)
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
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->prev=NULL;
	if(head==NULL)
	{
		p->next=NULL;
		head=p;
		return head;
	}
	else
	{
		p->next=head;
		head->prev=p;
		head=p;
		return head;
	}
}
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("Memory couldnt be allocated");
		exit(0);
	}
	return 0;
}
