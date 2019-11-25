#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
int printMin(NODE head) ;
NODE insert_front(int item,NODE head);
NODE getnode();
NODE insert_end(NODE head,int item);
NODE insert_pos(NODE head,int item,int pos);
NODE insert_left(NODE head,int item,int value);
int printMax(NODE head) ;
NODE exchange(NODE head); 
int main()
{
	NODE head=NULL;
	int ch,ele,position,value,min,max;
	printf("Enter 1 to inser at the front,3 to insert at a given position,4 to insert left,2 to insert at the end,5 to display\n");
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
			head=insert_end(head,ele);
			break;
		case 3:printf("enter the ele and position=\n");
	 		scanf("%d%d",&ele,&position);
			head=insert_pos(head,ele,position);
			break;
		case 4:printf("enter the ele and value=\n");
	 		scanf("%d%d",&ele,&value);
			head=insert_pos(head,ele,value);
			break;
		case 5:display(head);
			break;
		
		case 8:head=exchange(head);
			break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at a given position,4 to insert left,2 to insert at the end,5 to display=\n");
	scanf("%d",&ch);
	}
	
	return 0;
}
NODE insert_front(int item,NODE head)
{
	NODE newn;
	newn=getnode();
	newn->data=item;
	if(head==NULL)
	{
	newn->next=newn;
	head=newn;
	return head;
	}
	newn->next=head->next;
	head->next=newn;
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
NODE insert_end(NODE head,int item)
{
	NODE q;
	q=getnode();
	q->data=item;
	if(head==NULL)
	{
		q->next=q;
		head=q;
		return head;
	}
	q->next=head->next;
	head->next=q;
	head=q;
	return q;

}

void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
		exit(0);
	}
	if(head->next==head)
	{
		printf("%d\n",head->data);
		return;
	}
	printf("contents of list=\n");
	p=head->next;
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=head->next);
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=newn;
	if(head==NULL)
	{
		if(pos==1)
		{
			return newn;
		}
	
		else
		{
			printf("invalid position\n");
			return head;
		}	
	}
	if(pos==1)
	{
	newn->next=head->next;
	head->next=newn;
	return head;
	}
	else
	{
		curr=head->next;
		while(curr!=head&&count!=pos)
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
			printf("invalid position");
			return head;
		}
	}
}
NODE insert_left(NODE head,int item,int value)
{
	int flag=0;
	NODE curr=head->next;
	NODE prev,q;
	q=getnode();
	q->data=item;
	q->next=q;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(curr->data==value)
	{
		q->next=head->next;
		head->next=q;
		return head;
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			flag=1;
			q->next=curr;
			prev->next=q;
			return head;
			break;
		}
		prev=curr;
		curr=curr->next;
		
	}
	if(flag==0)
	{
		printf("value is not found in list\n");
		return head;
	}
}
NODE exchange(NODE head) 
{ 
    if (head == NULL) { 
        return 0; 
    } 
  NODE curr1,curr,p,q;  
    curr = head; 
    int min =1000, max =-1,temp; 
    while (curr->next != head)
 { 
        if (curr->data < min)
 	{ 
            min = curr->data; 
		p=curr;
        } 
	 curr=curr->next;
}
curr=head;
 while (curr->next != head)
 { 
  	 if (curr->data > max)
 	{ 
            max = curr->data; 
		q=curr;
        } 
       curr=curr->next;
  	
    } 
temp=p->data;
	p->data=q->data;
	q->data=temp;
        return head;
  
    
} 

   

