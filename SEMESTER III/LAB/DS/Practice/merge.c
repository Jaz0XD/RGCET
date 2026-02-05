#include<stdio.h>
#include<conio.h>
void mergesort(int,int);
void merge(int,int,int);
int a[10],n;
void main()
{
    int i,low,high,k;
    printf("MERGE SORT");
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    low=1;
    high=n;
    mergesort(low,high);
    printf("\nThe sorted list is:");
    for(k=1;k<=n;k++)
    {
        printf("\n%d",a[k]);
    }
}
void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=((low+high)/2);
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int i,j,h,b[10],k;
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h=h+1;
        }
        else
        {
            b[i]=a[j];
            j=j+1;
        }
        i=i+1;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    printf("\nsorting process order: ");
    for(k=low;k<=high;k++)
    {
        a[k]=b[k];
        printf("%d ",a[k]);
    }
}
