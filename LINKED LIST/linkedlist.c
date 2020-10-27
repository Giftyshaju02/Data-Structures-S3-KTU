#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* link;
}*p,*temp,*start;
void display()
{
  temp=start;
  if(start==NULL)
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    printf("LINKED LIST IS : ");
    while(temp!=NULL)
    {
      printf("%d, ",temp->data);
      temp=temp->link;
    }
    printf("\b\b.\n");
  }
}
int size()
{
  int i=1;
  temp=start;
  while(temp->link!=NULL)
  {
    i++;
    temp=temp->link;
  }
  return(i);
}
void insertbeg()
{
  int item;
  p = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT: ");
  scanf("%d",&item);
  if(start == NULL)
  {
    p->data=item;
    p->link=NULL;
    start = p;
  }
  else
  {
    p->data = item;
    p->link = start;
    start = p;
  }
}
void delbeg()
{

  if(start==NULL)
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    p=start;
    start=p->link;
    printf("DELETED ITEM IS : %d\n",p->data);
    free(p);
  }
}
void insertend()
{
  int item;
  p=(struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT: ");
  scanf("%d",&item);
  if(start == NULL)
  {
    p->data=item;
    p->link=NULL;
    start = p;
  }
  else
  {
    temp=start;
    while(temp->link!=NULL)
    {
      temp = temp->link;
    }
    temp->link=p;
    p->data=item;
    p->link=NULL;
  }
}
void delend()
{
  if (start==NULL)
  {
    printf("LINKED LIST EMPTY\n");
  }
  else if(start->link==NULL)
  {
    temp=start;
    printf("DELETED ITEM IS : %d\n",temp->data);
    start=NULL;
    free(temp);
  }
  else
  {
    p=start;
    temp=p->link;
    while(temp->link!=NULL)
    {
      temp=temp->link;
      p=p->link;
    }
    p->link=NULL;
    printf("DELETED ITEM IS : %d\n",temp->data);
    free(temp);
  }
}
void insertpos()
{
  int pos;
  printf("ENTER THE POSITION:");
  scanf("%d",&pos);
  if(pos==1)
  {
    insertbeg();
  }
  else if(pos>size())
  {
    printf("INVALID ENTRY!!!!\n");
  }
  else
  {
    int i;
    temp=start;
    p = (struct node*)malloc(sizeof(struct node));
    printf("ENTER THE ELEMENT: ");
    scanf("%d",&p->data);
    for(i=1;i<(pos-1);i++)
    {
      temp=temp->link;
    }
    p->link=temp->link;
    temp->link=p;
  }
}
void delpos()
{
  int pos;
  if (start==NULL)
  {
    printf("LINKED LIST EMPTY\n");
    return;
  }
  printf("ENTER THE POSITION:");
  scanf("%d",&pos);
  if(pos>size())
  {
      printf("INVALID ENTRY!!!!\n");
  }
  else
  {
    p=start;
    temp=start->link;
    for(int i=1;i<(pos-1);i++)
    {
      p=p->link;
      temp=temp->link;
    }
    printf("DELETED ITEM IS : %d\n",temp->data);
    p->link=temp->link;
    free(temp);
  }
}


void main()
{
  int ch;
  printf("\n\tMENU\n1.INSERTION AT START\n2.INSERTION AT END\n3.INSERTION AT A POSITION\n4.DELETION AT START\n5.DELETION AT END\n6.DELETION AT A POSITION\n7.DISPLAY\n8.EXIT\n");
  {
    do
    {
      printf("\nENTER THE CHOICE: ");
      scanf("%d",&ch);
      switch (ch)
      {
        case 1 : insertbeg();
                  break;
        case 2 : insertend();
                  break;
        case 3 : insertpos();
                  break;
        case 4 : delbeg();
                  break;
        case 5 : delend();
                  break;
        case 6 : delpos();
                  break;
        case 7 : display();
                  break;
        case 8 : printf("....................BREAKING OUT....................\n");
                  exit(0);
        default:printf("INVALID ENTRY!!!\n");
      }
      display();
    } while(ch);
  }
}
