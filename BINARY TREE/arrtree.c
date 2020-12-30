#include<stdio.h>
#include <stdlib.h>
int a[100];
int size=0,sizes=0;
int search(int i,int key)
{
  int x;
  if(a[i]==key)
  {
    return i;
  }
  if(2*i<=sizes)
  {
    x=search(2*i,key);
  }
  else
  {
    x = 0;
  }
  if((x==0)&&(2*i+1<=sizes))
  {
    x=search(2*i+1,key);
  }
  return x;
}
void build_tree(int i)
{
  sizes++;
  char ch;
  if(i!=0)
  {
    size++;
    printf("ENTER THE ELEMENT : ");
    scanf("%d",&a[i]);
    printf("\nIS NODE %d HAS LEFT SUBTREE (y/n): ",a[i]);
    scanf("     %c",&ch);
    if(ch=='y')
    {
      build_tree(2*i);
    }
    else
    {
      build_tree(0);
    }
    printf("\nIS NODE %d HAS RIGHT SUBTREE (y/n): ",a[i]);
    scanf("     %c",&ch);
    if(ch=='y')
    {
      build_tree(2*i+1);
    }
    else
    {
      build_tree(0);
    }
  }
}
void insert()
{
  int key,item;
  char ch;
  printf("ENTER THE PARENT ELEMENT: ");
  scanf("%d",&key);
  int i = search(1,key);
  if(i==0)
  {
    printf("SEARCH UNSUCESSFULL\n");
  }
  else if((a[2*i]==0)||(a[2*i+1]==0))
  {
    printf("ENTER THE ITEM TO INSERT: ");
    scanf("%d",&item);
    printf("WHERE TO INSERT LEFT OR RIGHT (l or r) : ");
    scanf("   %c",&ch);
    if(ch=='l')
    {
      if(a[2*i]==0)
      {
        a[2*i]=item;
      }
      else
      {
        printf("DESIRED INSERTION NOT POSSIBLE\n");
      }
    }
    else if(ch=='r')
    {
      if(a[2*i+1]==0)
      {
        a[2*i+1]=item;
      }
      else
      {
        printf("DESIRED INSERTION NOT POSSIBLE\n");
      }
    }
    size++;
  }
}
void delete()
{
  int key,flag=0;
  printf("ENTER THE ELEMENT TO DELETE : ");
  scanf("%d",&key);
  int i = search(1,key);
  if(i!=0)
  {
    if((a[2*i]==0)&&(a[2*i+1]==0))
    {
      flag=1;
      printf("%d DELETED \n",a[i]);
      a[i]=0;
      size--;
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
void inorder(int i)
{
  if(a[i]!=0)
  {
    inorder(2*i);
    printf("%d ",a[i]);
    inorder(2*i+1);
  }
}
void preorder(int i)
{
  if(a[i]!=0)
  {
    printf("%d ",a[i]);
    preorder(2*i);
    preorder(2*i+1);
  }
}
void postorder(int i)
{
  if(a[i]!=0)
  {
    postorder(2*i);
    postorder(2*i+1);
    printf("%d ",a[i]);
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
              inorder(1);
               break;
      case 2 : printf("PREORDER : ");
                preorder(1);
                break;
      case 3 : printf("POSTORDER : ");
                postorder(1);
                break;
      default : printf("INVALID ENTRY!!");
    }
    printf("\n");
}
void display()
{
  printf("ARRAY REPRESENTATION OF TREE IS : ");
  for(int i=1,j=0;j<size;i++)
  {
    if(a[i]!=0)
    {
      j++;
    }
    printf("%d ,",a[i]);
  }
  printf("\b\b.    \n");
}
void main()
{
  printf("\nBINARY TREE CREATION USING ARRAY\n");
  build_tree(1);
  int ch,key;
  printf("\nMENU\n1.INSERT\n2.DELETE\n3.TRAVERSE\n4.DISPLAY ARRAY\n5.SEARCH ELEMENT\n6.EXIT\n");
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
      case 4 :display();
              break;
      case 5 : printf("ENTER THE ELEMENT TO SEARCH : ");
               scanf("%d",&key);
               int i = search(1,key);
               if(i==0)
               {
                 printf("ITEM NOT FOUND\n");
               }
               else
               {
                 printf("ELEMENT FOUND AT POSITION : %d\n",i);
               }
               break;
      case 6 : printf("EXITING............\n");
                exit(0);
      default:printf("INVAID CASE !!!!\n");
    }
  } while(ch);
}
