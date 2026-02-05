#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int choice, n, a[30], top = 0, i;
    clrscr();
    printf("\n Stack using array");
    do
    {
        printf("\n Main menu");
        printf("\n1.stack max");
        printf("\n2.push");
        printf("\n3.pop");
        printf("\n4.display");
        printf("\n5.size");
        printf("\n6.exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the stack max size:");
            scanf("%d", &n);
            break;
        case 2:
            if (top >= n)
            {
                printf(" The stack is full");
            }
            else
            {
                printf("\n Enter the element:");
                top++;
                scanf("%d", &a[top]);
            }
            break;
        case 3:
            if (top == 0)

            {
                printf("\n The stack is empty");
            }
            else
            {
                printf("\n Poped out element is %d \n", a[top]);
                top--;
            }
            break;
        case 4:
            if (top != 0)
            {
                printf("\n Stack contains \n");
                for (i = 1; i <= top; i++)
                    printf("\t %d", a[i]);
            }
            else
            {
                printf("\n Stack is empty");
            }
            break;
        case 5:
            printf("\n The size of stack is %d", top);
            break;
        default:
            exit(1);
        }
    } while (choice < 6);
    getch();
}
