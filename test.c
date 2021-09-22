#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/*
Rule 1: no process can print other process's id
Rule 2: no parent process id is printed before its Child
*/

int main()
{
   pid_t pid1, pid2, pid3, pid4, pid5, pid6;

   printf("The parent (of all) process is A : %d", getpid()); //main parent process
   pid1 = fork();

   if (pid1 < 0)
   {
      printf("Fork failed ");
   }

   else if (pid1 == 0)
   { //process B - child 1
      printf("Child 1 with id: %d and its Parent id: %d \n", getpid(), getppid());
      pid2 = fork();
      if (pid2 == 0)
      { //process E child 1.1
         printf("Child 1.1 with id: %d and its Parent id: %d \n", getpid(), getppid());
      }
      else
      {
         pid3 = fork();
         if (pid3 == 0)
         { //process F child 1.2
            printf("Child 1.2 with id: %d and its Parent id: %d \n", getpid(), getppid());
         }
         else
         {
            pid4 = fork();
            if (pid4 == 0)
            { //process G child 1.3
               printf("Child 1.3 with id: %d and its Parent id: %d \n", getpid(), getppid());
            }
         }
      }
   }

   else
   {
      pid5 = fork();
      if (pid5 == 0)
      { //process C child 2
         printf("Child 2 with id: %d and its Parent id: %d \n", getpid(), getppid());
         pid6 = fork();
         if (pid6 == 0)
         { //process D child 2.1
            printf("Child 2.1 with id: %d and its Parent id: %d \n", getpid(), getppid());
         }
      }
   }
   for (int i = 0; i < 3; i++)
   {
      wait(NULL);
   }
   return 0;
}