#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node* prev;
  int data;
  struct node* next;
}*p,*temp,*head=NULL,*tail=NULL;
int size()
{
  int i=1;
  temp=head;
  while(temp->next!=NULL)
  {
    i++;
    temp=temp->next;
  }
  return(i);
}
void displayhead()
{
  temp=head;
  if((head==NULL)&&(tail==NULL))
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    printf("LINKED LIST IS : ");
    while(temp!=NULL)
    {
      printf("%d, ",temp->data);
      temp=temp->next;
    }
    printf("\b\b.\n");
  }
}
void displaytail()
{
  temp=tail;
  if((head==NULL)&&(tail==NULL))
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    printf("LINKED LIST IS : ");
    while(temp!=NULL)
    {
      printf("%d, ",temp->data);
      temp=temp->prev;
    }
    printf("\b\b.\n");
  }
}
void insertbeg()
{
  p = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT: ");
  scanf("%d",&(p->data));
  p->next = head;
  if(head==NULL)
  {
    tail=p;
  }
  else
  {
    head->prev=p;
  }
  p->prev=NULL;
  head=p;
}
void delbeg()
{
  if((head==NULL)&&(tail==NULL))
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    p=head;
    printf("DELETED ELEMENT IS : %d\n",p->data);
    if(tail==p)
    {
      head=NULL;
      tail=NULL;
    }
    else
    {
      head=p->next;
      p->next->prev=NULL;
    }
    free(p);
  }
}
void insertend()
{
  p = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT: ");
  scanf("%d",&(p->data));
  p->prev=tail;
  if(head==NULL)
  {
    head=p;
  }
  else
  {
    tail->next=p;
  }
  tail=p;
  p->next=NULL;
}
void delend()
{
  if((head==NULL)&&(tail==NULL))
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    p=tail;
    printf("DELETED ELEMENT IS : %d\n",p->data);
    if(head==p)
    {
      tail=NULL;
      head=NULL;
    }
    else
    {
      tail=p->prev;
      p->prev->next=NULL;
    }
    free(p);
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
  else if(pos>size()+1)
  {
    printf("INVALID ENTRY!!\n");
  }
  else
  {
    int i;
    p = (struct node*)malloc(sizeof(struct node));
    for(i=1,temp=head;i<pos-1;i++)
    {
      temp=temp->next;
    }
      printf("ENTER THE ELEMENT: ");
      scanf("%d",&(p->data));
      p->next=temp->next;
      temp->next->prev=p;
      temp->next=p;
      p->prev=temp;
  }
}
void delpos()
{
  if((head==NULL)&&(tail==NULL))
  {
    printf("LINKED LIST EMPTY\n");
  }
  else
  {
    int pos,i;
    printf("ENTER THE POSITION:");
    scanf("%d",&pos);
    if(pos==1)
    {
      delbeg();
    }
    else if(pos>size())
    {
      printf("INVALID ENTRY!!\n");
    }
    else if(size()==pos)
    {
      delend();
    }
    else
    {
      temp=head;
      for(i=1;i<pos;i++)
      {
        temp=temp->next;
      }
        printf("DELETED ELEMENT IS : %d\n",temp->data);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
  }
}
void main()
{
  int ch;
  printf("\n\tMENU\n1.INSERTION AT START\n2.INSERTION AT END\n3.INSERTION AT A POSITION\n4.DELETION AT START\n5.DELETION AT END\n6.DELETION AT A POSITION\n7.DISPLAY FROM HEAD\n8.DISPLAY FROM TAIL\n9.EXIT\n");
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
        case 7 : displayhead();
                  break;
        case 8 : displaytail();
                  break;
        case 9 : printf("....................BREAKING OUT....................\n");
                  exit(0);
        default:printf("INVALID ENTRY!!!\n");
      }
    } while(ch);
  }
}
