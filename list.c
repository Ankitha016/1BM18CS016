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
NODE insert_pos(NODE head,int item,int pos);
void insert_end(NODE head,int item);
int main()
{
	NODE head=NULL;
	int n,ele,pos;
	printf("Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display\n");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("Enter the element\n");
			scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("Enter the position and element to insert the element\n");
			scanf("%d",&pos);
			scanf("%d",&ele);
			head=insert_pos(head,ele,pos);
			break;
		case 3:printf("Enter the element\n");
			scanf("%d",&ele);
			insert_end(head,ele);
			break;
		case 4:display(head);
			break;
	}
	printf("Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display\n");
	scanf("%d",&n);
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
		return p;
	else
		printf("Memory couldnt be allocated");
		exit(0);
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
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
		{
			return newn;
		}
		else
		{
			printf("Invalid position");
			return head;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
		else
		{
			printf("Invalid position");
			return head;
		}
	}
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
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display

1
Enter the element
34
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
3
Enter the element
56
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
4
Contents of the list
34
56
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
2
Enter the position and element to insert the element
1
44
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
4
Contents of the list
44
34
56
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
2
Enter the position and element to insert the element
4
77
Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display
4
Contents of the list
44
34
56
77

			
		
		
	

		
			
	 


