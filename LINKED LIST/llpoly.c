#include<stdio.h>
#include<stdlib.h>
struct poly
{
  int coef;
  int exp;
  struct poly *link;
}*startr=NULL;
struct poly* createpoly()
{
  int n;
  struct poly *start=NULL,*temp=NULL;
  printf("\nENTER THE NUMBER OF ELEMENTS: ");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    struct poly *p;
    p = (struct poly*)malloc(sizeof(struct poly));
    printf("ENTER THE COEFFICIENT :");
    scanf("%d",&(p->coef));
    printf("ENTER THE EXPONENT :");
    scanf("%d",&(p->exp));
    p->link=NULL;
    if(start==NULL)
    {
      start=p;
      temp=p;
    }
    else
    {
      temp->link=p;
      temp=p;
    }
  }
  return(start);
}
void result(int coef,int exp)
{
  struct poly *r,*tempr;
  r = (struct poly*)malloc(sizeof(struct poly));
  r->coef=coef;
  r->exp=exp;
  r->link=NULL;
  if(startr==NULL)
  {
    startr=r;
    tempr=r;
  }
  else
  {
    tempr->link=r;
    tempr=r;
  }
}
struct poly* addpoly(struct poly *a,struct poly *b)
{
  int s;
  struct poly *p,*q;
  p=a,q=b;
  while ((p!=NULL)&&(q!=NULL))
  {
    if(p->exp==q->exp)
    {
      s=p->coef+q->coef;
      result(s,p->exp);
      p=p->link;
      q=q->link;
    }
    else if(p->exp>q->exp)
    {
      result(p->coef,p->exp);
      p=p->link;
    }
    else
    {
      result(q->coef,q->exp);
      q=q->link;
    }
  }
  while(q!=NULL)
  {
    result(q->coef,q->exp);
    q=q->link;
  }
  while(p!=NULL)
  {
    result(p->coef,p->exp);
    p=p->link;
  }
  return(startr);
}
void display(struct poly *node)
{
  while(node!= NULL)
    {
    printf("%dx^%d", node->coef, node->exp);
    node = node->link;
    if(node!= NULL)
        printf(" + ");
    }
}
void main()
{
  struct poly *a,*b,*c;
  printf("\nPOLYNOMIAL 1");
  a=createpoly();
  printf("\nPOLYNOMIAL 2");
  b=createpoly();
  c=addpoly(a,b);
  printf("\nPOLYNOMIAL 1 IS: ");
  display(a);
  printf("\nPOLYNOMIAL 2 IS: ");
  display(b);
  printf("\nSUM IS: ");
  display(c);
  printf("\n");
}
