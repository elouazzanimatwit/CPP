#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t pid, mypid;
    char* arg_list[] = {"date", "+%Y-%m-%d", NULL};

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

        int status_code=execvp("ls", arg_list);

        if(status_code == -1){
            printf("If you see this, then execvp() hasn't terminated properly");
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        printf("Parent process id is %d \n", pid);
        printf("Parent's child has exited with status %d \n", status);


        printf("My child exit code is %d\n", WIFEXITED(status));
    }

    return 0;
}