#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid, mypid;
    char* arg_list[] = {"ls", "-l", NULL};

    mypid = getpid();
    printf("Process ID before fork is %d \n", mypid);
    pid = fork();

    if(pid == -1){
        printf("Fork Failure!");
        exit(pid);
    }

    if(pid == 0){
        mypid = getpid();
        printf("Child process id is %d and Parent process id is %d \n", pid, mypid);
        printf("Any command after this point will not be printed. \n");

        execvp("ls", arg_list);

        printf("If you see this, then execvp() hasn't terminated properly");
    } else {
        wait(NULL);
        printf("Parent process id is %d \n", pid);
    }

    return 0;
}