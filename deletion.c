#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE delete_front(NODE head);
NODE getnode();
NODE delete_ele(NODE head,int key);
void delete_end(NODE head);
NODE insert_front(int item,NODE head);
int main()
{
	NODE head=NULL;
	int n,ele,pos,i;
	printf("Enter 1 to insert ele,2 to delete at the front,3 to delete at the end,4 to display,5 to delete the given element\n");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:head=head=insert_front(1,head);
			head=insert_front(2,head);
			head=insert_front(3,head);
			head=insert_front(4,head);
			break;
		case 2:
			head=delete_front(head);
			break;
		case 3:
			delete_end(head);
			break;
		case 4:display(head);
			break;
		case 5:printf("enter the element to be deleted\n");
			scanf("%d",&ele);
			delete_ele(head,ele);
			break;
			
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
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
void delete_end(NODE head)
{
	NODE p,r;
	p=head;
	if(head==NULL)
	{
		printf("list is empty");
		return ;
	}
	while(p->next!=NULL)
	{
		r=p;
		p=p->next;
	}
	printf("deleted ele is %d\n",p->data);
	r->next=NULL;
	free(p);
	
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
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
NODE delete_ele(NODE head,int key)
{
	NODE p=head,prev;
	if(head==NULL)
	{
		printf("list is empy\n");
	}
	while (p!= NULL && p->data != key) 
    { 
	
        prev = p; 
        p = p->next; 
    }
	prev->next = p->next; 
  
    free(p); 
	
}  
	
