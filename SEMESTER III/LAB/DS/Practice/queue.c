#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int ch, n, queue[50], rear = 0, front = 0, i, item;
    printf("\n Implementation of queue using array");
    do
    {
        printf("\n Main menu");
        printf("\n1.queue max");
        printf("\n2.add");
        printf("\n3.delete");
        printf("\n4.display");
        printf("\n5.queue size");
        printf("\n6.exit");
        printf("\n Enter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\n Enter the queue size");
            scanf("%d", &n);
            break;
        }
        case 2:
        {
            if ((front == n) || (rear > n))
                printf("\n The queue is full");
            else
            {
                printf("\n Enter the element");
                scanf("%d", &item);
                rear = rear + 1;
                queue[rear] = item;
                printf("\n The element is added");
            }
            break;
        }
        case 3:
        {
            if (rear == front)
            {
                printf("\n The queue is empty");
            }
            else
            {
                front = front + 1;
                item = queue[front];
                printf("\n The deleted element is %d", item);
            }
            break;
        }
        case 4:
        {
            if (rear == front)
            printf("The queue is empty");
            else
                printf("\n The queue contains");
            for (i = front + 1; i <= rear; i++)
            {
                printf("\t %d", queue[i]);
            }
            break;
        }
        case 5:
        {
            if (rear == front)
                printf("\n The queue is empty");
            else
                printf("\n The size of queue is %d", (rear - front));
        }
        default:
            exit(1);
        }
    } while (ch < 7);
    getch();
}
