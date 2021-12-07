#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <strhash.h>
#include <struct.h>
#include <syslog.h>

int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int faultCount = 0;
void getData()
{
    printf("\nReference Sequence Length: ");
    scanf("%d", &n);
    printf("\nPage Reference Sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nFrame Nos.: ");
    scanf("%d", &nf);
}
void Begin()
{
    faultCount = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}
int Struck(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }
    return hit;
}
void DisplayPage()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf(" %d", p[k]);
    }
}
void PageFaultCount()
{
    printf("\nNumber of Page Faults Present: %d", faultCount);
}
void fifo()
{
    Begin();
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);
        if (Struck(in[i]) == 0)
        {
            for (k = 0; k < nf - 1; k++)
                p[k] = p[k + 1];
            p[k] = in[i];
            faultCount++;
            DisplayPage();
        }
        else
            printf("No Page Faults are found!");
    }
    PageFaultCount();
}
void lru()
{
    Begin();
    int Lowest[50];
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);
        if (Struck(in[i]) == 0)
        {
            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int Present = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (pg == in[k])
                    {
                        Lowest[j] = k;
                        Present = 1;
                        break;
                    }
                    else
                        Present = 0;
                }
                if (!Present)
                    Lowest[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (Lowest[j] < min)
                {
                    min = Lowest[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            faultCount++;
            DisplayPage();
        }
        else
            printf("No page fault!");
    }
    PageFaultCount();
}
int main()
{
    int choice;
    while (1)
    {
        printf("\nAbdul Aziz A.B - 20BRS1185 - Page Replacement Q2");
        printf("\n1.Enter data: ");
        printf("\n2.FIFO");
        printf("\n3.LRU");
        printf("\n4.Exit");
        printf("\nPreference: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getData();
            break;
        case 2:
            fifo();
            break;
        case 3:
            lru();
            break;
        default:
            return 0;
            break;
        }
    }
}