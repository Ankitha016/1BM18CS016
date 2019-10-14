#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct node
{
	char s[100];
	struct node *next;
};
typedef struct node* NODE;
NODE getnode();
void insert_end(NODE head,char item[100]);
NODE insert_f(NODE head,char item[100]);
void display(NODE head);
int main()
{
	char ele[100];
	int ch;
	NODE head;
	printf("enter 1 to insert,2 to display");
	scanf("%d",&ch);
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:printf("enter the frst elemrnt");
				scanf("%s",ele);
				head=insert_f(head,ele);
				break;
			case 2:printf("Enter the element\n");
				scanf("%s",ele);
				insert_end(head,ele);
				
				break;
			case 3:display(head);
				
				break;
		}
		printf("enter 1 to insert,2 to display");
	scanf("%d",&ch);
	}
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
		printf("%s",p->s);
		p=p->next;
	}
}

void insert_end(NODE head,char item[100])
{
	NODE r,q;
	q=getnode();
	strcpy(q->s,item);
	r=head;
	while(r->next!=NULL)
	{
		r=r->next;
	}
	r->next=q;
	q->next=NULL;
}
NODE insert_front(NODE head,char item[10])
{
	NODE p;
	p=getnode();
	strcpy(p->s,item);
	p->next=head;
	head=p;
	return head;
}

