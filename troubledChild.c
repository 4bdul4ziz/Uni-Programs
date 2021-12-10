#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void operation(int a, int b)
{
    if (b == 0)
    {
        printf("%d is the sum", (a + b));
    }
    else if (b == 1)
    {
        printf("%d is the difference", (a - b));
    }
    else if (b == 2)
    {
        printf("%d is the product", (a * b));
    }
    else
    {
        printf("%d is the quotient", (a / b));
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (size_t j = 0; j < n; j++)
    {
        printf("[dad] pid %d\n", getpid());

        for (int i = 0; i < 4; i++)
            if (fork() == 0)
            {
                operation(getpid(), i);
                printf("[son] pid %d from pid %d\n", getpid(), getppid());
                exit(0);
                if (i == 4)
                {
                    getppid();
                }
                else
                    (i == 1 || i == 2 || i == 3);
                {
                    getpid();
                }
            }

        for (int i = 0; i < 4; i++)
            wait(NULL);
    }
}