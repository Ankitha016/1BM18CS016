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
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
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
NODE reverse(NODE head)
{
	NODE curr=head,prev =NULL,nextn=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
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
void sort(NODE head)
{
	NODE p=head,q=NULL;
	int temp;
	if(head==NULL)
	{
		return;
	}
	while(p->next!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
}
NODE concatenate(NODE head1,NODE head2)
{
	if(head1==NULL)
	{
		return head2;
	}
	else if(head2==NULL)
	{
		return head1;
	}
	else
	{	
	NODE p=head1;
	while(p->next!=NULL)
	{
		p=p->next;
		
	}
	p->next=head2;
	return head1;
	}
}
int main()
{
	NODE head1=NULL, head2=NULL,head3=NULL;
	int n,ch,ele,p,i,m;
	
	printf("Enter 1 to insert,2 to sort ,3 to  reverse,4 to concatenate,5 to display=");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				
				for(i=0;i<n;i++)
				{
					printf("enter the element to be inserted\n");
					scanf("%d",&ele);
					head1=insert_front(ele,head1);
				}
			break;
		case 2:sort(head1);
			break;
		case 3:head1=reverse(head1);
				break;
		case 4:printf("enter the no.of element to be inserted in second list\n");
				scanf("%d",&m);
				
				for(i=0;i<m;i++)
				{
					printf("enter the elements to be inserted\n");
					scanf("%d",&ele);
					head2=insert_front(ele,head2);
				}
				head3=concatenate(head1,head2);
				display(head3);
			break;
		case 5:display(head1);
			break;

	}
	printf("again enter choice else 0 to exit=\n");
	scanf("%d",&ch);
}
}
