#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*front=NULL,*rear=NULL,*temp=NULL;
void insert()
{
  struct node *p;
  p = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT : ");
  scanf("%d",&(p->data));
  p->link=NULL;
  if(front==NULL)
  {
    front=p;
    rear=p;
  }
  else
  {
    rear->link=p;
    rear=p;
  }
}
void del()
{
  if(front==NULL)
  {
    printf("QUEUE : EMPTY");
  }
  else
  {
    temp=front;
    printf("DELETED ELEMENT: %d",temp->data);
    if(front==rear)
    {
      front=NULL;
      rear=NULL;
    }
    else
    {
      front=front->link;
    }
    free(temp);
  }
  printf("\n");
}
void display()
{
  temp=front;
  printf("QUEUE : ");
  if(temp==NULL)
  {
    printf("EMPTY");
  }
  else
  {
    while(temp!= NULL)
    {
      printf("%d", temp->data);
      temp = temp->link;
      if(temp!= NULL)
        printf("->");
    }
  }
  printf("\n");
}
void main()
{
  int ch;
  printf("\n\tMENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
  do
  {
      printf("\nENTER THE CHOICE : ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1: insert();
                break;
        case 2: del();
                break;
        case 3: display();
                break;
        case 4: printf("EXITING..........\n");
                exit(0);
        default:printf("INVALID ENTRY");
      }
  } while(ch);
}
