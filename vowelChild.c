#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void vowelFind()
{
    int c = 0, length = 0, count = 0;
    char s[1000];

    printf("\nInput a string\n");
    scanf("%s", &s);

    while (s[c] != '\0')
    {
        if (s[c] == 'a' || s[c] == 'A' || s[c] == 'e' || s[c] == 'E' || s[c] == 'i' || s[c] == 'I' || s[c] == 'o' || s[c] == 'O' || s[c] == 'u' || s[c] == 'U')
            count++;
        c++;
    }
    printf("\nLength of the sting is: %d", c);
    printf("\nNumber of vowels in the string: %d", count);
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
        vowelFind();
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

int main(void)
{
    printf("[dad] pid %d\n", getpid());

    for (int i = 0; i < 4; i++)
        if (fork() == 0)
        {
            printf("[son] pid %d from pid %d\n", getpid(), getppid());
            exit(0);
        }

    for (int i = 0; i < 3; i++)
        wait(NULL);
}