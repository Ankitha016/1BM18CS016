#include<stdlib.h>
struct NODE
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
NODE insert_pos(NODE head,int item,int pos);
void insert_end((NODE head,int item);
int main()
{
	NODE head=NULL;
	int n;
	printf("Enter 1 to inser at the front,2 to insert at a given position,3 to insert at the end,4 to display\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
	 


