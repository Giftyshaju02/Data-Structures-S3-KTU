#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}*root=NULL;
struct node *search(struct node *r,int key)
{
  struct node *x=NULL;
  if(r->data==key)
  {
    return(r);
  }
  else if(r->lchild!=NULL)
  {
    x=search(r->lchild,key);
  }
  if(x==NULL && r->rchild!=NULL)
  {
    x=search(r->rchild,key);
  }
  return(x);
}
void insert()
{
  int key,item;
  char ch;
  printf("ENTER THE PARENT ELEMENT: ");
  scanf("%d",&key);
  struct node* i = search(root,key);
  struct node* ptr = (struct node*)malloc(sizeof(struct node));
  if(i==NULL)
  {
    printf("SEARCH UNSUCESSFULL\n");
  }
  else if((i->lchild==NULL)||(i->rchild==NULL))
  {
    printf("ENTER THE ITEM TO INSERT: ");
    scanf("%d",&item);
    ptr->data=item;
    ptr->lchild=NULL;
    ptr->rchild=NULL;
    printf("WHERE TO INSERT LEFT OR RIGHT (l or r) : ");
    scanf("   %c",&ch);
    if(ch=='l')
    {
      if(i->lchild==NULL)
      {
        i->lchild=ptr;
      }
      else
      {
        printf("DESIRED INSERTION NOT POSSIBLE\n");
      }
    }
    else if(ch=='r')
    {
      if(i->rchild==NULL)
      {
        i->rchild=ptr;
      }
      else
      {
        printf("DESIRED INSERTION NOT POSSIBLE\n");
      }
    }
  }
}
struct node* parent(struct node* r, struct node* i)
{
  struct node* x=NULL;
  if(r->lchild == i || r->rchild == i)
  {
    return(r);
  }
  else if(r->lchild != NULL)
  {
    x = parent(r->lchild,i);
  }
  if(x==NULL && r->rchild != NULL)
  {
    x=parent(r->rchild,i);
  }
  return(x);
}
void delete()
{
  int key,flag=0;
  printf("ENTER THE ELEMENT TO DELETE : ");
  scanf("%d",&key);
  struct node* i = search(root,key);
  if(i!=NULL)
  {
    if((i->lchild==NULL)&&(i->rchild==NULL))
    {
      flag=1;
      struct node *par = parent(root,i);
      if(par->lchild==i)
      {
        printf("%d DELETED \n",i->data);
        free(i);
        par->lchild=NULL;
      }
      else if(par->rchild==i)
      {
        printf("%d DELETED \n",i->data);
        free(i);
        par->rchild=NULL;
      }
    }
    else
    {
      printf("NODE CAN'T BE DELETED!!\n");
    }
  }
  else if((i==0)||(flag==0))
  {
    printf("NODE DOES NOT EXIST!\n");
  }
}
void inorder(struct node *r)
{
  if(r!=NULL)
  {
    inorder(r->lchild);
    printf("%d ",r->data);
    inorder(r->rchild);
  }
}
void preorder(struct node *r)
{
  if(r!=NULL)
  {
    printf("%d ",r->data);
    preorder(r->lchild);
    preorder(r->rchild);
  }
}
void postorder(struct node *r)
{
  if(r!=NULL)
  {
    postorder(r->lchild);
    postorder(r->rchild);
    printf("%d ",r->data);
  }
}
void traverse()
{
  int ch;
  printf("\n  MENU\n1.INORDER\n2.PREORDER\n3.POSTORDER\nENTER YOUR CHOICE: ");
  scanf("%d",&ch);
    switch (ch)
    {
      case 1 : printf("INORDER : ");
              inorder(root);
               break;
      case 2 : printf("PREORDER : ");
                preorder(root);
                break;
      case 3 : printf("POSTORDER : ");
                postorder(root);
                break;
      default : printf("INVALID ENTRY!!");
    }
    printf("\n");
}
void build_tree(struct node *r)
{
  char ch;
  int item;
  printf("\nIS NODE %d HAS LEFT SUBTREE (y/n): ",r->data);
  scanf("     %c",&ch);
  if(ch=='y')
  {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE ELEMENT: ");
    scanf("%d",&item);
    n->data=item;
    n->lchild=NULL;
    n->rchild=NULL;
    r->lchild=n;
    build_tree(n);
  }
  printf("\nIS NODE %d HAS RIGHT SUBTREE (y/n): ",r->data);
  scanf("     %c",&ch);
  if(ch=='y')
  {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE ELEMENT: ");
    scanf("%d",&item);
    n->data=item;
    n->lchild=NULL;
    n->rchild=NULL;
    r->rchild=n;
    build_tree(n);
  }
}
void main()
{
  int ch,n,key;
  printf("\nBINARY TREE CREATION USING LINKED LIST");
  printf("\nENTER THE ROOT ELEMENT: ");
  scanf("%d",&n );
  struct node *x= (struct node*)malloc(sizeof(struct node));
  x->data=n;
  x->lchild=NULL;
  x->rchild=NULL;
  root=x;
  build_tree(root);
  printf("\nMENU\n1.INSERT\n2.DELETE\n3.TRAVERSE\n4.SEARCH ELEMENT\n5.EXIT\n");
  do
  {
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1 :insert();
              break;
      case 2 :delete();
              break;
      case 3 :traverse();
              break;
      case 4 : printf("ENTER THE ELEMENT TO SEARCH : ");
               scanf("%d",&key);
               if(search(root,key) == NULL)
               {
                 printf("ITEM NOT FOUND\n");
               }
               else
               {
                 printf("ELEMENT FOUND \n");
               }
               break;
      case 5 : printf("EXITING............\n");
                exit(0);
      default:printf("INVAID CASE !!!!\n");
    }
  } while(ch);
}
