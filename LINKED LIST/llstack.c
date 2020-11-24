#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
}*top=NULL,*temp=NULL;
void push()
{
  struct node *p;
  p = (struct node*)malloc(sizeof(struct node));
  printf("ENTER THE ELEMENT : ");
  scanf("%d",&(p->data));
  p->link=top;
  top=p;
}
void pop()
{
  if(top==NULL)
  {
    printf("STACK : UNDERFLOW");
  }
  else
  {
    temp=top;
    top=top->link;
    printf("DELETED ELEMENT: %d",temp->data);
    free(temp);
  }
  printf("\n");
}
void display()
{
  temp=top;
  printf("STACK : ");
  if(temp==NULL)
  {
    printf("UNDERFLOW");
  }
  else
  {
    while(temp!= NULL)
    {
      printf("%d", temp->data);
      temp = temp->link;
      if(temp!= NULL)
        printf("<-");
    }
  }
  printf("\n");
}
void main()
{
  int ch;
  printf("\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
  do
  {
      printf("\nENTER THE CHOICE : ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: printf("EXITING..........\n");
                exit(0);
        default:printf("INVALID ENTRY");
      }
  } while(ch);
}
