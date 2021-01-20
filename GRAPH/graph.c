#include<stdio.h>
#include <stdlib.h>
int n,vis[20],cnt;
struct vertex
{
  int data;
  struct vertex *link;
}*gptr,*ptr,*u;
struct node
{
  struct vertex *data;
  struct node *link;
}*top=NULL,*front=NULL,*rear=NULL;
void creategraph()
{
  int e,item,flag;
  printf("\nENTER THE NUMBER OF VERTICES : ");
  scanf("%d",&n);
  gptr = (struct vertex* )malloc(sizeof(struct vertex) * n);
  printf("\nENTER THE VALUES OF VERTICES : ");
  for(int i = 0;i<n;i++)
  {
    scanf("%d",&gptr[i].data);
    gptr[i].link = NULL;
  }
  for(int i = 0;i<n;i++)
  {
    printf("\nENTER THE NO. OF CONNECTION FOR %d : ",gptr[i].data);
    scanf("%d",&e);
    ptr = &gptr[i];
    for(int j=0;j<e;j++)
    {
      struct vertex *new = (struct vertex *)malloc(sizeof(struct vertex));
      printf("ENTER THE CONNECTED VERTEX : ");
      scanf("%d",&item);
      for(int k=0;k<n;k++)
      {
        if(item == gptr[k].data && item != gptr[i].data)
        {
          flag=1;
          break;
        }
        else
        {
          flag=0;
        }
      }
      if(flag==1)
      {
        new->data=item;
        new->link = NULL;
        ptr->link = new;
        ptr = ptr->link;
      }
      else
      {
        printf("INVALID ENTRY!!!\n");
        j--;
      }
    }
  }
  printf("\nADJACENCY LIST REPRESENTATION : \n  ");
  for(int i=0;i<n;i++)
  {
    ptr = &gptr[i];
    while (ptr!=NULL)
    {
      printf("%d->",ptr->data);
      ptr=ptr->link;
    }
    printf("\b\b   \n  ");
  }
}
void init()
{
  for(int i=0;i<n;i++)
  {
    vis[i]=0;
  }
  cnt=0;
}
void push(struct vertex *u)
{
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->data = u;
  p->link = top;
  top = p;
}
struct vertex* pop()
{
  if(top==NULL)
  {
    return NULL;
  }
  else
  {
    struct node* p = top;
    struct vertex* u;
    u = p->data;
    top = top->link;
    free(p);
    return(u);
  }
}
int isvisited(struct vertex *u)
{
  for(int i=0;i<cnt;i++)
  {
    if(vis[i]==u->data)
    {
      return 1;
    }
  }
  vis[cnt++]=u->data;
  return 0;
}
struct vertex* search (struct vertex *u)
{
  for(int i=0;i<n;i++)
  {
    if(u->data == gptr[i].data)
    {
      return(&gptr[i]);
    }
  }
}
void dfs()
{
  if(gptr==NULL)
  {
    printf("\nGRAPH IS EMPTY");
  }
  else
  {
    printf("\nDFS : ");
    init();
    push(&gptr[0]);
    while(top!=NULL)
    {
      u = pop();
      if(isvisited(u)==0)
      {
        printf("%d , ",u->data);
        ptr = search(u);
        ptr = ptr->link;
        while(ptr!=NULL)
        {
          push(ptr);
          ptr = ptr->link;
        }
      }
    }
  }
  printf("\b\b  \n");
}
void enq(struct vertex *u)
{
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->data = u;
  p->link = NULL;
  if(front == NULL && rear == NULL)
  {
    front = p;
    rear = p;
  }
  else
  {
    rear->link = p;
    rear = p;
  }
}
struct vertex* deq()
{
  if(front== NULL && rear == NULL)
  {
    return NULL;
  }
  else
  {
    struct node *p = front;
    struct vertex *u = front->data;
    if(front==rear)
    {
      front = NULL;
      rear = NULL;
    }
    else
    {
      front = front->link;
    }
    free(p);
    return(u);
  }
}
void bfs()
{
  if(gptr==NULL)
  {
    printf("\nGRAPH IS EMPTY");
  }
  else
  {
    printf("\nBFS : ");
    init();
    enq(&gptr[0]);
    while(front!=NULL && rear!=NULL)
    {
      u = deq();
      if(isvisited(u)==0)
      {
        printf("%d , ",u->data);
        ptr = search(u);
        ptr = ptr->link;
        while (ptr!=NULL)
        {
          enq(ptr);
          ptr = ptr->link;
        }
      }
    }
  }
  printf("\b\b  \n");
}
void main()
{
  creategraph();
  dfs();
  bfs();
}
