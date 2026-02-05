#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int product, counter = 0, b, ch, buffer[100], in = 0, out = 0;
void producer();
void consumer();
void main()
{
    printf("\nPRODUCER CONSUMER PROBLEM\n");
    printf("\nEnter the Buffer size...:");
    scanf("%d", &b);
    while (ch != 3)
    {
        printf("\nMenu\n1.Product\n2.Consumer\n3.Exit\n");
        printf("\nEnter your choice..:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("wrong entry");
        }
    }
}
void producer()
{
    while (counter == b)
    {
        printf("\nBuffer Full....");
        return;
    }
    printf("\nEnter Product Id..:");
    scanf("%d", &product);
    buffer[in] = product;
    in = (in + 1) % b;
    counter++;
}
void consumer()
{
    while (counter == 0)
    {
        printf("\nBuffer Empty...");
        return;
    }
    product = buffer[out];
    printf("\nConsumer Consumed %d Product", product);
    out = (out + 1) % b;
    counter--;
}
