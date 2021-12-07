#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void regAdd()
{
    int reg, uwu, sum;
    printf("This is the child speaking, i require your reg. number asap for research purposes: ");
    scanf("%d", &reg);
    printf("Very well, give me a moment.\n");
    while (reg > 0)
    {
        uwu = reg % 10;
        sum = sum + uwu;
        reg = reg / 10;
    }
    printf("Here's the sum of the last four digits of your reg. number = %d", sum);
}

int main()
{
    int status;
    int pid;
    pid = fork();
    if (pid < 0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if (pid == 0)
    {
        regAdd();
        /*make the sum of int prog.*/
        printf("\n Hello I am the child process ");
        printf("\n My pid is %d ", getpid());
        exit(0);
    }
    else
    {
        wait(&status);
        printf("\n Oh no! my child is dead >:( because of the status: %d", status);
        printf("\n Hello I am the parent process ");
        printf("\n My actual pid is %d \n ", getpid());
        exit(1);
    }
}