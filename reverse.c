#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE reverse(NODE head);
NODE insert_front(int item,NODE head);
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
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
NODE reverse(NODE head)
{
	NODE curr=head,prev=NULL,nextn=NULL;
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	if(head->next==NULL)
	{
		return head;
	}
	while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
	}
	head=prev;
	return head;
}
int main()
{
	NODE head=NULL;
	int ele,n;
	printf("Enter 1 to insert,2 to dispaly,3 to reverse\n");
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
			case 1:printf("enter the element to be inderted\n");
				scanf("%d",&ele);
				head=insert_front(ele,head);
				break;
			case 2:
				display(head);
				break;
			case 3:head=reverse(head);
				printf("reversed list:\n");
				display(head);
				break;
		}
		printf("enter your choice to continue 0 to exit");
		scanf("%d",&n);
	}
}		






