#include<stdio.h>
#include<stdlib.h>
int ctr,count=10;
void printtree(int a[],int i,int space,int n)
{
  if(i>n)
  {
    return;
  }
  space+=count;
  printtree(a,2*i+1,space,n);
  printf("\n");
  for(int i=count;i<space;i++)
  {
    printf(" ");
  }
  printf("%d\n",a[i]);
  printtree(a,2*i,space,n);
}
void swap(int *a,int *b)
{
  int temp;
  temp = *b;
  *b = *a;
  *a = temp;
}
void maxheapify(int a[],int n,int i)
{
  int largest = i;
  int l = (2*i);
  int r = (2*i)+1;
  if(l<=n && a[l]>a[largest])
  {
    largest = l;
  }
  if(r<=n && a[r]>a[largest])
  {
    largest = r;
  }
  if(largest!=i)
  {
    swap(&a[largest],&a[i]);
    printf("\nSTEP %d",ctr++);
    printtree(a,1,0,n);
    maxheapify(a,n,largest);
  }
}
void heapsort(int a[],int n)
{
  printf("\nINSERTION : ");
  ctr=1;
  for(int i=(n/2);i>=1;i--)
  {
    maxheapify(a,n,i);
  }
  printf("\nHEAP TREE : ");
  printtree(a,1,0,n);
  printf("\nDELETION : ");
  ctr=1;
  for(int i=n;i>=1;i--)
  {
    swap(&a[1],&a[i]);
    maxheapify(a,i-1,1);
  }
}
void main()
{
  int a[100],n;
  printf("ENTER THE SIZE OF ARRAY : ");
  scanf("%d",&n);
  printf("ENTER THE ARRAY ELEMENTS : ");
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("\nINSERTED TREE: ");
  printtree(a,1,0,n);
  heapsort(a,n);
  printf("\nSORTED TREE : ");
  for(int i=1;i<=n;i++)
  {
    printf("%d  ",a[i]);
  }
  printf("\n");
}
