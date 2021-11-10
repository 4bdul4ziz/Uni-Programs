#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;
void produce()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nItem '%d' has been produced", x);
    ++mutex;
}
void distribute()
{
    --mutex;
    --full;
    ++empty;
    printf("\nItem '%d' has been distributed", x);
    x--;

    ++mutex;
}
int main()
{
    int n, i;
    printf("\n1.Produce");
    printf("\n2.Distribute");
    printf("\n3.Exit");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                produce();
            }
            else
            {
                printf("Warehouse is full");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                distribute();
            }
            else
            {
                printf("Warehouse is empty");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    } while (n != 3);
}
