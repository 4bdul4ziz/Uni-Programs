#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid1, pid2, pid3, pid4, pid5, pid6;
    int i;
    pid1 = fork();
    if(pid1==0){
        pid2 = fork();
        if(pid2==0){
            printf("Child 11 with th ID: %d and parent ID: %d\n",getpid(), getppid());
        }
        else{
            pid3 = fork();
            if(pid3==0){
                printf("Child 12 with ID: %d and parent ID: %d\n", getpid(), getppid());
            }
            else{
                pid4 = fork();
                if(pid4 == 0){
                    printf("Child 13 with ID: %d and parent ID: %d\n",getpid(), getppid());
                }
                else{
                    for(i=0;i<3;i++){
                        wait(NULL);
                    }
                    printf("Child 1 with ID: %d and parent ID: %d\n",getpid(), getppid());
                }
            }
        }
    }
    else{
        pid5 = fork();
        if(pid5 == 0){
            pid6 = fork();
            if(pid6 == 0){
                printf("Child 21 with ID: %d and parent ID: %d\n",getpid(),getppid());
            }
            else{
                wait(NULL);
                printf("Child 2 with ID: %d and parent ID: %d\n",getpid(), getppid());
            }
        }
        else
        {
            for(i=0;i<2;i++){
                wait(NULL);
            }
            printf("Main parent: %d\n",getpid());
        }
    }
    
}
