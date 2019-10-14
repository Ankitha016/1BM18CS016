#include<stdlib.h>
#include<stdio.h>
struct node
{
	float coeff;
	int pow;
	struct node *next;
};
typedef struct node* NODE;
void display(NODE head);
NODE getnode();
NODE insert_front(NODE head,int po,float c);
void insert_end(NODE head,int po,float c);
void add(NODE head1,NODE head2,NODE head3);
int main()
{
	NODE head1=NULL;
	NODE head2=NULL;
	NODE head3=NULL;
	int n,i,j,m,num;
	float co;
	int power;
	printf("Enter 1 to insert to frst polinomial,2 to insert to second pol,3 to add,5 to display the result\n");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the number of terms\n");
			scanf("%d",&num);
			for(i=0;i<num;i++)	
			{
				printf("Enter the power and coeff of %d term\n",i+1);
				scanf("%d",&power);
				scanf("%f",&co);
				insert_end(head1,power,co);
			}
			break;
		case 2:printf("enter the number of terms\n");
			scanf("%d",&num);
			for(i=0;i<num;i++)	
			{
				printf("Enter the power and coeff of %d term\n",i+1);
				scanf("%d",&power);
				scanf("%f",&co);
				insert_end(head1,power,co);
			}
			break;
		case 3:
			add(head1,head2,head3);
			break;
		case 4:display(head3);
			break;
		case 5:printf("Enter the power and coeff of %d term\n",i+1);
				scanf("%d",&power);
				scanf("%f",&co);
				insert_front(head1,power,co);
				break;
		case 6:printf("Enter the power and coeff of %d term\n",i+1);
				scanf("%d",&power);
				scanf("%f",&co);
				insert_front(head1,power,co);
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
		printf("%fx%d+",p->coeff,p->pow);
		p=p->next;
	}
}

void insert_end(NODE head,int po,float c)
{
	NODE r,q;
	q=getnode();
	q->pow=po;
	q->coeff=c;
	r=head;
	while(r->next!=NULL)
	{
		r=r->next;
	}
	r->next=q;
	q->next=NULL;
}
void add(NODE h1,NODE h2,NODE h3)
{
	h3=getnode();
	while(h1->next&&h2->next)
	{
		if(h1->pow>h2->pow)
		{
			h3->pow=h1->pow;
			h3->coeff=h1->coeff;
			h1=h1->next;
		}
		if(h2->pow>h1->pow)
		{
			h3->pow=h2->pow;
			h3->coeff=h2->coeff;
			h2=h2->next;
		}
		else
		{
			h3->pow=h1->pow;
			h3->pow=h1->pow+h2->pow;
			h1=h1->next;
			h2=h2->next;
		}
		h3->next=getnode();
		h3=h3->next;
		h3->next=NULL;
	}
	while(h1!=NULL||h2!=NULL)
	{
		if(h1->next)
		{
			h3->pow=h1->pow;
			h3->coeff=h1->coeff;
			h1=h1->next;
		}
		if(h2->next)
		{
			h3->pow=h2->pow;
			h3->coeff=h2->coeff;
			h2=h2->next;
		}
		h3->next=getnode();
		h3=h3->next;
		h3->next=NULL;
	}
}
NODE insert_front(NODE head,int po,float c)
{
	NODE p;
	p=getnode();
	p->pow=po;
	p->coeff=c;
	p->next=head;
	head=p;
	return head;
}

