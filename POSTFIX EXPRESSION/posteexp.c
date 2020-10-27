#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
char inexp[100],stack[100],outexp[100],item;
int top=-1,i=0,j=0;
float stack1[100];
void push(char inp)
{
  if(top>=99)
  {
    printf("STACK OVERFLOW!!\n");
  }
  else
  {
    top++;
    stack[top]=inp;
  }
}
void pushev(float item)
{
  if(top>=99)
  {
    printf("STACK OVERFLOW\n");
  }
  else
  {
    top+=1;
    stack1[top]=item;
  }
}
char pop()
{
  char ch;
  if(top<0)
  {
    printf("STACK UNDERFLOW!!\n");
  }
  else
  {
    ch=stack[top];
    top--;
  }
  return ch;
}
float popev()
{
  float item;
  if(top<0)
  printf("STACK OVERFLOW");
  else
  {
    item=stack1[top];
    top-=1;
    return(item);
  }
}
char read_symbol()
{
  char ch=inexp[i];
  i++;
  return(ch);
}
void output(char item)
{
  outexp[j]=item;
  j++;
}
int isp(char ch)
{
  switch(ch)
  {
      case '^':return 3;
               break;
      case '*':return 2;
               break;
      case '/':return 2;
               break;
      case '+':return 1;
               break;
      case '-':return 1;
               break;
      case '(':return 0;
               break;
      default:printf("FOUND INVALID CHARECTER FOR ISP\n");
  }
}
int icp(char ch)
{
  switch(ch)
  {
      case '^':return 4;
               break;
      case '*':return 2;
               break;
      case '/':return 2;
               break;
      case '+':return 1;
               break;
      case '-':return 1;
               break;
      case '(':return 4;
               break;
      default:printf("FOUND INVALID CHARECTER FOR ICP\n");
  }
}
char readsymbol()
{
  char ch;
  ch=outexp[j];
  j++;
  return(ch);
}
void out()
{
    int k;
    printf("\t%c\t",item);
    for(k=0;k<=top;k++)
        printf("%c",stack[k]);
    printf("\t%s\n",outexp);
}
void conv()
{
    char x;
  int len;
  printf("\tINPUT\tSTACK\tOUTPUT\n");
  float value;
  len=strlen(inexp);
  inexp[len]=')';
  push('(');
  out();
  while(top>-1)
  {
    item = read_symbol();
    x = pop();
    if(isalpha(item))
    {
      push(x);
      output(item);
    }
    else if (item == ')')
    {
      while(x!='(')
      {
        output(x);
        x=pop();
      }
    }
    else if(isp(x)>=icp(item))
    {
      while(isp(x)>=icp(item))
      {
        output(x);
        x=pop();
      }
      push(x);
      push(item);
    }
    else if(isp(x)<icp(item))
    {
      push(x);
      push(item);
    }
    else
      printf("INVALID EXPRESSION\n");
    out();
  }
}
void eval()
{
    float X,y,t;
  char op;
  outexp[i]='#';
  j=0;
  item=readsymbol();
  while(item!='#')
  {
    if(isdigit(item))
      pushev(item - '0');
    else
    {
      op=item;
      y=popev();
      X=popev();
      switch(item)
      {
        case '^':t=pow(X,y);
                 break;
        case '*':t=X*y;
                 break;
        case '/':t=X/y;
                 break;
        case '+':t=X+y;
                 break;
        case '-':t=X-y;
                 break;
      }
      pushev(t);
    }
    item=readsymbol();
  }
}
void readvalue()
{
    for(i=0;outexp[i]!='\0';i++)
  {
    if(isalpha(outexp[i]))
    {
      printf("ENTER THE VALUE OF %c: ",outexp[i]);
      scanf(" %c",&outexp[i]);
    }
  }
  eval();
}
void main()
{
    float value;
  printf("ENTER THE INFIX EXPRESSION: ");
  gets(inexp);
  conv();
  printf("POSTFIX EXPRESSION: %s\n",outexp);
  readvalue();
  value = popev();
  printf("THE VALUE OF EXPRESSION IS %f\n",value);
}
