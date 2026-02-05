#include<stdio.h>
void quick(int a[],int,int);
void split(int a[],int,int);
void main()
{
  int i,n,a[20];
  printf("\n Enter the limit:");
  scanf("%d",&n);
  printf("\n Enter the elements to be sorted\n");
  for(i=0;i<n;i++)
  {
    printf("\n\t a[%d]=",i);
    scanf("%d",&a[i]);
  }
  quick(a,0,n-1);
  printf("\n The sorted elements are:");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
  getch();
}
void quick(int a[],int first,int last)
{
  int x,i,j;
  if(first<last)
  {
    x=a[first];
    i=first;
    j=last;
    while(i<j)
    {
      while(a[i]<=x&&i<last)
      i++;
      while(a[j]>=x&&j>first)
      j--;
      if(i<j)
      split(a,i,j);
    }
    split(a,first,j);
    quick(a,first,j-1);
    quick(a,j+1,last);
  }
}
void split(int a[],int i,int j)
{
  int temp;
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
}


// #include <stdio.h>


// void quick(int a[], int, int);
// void split(int a[], int, int);

// void main()
// {
// int a[20], n, i;
// printf("Enter the number of array: ");
// scanf("%d", &n);
// printf("Enter the list of elements: ");
// for(i=0;i<n;i++)
// {
//     scanf("%d", &a[i]);
// }
// quick(a,0,n-1);
// printf("The sorted list is:");
// for (i=0;i<n;i++)
// printf("%d\t", a[i]);
// }

// void quick(int a[], int first, int last)
// {
//     int i, j, x;
    

//     if (first < last)
//     {
//         x = a[first];
//     i = first;
//     j = last;
//         while(i<j)
//         {
//             while(a[i] <= x && i< last)
//             i++;
//             while(a[j] >= x && j> first)
//             j--;
//             if(i<j)
//             split(a,i,j);
//         }
//         split(a,first,j);
//         quick(a,first, j-1);
//         quick(a,j+1,last);
//     }

// }
// void split(int a[],int i, int j)
// {
//     int temp;
//     temp = a[i];
//     a[i] = a[j];
//     a[j] = temp;
// }