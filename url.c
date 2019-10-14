#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char url[10];
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(char item[10],NODE head);
NODE getnode();
NODE insert_pos(NODE head,int pos,int n);
void insert_end(NODE head,char item[10]);
int main()
{
	NODE head=NULL;
	char ele[20];
	int ch,position,i,n,n1;
	printf("Enter 1 to inser at the front,3 to display url,2 to insert at the end,4 to display\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the no.of web pages opened= \n");
				scanf("%d",&n);
				printf("enter the url of the web page=\n");
				for(i=0;i<n;i++)
				{
					n1++;
					scanf("%s",ele);
					head=insert_front(ele,head);
				}
			break;        
		case 2:printf("enter the no.of web pages opened= \n");
				scanf("%d",&n);
				printf("enter the url of the web page=\n");
				for(i=0;i<n;i++)
				{
					n1++;
					scanf("%s",ele);
					insert_end(head,ele);
				}
			break;     
		case 3:printf("enter the position of webpage whic he was looking for=");
			scanf("%d",&position);
			head=insert_pos(head,position,n1);
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 display url ,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
	}
}
NODE insert_front(char item[10],NODE head)
{
	NODE p;
	p=getnode();
	strcpy(p->url,item);
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
void insert_end(NODE head,char item[10])
{
	NODE p,q;
	q=getnode();
	strcpy(q->url,item);
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
}
NODE insert_pos(NODE head,int pos,int n)
{
	NODE curr,prev,q;
	int i;
	int count=1;
	curr=head;
	if(pos>n)
	{
		printf("invalid input\n");
		exit(0);
	}
	if(curr->next==NULL)
	{
		if(count==1)
		{
			printf("url of required webpage=%s\n",curr->url);
			return head;
		}
	
		else
		{
			printf("invalid position\n");
			return head;
		}	
	}

		
		
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		q=curr->next;
		if(count==pos)
		{
			printf(" url of required webpage= %s\n",curr->url);
			return head;
		}
		else
		{
			printf("invalid position");
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
		printf("%s\n",p->url);
		p=p->next;
	}
}
