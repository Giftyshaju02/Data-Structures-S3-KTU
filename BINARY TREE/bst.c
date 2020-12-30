#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node* lchild;
  int data;
  struct node* rchild;
}*root=NULL;
void insert()
{
  int item;
  struct node *parent,*ptr;
  struct node *x = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ITEM : ");
  scanf("%d",&item);
  x->data=item;
  x->lchild=NULL;
  x->rchild=NULL;
  if(root==NULL)
  {
    root = x;
    printf("ELEMENT INSERTED AS ROOT NODE\n");
  }
  else
  {
    ptr=root;
    while(ptr!=NULL)
    {
      parent=ptr;
      if(x->data < ptr->data)
      {
        ptr=ptr->lchild;
      }
      else if(x->data > ptr->data)
      {
        ptr=ptr->rchild;
      }
      else
      {
        printf("INVALID ENTRYY!!!\n");
        return;
      }
    }
    if(item<parent->data)
    {
      parent->lchild=x;
      printf("ELEMENT INSERTED AS LEFT CHILD OF %d\n",parent->data);
    }
    else
    {
      parent->rchild=x;
      printf("ELEMENT INSERTED AS RIGHT CHILD OF %d\n",parent->data);
    }
  }
}
struct node* succ(struct node* ptr)
{
  ptr = ptr->rchild;
    while(ptr->lchild!=NULL)
    {
      ptr=ptr->lchild;
    }
  return(ptr);
}
void delete(int item)
{
  struct node *parent,*ptr;
  ptr=root;
  parent=root;
  int flag = 0,ch=0;
  while(ptr!=NULL)
  {
    if(ptr->data==item)
    {
      flag = 1;
      break;
    }
    parent=ptr;
    if(item<ptr->data)
    {
      ptr=ptr->lchild;
    }
    else if(ptr->data<item)
    {
      ptr=ptr->rchild;
    }
  }
  if(flag==0)
  {
    printf("ITEM NOT FOUND!!\n");
    return;
  }
  if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
  {
    ch=1;
  }
  else if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
  {
    ch=3;
  }
  else
  {
    ch=2;
  }
  switch (ch)
  {
    case 1 :{if(ptr==root)
            {
              root=NULL;
            }
            else if(parent->lchild==ptr)
            {
              parent->lchild=NULL;
            }
            else
            {
              parent->rchild=NULL;
            }
            free(ptr);
            break;}
    case 2 :{ if(ptr==root)
            {
              if(ptr->lchild==NULL)
              {
                root=ptr->rchild;
              }
              else
              {
                root=ptr->lchild;
              }
            }
            else if(parent->lchild==ptr)
            {
              if(ptr->lchild==NULL)
              {
                parent->lchild=ptr->rchild;
              }
              else
              {
                parent->lchild=ptr->lchild;
              }
            }
            else if(parent->rchild==ptr)
            {
              if(ptr->lchild==NULL)
              {
                parent->rchild=ptr->rchild;
              }
              else
              {
                parent->rchild=ptr->lchild;
              }
            }
            free(ptr);
            break;}
      case 3 :{ struct node *sp = succ(ptr);
               int sd = sp->data;
               delete(sd);
               ptr->data=sd;
               return;}
    }
  printf("ITEM DELETED\n");
}
void search()
{
  struct node *parent,*ptr;
  int item;
  ptr=root;
  int flag=0;
  printf("ENTER THE ITEM : ");
  scanf("%d",&item);
  while((ptr!=NULL)&&(flag==0))
  {
    if(item<ptr->data)
    {
      ptr=ptr->lchild;
    }
    else if(ptr->data == item)
    {
      flag = 1;
    }
    else
    {
      ptr=ptr->rchild;
    }
  }
  if(flag==1)
  {
    printf("ITEM FOUND \n");
  }
  else
  {
    printf("ITEM NOT FOUND\n");
  }
}
void inorder(struct node* r)
{
  struct node *ptr= r;
  if(ptr!=NULL)
  {
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
  }
}
void preorder(struct node* r)
{
  struct node *ptr= r;
  if(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
  }
}
void postorder(struct node* r)
{
  struct node *ptr= r;
  if(ptr!=NULL)
  {
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
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
void main()
{
  int ch,item;
  printf("\n\n  MENU\n1.INSERTION\n2.DELETION\n3.SEARCHING\n4.TRAVERSAL\n5.EXIT\n");
  do
  {
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : insert();
               break;
      case 2 : if(root==NULL)
                {
                  printf("\nBINARY SEARCH TREE EMPTY");
                }
                else
                {
                  printf("ENTER THE ITEM : ");
                  scanf("%d",&item);
                  delete(item);
                }
               break;
      case 3 : search();
                break;
      case 4 : traverse();
                break;
      case 5 : printf("EXITING............\n");
                exit(0);
      default : printf("INVALID ENTRY!!!\n");
    }
  } while(ch);
}
