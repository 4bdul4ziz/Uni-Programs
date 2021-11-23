#include <stdio.h>
#define max 25
int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0, lowest = 10000;
static int bf[max], ff[max];
void FirstFit()
{
    printf("\nFirst Fit");
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("Abdul Aziz A.B - 20BRS1185");
    printf("\nProcess_no\tProcess_size \tMP_no\t   MP_size\tFragment");
    for (i = 1; i <= nf; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    printf("\n\n");
    for (i = 1; i <= nf && ff[i] != 0; i++)
    {
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }
}
void BestFit()
{
    printf("\nBest Fit");
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    printf("\nProcess_no  \tProcess_size  \tMP_no  \t   MP_size  \tFragment");
    for (i = 1; i <= nf && ff[i] != 0; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    printf("\n\n");
    for (i = 1; i <= nf && ff[i] != 0; i++)
    {
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }
}
void WorstFit()
{
    printf("\nWorst Fit");
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1) //if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    if (highest < temp)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
                }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }
    printf("\nProcess_no  \tProcess_size  \tMP_no  \t   MP_size  \tFragment");
    for (i = 1; i <= nf; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    printf("\n\n");
}
void main()
{
    printf("\nEnter the number of Memory Partitions:");
    scanf("%d", &nb);
    printf("Enter the number of Processes:");
    scanf("%d", &nf);
    printf("\nEnter the size of the Memory Partitions:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Memory Partition %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the Processes:-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("Process %d:", i);
        scanf("%d", &f[i]);
    }
    FirstFit();
    BestFit();
    WorstFit();
}
