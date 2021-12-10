#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int isHit(int number)
{
    int nf;
    int p[50];
    int hit = 0;
    for (int j = 0; j < nf; j++)
    {
        if (p[j] == number)
        {
            hit = 1;
            break;
        }
    }
    return hit;
}

void processA(int fildes[2])
{ //this process is generating 12 random numbers in the given range without fractional part
    int i, number;
    close(fildes[0]); // closing the read end of the pipe
    for (i = 0; i < 12; ++i)
    {
        number = rand() % 8 + 1; //here i am generating 12 random numbers in range of 0 to 9
        write(fildes[1], &number, sizeof(number));
    }
    close(fildes[1]); // closing the write end of the pipe
}

void processB(int fildes[2])
{ //now this process has to implement optimal page replacement algo
    int i, number;
    int in[12];
    int nf = 3;       //number of frames for optimal = 3
    close(fildes[1]); // closing the write end of the pipe
                      //reading from the pipe and storing into an array
    for (i = 0; i < 12; ++i)
    {
        in[i] = read(fildes[0], &number, sizeof(number));
        //printf("%d\n", number);
    }
    //now the in[] contains the page sequence
    int pgfaultcnt = 0;
    int p[50];
    //initializing
    for (int i = 0; i < nf; i++)
    {
        p[i] = 9999;
    }

    int near[50];
    for (int i = 0; i < 12; i++)
    {
        printf("\nFor %d :", in[i]);
        if (isHit(in[i]) == 0)
        {
            for (int j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (int k = i; k < 12; k++)
                {
                    if (pg == in[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (int j = 0; j < 12; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            for (int k = 0; k < 3; k++)
            {
                if (p[k] != 9999)
                    printf(" %d", p[k]);
            }
        }
        else
            printf("No page fault");
    }
    printf("\nTotal no of page faults:%d", pgfaultcnt); //displaying total page fault count

    // closing the read end of the pipe
    close(fildes[0]);
}

int main()
{
    // variable declaration
    int fildes[2];
    pid_t pids[2];

    // seeding the pseudo-random
    // number generator
    srand((unsigned int)time(NULL));

    // creating the pipe
    pipe(fildes);

    // creating the child processes
    if ((pids[0] = fork()) == 0)
    {
        // inside process A
        processA(fildes);
        exit(EXIT_SUCCESS);
    }

    if ((pids[1] = fork()) == 0)
    {
        // inside process B
        processB(fildes);
        exit(EXIT_SUCCESS);
    }

    // closing the fds of the pipe
    close(fildes[0]);
    close(fildes[1]);

    // waiting for the child processes to exit
    waitpid(pids[0], NULL, 0);
    waitpid(pids[1], NULL, 0);

    // end of program
    return 0;
}
