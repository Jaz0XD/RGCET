#include <stdio.h>
#include <conio.h>

void main()
{
    int a[30], x, i, l, h, m, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in the array: ");    
    for (i=0; i<n; i++)
    scanf("%d", &a[i]);
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    l = 0;
    h = n - 1;
    while (l <= h)
    {
        m = (l+h)/2;
        if( x == a[m])
        {
            printf("Search Successful");
            printf("The position of element is: %d", m+1);
            printf("The element is: %d", x);
            break;
        }
        if( x < a[m])
        {
            h= m-1;
            continue;
        }
        if(x > a[m])
        {
            l = m+1;
            continue;
        }
    }
    while ( l> h)
    {
        printf("Search unsuccessful");
        break;
    }
}