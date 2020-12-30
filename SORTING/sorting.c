#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int n,ctr=1;
void bubble(int arr[])
{
  int a[n];
  memcpy(a, arr, n * sizeof(int));
  printf("\nUNSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
  int temp;
  ctr=1;
  for(int i=0;i<n;i++,ctr++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
    printf("\nAFTER ITERATION %d : ",ctr);
    for(int k=0;k<n;k++)
    {
      printf("%d ",a[k]);
    }
  }
  printf("\n");
  printf("\nSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
}
void selection(int arr[])
{
  int a[n];
  memcpy(a, arr, n * sizeof(int));
  printf("\nUNSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
  int loc,min,temp;
  ctr=1;
  for(int i=0;i<n-1;i++,ctr++)
  {
    loc=i;
    min=a[i];
    for(int j=i+1;j<n;j++)
    {
      if(a[j]<min)
      {
        min=a[j];
        loc=j;
      }
    }
    if(loc!=i)
    {
      temp=a[loc];
      a[loc]=a[i];
      a[i]=temp;
    }
    printf("\nAFTER ITERATION %d : ",ctr);
    for(int k=0;k<n;k++)
    {
      printf("%d ",a[k]);
    }
  }
  printf("\n");
  printf("\nSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
}
void insertion(int arr[])
{
  int a[n];
  memcpy(a, arr, n * sizeof(int));
  printf("\nUNSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
  int j;
  ctr=1;
  for(int i=1;i<n;i++,ctr++)
  {
    int m = a[i];
    for(j=i-1;j>=0;j--)
    {
      if(m<a[j])
      {
        a[j+1]=a[j];
      }
      else
      {
        break;
      }
    }
    a[j+1]=m;
    printf("\nAFTER ITERATION %d : ",ctr);
    for(int k=0;k<n;k++)
    {
      printf("%d ",a[k]);
    }
  }
  printf("\n\nSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
}
void merge_main(int arr[])
{
  int a[n],b[n];
  ctr=1;
  memcpy(a, arr, n * sizeof(int));
  void merge(int low , int mid , int high)
  {
    int k=low, i=low, j=mid+1;
    while((i<=mid)&&(j<=high))
    {
      if(a[i]<=a[j])
      {
        b[k]=a[i];
        i++;
      }
      else
      {
        b[k]=a[j];
        j++;
      }
      k++;
    }
    while(i<=mid)
    {
      b[k]=a[i];
      k++;
      i++;
    }
    while(j<=high)
    {
      b[k]=a[j];
      k++;
      j++;
    }
    for(i=low;i<=high;i++)
    {
      a[i]=b[i];
    }
    printf("\nAFTER ITERATION %d : ",ctr++);
    for(int k=0;k<n;k++)
    {
      printf("%d ",a[k]);
    }
  }
  void mergesort(int low, int high)
  {
    if(low<high)
    {
      int mid = (low+high)/2;
      mergesort(low,mid);
      mergesort(mid+1,high);
      merge(low,mid,high);
    }
  }
  printf("\nUNSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
  mergesort(0,n-1);
  printf("\n");
  printf("\nSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
}
void quick_main(int arr[])
{
  int a[n],ct=1;
  ctr=1;
  memcpy(a, arr, n * sizeof(int));
  void quicksort(int first , int last)
  {
    int i,j,pivot,temp;
    if(first<last)
    {
      pivot=a[first];
      i=first;
      j=last;
      while(i<j)
      {
        while((a[i]<=pivot) && (i<last))
        {
          i++;
        }
        while((a[j]>=pivot) && (j>first))
        {
          j--;
        }
        if(i<j)
        {
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
        }
      }
      temp=a[j];
      a[j]=a[first];
      a[first]=temp;
      printf("\nAFTER ITERATION %d : ",ctr++);
      for(int k=0;k<n;k++)
      {
        printf("%d ",a[k]);
      }
      quicksort(first,j-1);
      quicksort(j+1,last);
    }
  }
  printf("\nUNSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
  quicksort(0,n-1);
  printf("\n");
  printf("\nSORTED ARRAY : ");
  for(int k=0;k<n;k++)
  {
    printf("%d ",a[k]);
  }
  printf("\n");
}
void main()
{
  int ch,a[100];
  printf("\nENTER THE SIZE OF ARRAY : ");
  scanf("%d",&n);
  printf("\nENTER THE ARRAY ELEMENTS : ");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("\nMENU\n1.BUBBLE SORT\n2.SELECTION SORT\n3.INSERTION SORT\n4.MERGE SORT\n5.QUICK SORT\n6.EXIT\n");
  do
  {
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1 :bubble(a);
              break;
      case 2 :selection(a);
              break;
      case 3 :insertion(a);
              break;
      case 4 :merge_main(a);
              break;
      case 5 :quick_main(a);
              break;
      case 6 :printf("EXITING............\n");
              exit(0);
      default:printf("INVAID CASE !!!!\n");
    }
  } while(ch);
}
