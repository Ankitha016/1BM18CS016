#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node *NODE;
NODE insert(NODE root,int item);
void printLevelOrder(NODE root);
void display(NODE head);
NODE getnode(int item);
int height(NODE root);
int number(NODE root);
void printLevelOrder(struct node* root);
int minValue(NODE root);
int maxValue(NODE root);
void inorder(NODE root);
unsigned int getLeafCount(NODE root);
void preorder(NODE root);
void postorder(NODE root);
int main()
{
	int ele,n,ch,i,mi,ma,h;
	unsigned int l;
	NODE root=NULL;
	printf("enter 1 to create and insert into tree\n2 to get inorder\n3 to get preorder\n4 to get postorder\n5 to display\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:printf("enter the no of elements to insert\n");
				scanf("%d",&n);
				printf("enter the elements\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&ele);
					root=insert(root,ele);
				}
				break;
			case 2:inorder(root);
				break;	
			case 3:preorder(root);
				break;	
			case 4:postorder(root);
				break;
			case 5:mi=minValue(root);
				printf("minimum=%d",mi);
				break;	
			case 6:ma=maxValue(root);
				printf("minimum=%d",ma);
				break;	
			case 7:h=height(root);
				printf("%d",h);
				break;
			case 8:printLevelOrder(root);
				break;
			case 9:l=getLeafCount(root);
				printf("%d",l);
				break;
			case 10:printf("%d",number(root));
				break;
 
		}
		printf("again enter the choice else 0 to exit\n");
		scanf("%d",&ch);
	}

}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	printf("%d\n",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{

	
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n",root->data);

}
NODE insert(NODE root,int item)
{

	if(root==NULL)
		return getnode(item);
	if(item<root->data)
		root->lchild=insert(root->lchild,item);
	else if(item>=root->data)
		root->rchild=insert(root->rchild,item);
	return root;
}
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data=item;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
int minValue(NODE root)
{ 
  NODE current = root; 
  while (current->lchild != NULL) 
  { 
    current = current->lchild; 
  } 
  return(current->data); 
} 
int maxValue(NODE root)
{ 
  NODE current = root; 
  while (current->rchild != NULL) 
  { 
    current = current->rchild; 
  } 
  return(current->data); 
} 

  
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->lchild, level-1); 
        printGivenLevel(root->rchild, level-1); 
    } 
}
void printLevelOrder(NODE root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
int height(NODE root) 
{ 
    if (root==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lch = height(root->lchild); 
        int rch = height(root->rchild); 
  
        /* use the larger one */
        if (lch > rch) 
            return(lch+1); 
        else return(rch+1); 
    } 
} 
unsigned int getLeafCount(NODE root) 
{ 
  if(root== NULL)        
    return 0; 
  if(root->lchild == NULL && root->rchild==NULL)       
    return 1;             
  else 
    return getLeafCount(root->lchild)+ 
           getLeafCount(root->rchild);       
} 
int number(NODE root)
{
	int co=1;
	if(root==NULL)
		return 0;;
	while(root->lchild != NULL && root->rchild!=NULL)
		{
			co++;
			return number(root->lchild)+number(root->rchild);
		}
	if(co==1)
		return co;
	
	return co+getLeafCount(root) ;
}
