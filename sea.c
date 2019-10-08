#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
int search(NODE head,int ele);
NODE getnode();
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
int search(NODE head,int ele)
{
	int count=0;
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	else
	if(head->next==NULL)
	{
		if(head->data==ele)
		{
			
			return 1;
		}
		else
		{
			printf("element not found\n");
			
		}
	}
	else
	p=head;
	while(p!=NULL)
	{
		count=++count;
		if(p->data==ele)
		{
				
				
				return count;
	
		}
		
	p=p->next;
	}
	

}
int main()
{
	NODE head=NULL;
	int n,i,ele,item;
	printf("enter 1 to insert,2 to dispaly,3 to search\n");
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
		case 1:printf("enter element to be inserted\n");
			scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:display(head);
			break;
		case 3:printf("enter the element to be searched\n");
			scanf("%d",&ele);
			i=search(head,ele);
			if(i==0)
			{
				printf("element not found\n");
			}
			else	
			printf("element found at%d position\n",i);
		}
	printf("enter your choice to continue else 0 to exit\n");
	scanf("%d",&n);
}
			
}
	
				










