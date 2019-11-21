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
NODE odd(NODE head);
NODE getnode();
NODE rotate(NODE head, int k); 
NODE insert_front(int item,NODE head);
NODE insert_left(NODE head,int item,int value);
NODE delete_pos(NODE head,int value);
int main()
{
	NODE head=NULL;
	int n,m,ele,p,i,value,k;
	int c,j;
	printf("Enter 1 to insert ele to create and insert into linked list\n2 to insert at left\n3 to delete at any specific value\n4 to display=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the number of elements=\n");
			scanf("%d",&m);
			printf("enter the elements=\n");
			for(i=0;i<m;i++)
			{
			
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			}
			break;
		case 2:printf("enter the element to insert\n");
			scanf("%d",&ele);
			printf("enter the value \n");
			scanf("%d",&value);
			head=insert_left(head,ele,value);
			break;
		case 3:printf("enter the value=\n");
	 		scanf("%d",&p);
			head=delete_pos(head,p);
			break;
		case 4:display(head);
			break;
		case 5:head=odd(head);
			break;
		case 6:printf("enter the number of nodes by which list has to be rotated=\n");
			scanf("%d",&k);
			head=rotate(head,k); 
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}

return 0;
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
NODE insert_left(NODE head,int item,int value)
{
	int flag=0;
	NODE curr=head,n=NULL;
	NODE q;
	q=getnode();
	q->data=item;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(curr->data==value)
	{
		
		q->next=head;
		head->prev=q;
		head=q;
		return head;
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			flag=1;
			q->next=curr;
			q->prev=n;
			n->next=q;
			curr->prev=q;
			return head;
			
		}
		n=curr;
		curr=curr->next;
		
	}
	if(flag==0)
	{
		printf("value is not found in list\n");
		return head;
	}

	return 0;
}
NODE odd(NODE head)
{
	int count=1;
	NODE curr=head;
	while(curr!=head)
	{
		count++;
		if(count%2!=0)
		{
			head=delete_pos(head,count );	
		}
		else
		curr=curr->next;
	}
	return head;
}	
NODE delete_pos(NODE head,int pos)
{
	NODE curr,pv=NULL,q,p;
	int count=1;
	if(head==NULL)
	{
		return NULL;	
	}
	if(head->next==NULL)
	{
		if(pos==1)
		
			free(curr);
		return head;
	}
	if(pos==1)
	{
		p=head;
		q=head;
		q=q->next;
		head=q;
		head->prev=NULL;
		free(p);
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			pv=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			if(curr->next==NULL)
			{
				pv->next==NULL;
				free(curr);
			}	
			pv->next=curr->next;
			curr->next->prev=pv;
			printf("deleted ele is %d\n",curr->data);
			free(curr);
			return head;
		}
		else
		{
			printf("invalid position");
			return head;
		}
	}
}
NODE rotate(NODE head, int k) 
{ 
	
     if (k == 0) 
       return head; 
  
  
     NODE current = head; 
  
    // current will either point to kth or NULL after this loop. 
    //  current will point to node 40 in the above example 
    int count = 1; 
    while (count < k && current != NULL) 
    { 
        current = current->next; 
        count++; 
    } 
  
    // If current is NULL, k is greater than or equal to count 
    // of nodes in linked list. Don't change the list in this case 
    if (current == NULL) 
        return head; 
  
    // current points to kth node. Store it in a variable. 
    // kthNode points to node 40 in the above example 
	NODE kth = current; 
  
    // current will point to last node after this loop 
    // current will point to node 60 in the above example 
    while (current->next != NULL) 
        current = current->next; 
  
    // Change next of last node to previous head 
    // Next of 60 is now changed to node 10 
    current->next = head; 
  
    // Change head to (k+1)th node 
    // head is now changed to node 50 
    head = kth->next; 
  
    // change next of kth node to NULL 
    // next of 40 is now NULL 
    kth->next = NULL; 
	return head;
} 
		

