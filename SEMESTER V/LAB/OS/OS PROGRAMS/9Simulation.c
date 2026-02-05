#include <stdio.h>
#include <conio.h>
void main()
{
    int phyadr, psi, frame, page, offset, n, pt[20], logadr, i;
    clrscr();
    printf("\nSIMULATION OF PAGING");
    printf("\n\nEnter the Number of Pages...: ");
    scanf("%d", &n);
    printf("\n\nEnter the Page Size..: ");
    scanf("%d", &psi);
    printf("\n\nEnter the Page Table Values...");
    printf("\n\nPage Number\tValue");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t", i);
        scanf("%d", &pt[i]);
    }
    printf("\n\nEnter the Logical Address..: ");
    scanf("%d", &logadr);
    if (logadr > (n * psi) - 1)
        printf("\nInvalid address...");
    else
    {
        offset = logadr % psi;
        page = logadr % psi;
        phyadr = (psi * pt[page] + offset);
        printf("\n\nPhysical Address = (%d * %d) + %d", psi, pt[page], offset);
        printf("\n\nPhysical Address is %d", phyadr);
    }
    getch();
}
