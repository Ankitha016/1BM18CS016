#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
void delete_ele_repeated(NODE head) ;
NODE delete_front(NODE head);
NODE getnode();
NODE delete_ele(NODE head,int ele);
void delete_end(NODE head);
NODE insert_front(int item,NODE head);
int check_list(int ele,NODE head);
int flag=0;
int main()
{
	NODE head=NULL;
	int n,ele,pos,i;
	int c;
	printf("Enter 1 to insert ele,2 to display,3 to delete the repeated element=\n");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 3:
			delete_ele_repeated(head);
			break;
		case 2:display(head);
			break;
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
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
void delete_ele_repeated(NODE head) 
{
	NODE curr=head,nextn;
	int che,j;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	
	}
	while(curr->next!=NULL)
	{
	if(curr->data==curr->next->data)
	{
		nextn=curr->next->next;
		free(curr->next);
		curr->next=nextn;
	}
	else
	{
		curr=curr->next	;
	}
	}	
	
}
NODE delete_ele(NODE head, int ele) 
{
	NODE curr=head,prev=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	
	if(head->next==NULL)
	{
		if(head->data==ele)
		{
			free(head);
			return NULL;
		}
		else
		{
			printf("value not found\n");
			return head;
		}
	}
	while(curr!=NULL)
	{
		if(curr->data==ele)
		{
			if(prev==NULL)
			{
				head=curr->next;
				free(curr);
			}
			else
			{
				prev->next=curr->next;
				free(curr);
			}
			return head;
		}
		prev =curr;
		curr=curr->next;
	}
	
	
}	
int check_list(int ele,NODE head)
{
	int count;
	NODE cu=head;
	while(cu!=NULL)
	{
		if(cu->data==ele)
		{
			count++;
		}
		cu=cu->next;
	}
	return count;
}
