// Implementation of process management using the following system
// calls of UNIX operating system: fork, exec, getpid, exit, wait, close

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(int arc, char *ar[])
{
    int pid;
    char s[100];
    pid = fork();
    if (pid < 0)
        printf("error");
    else if (pid > 0)
    {
        wait(NULL);
        printf("\n Parent Process:\n");
        printf("\n\tParent Process id:%d\t\n", getpid());
        execlp("cat", "cat", ar[1], (char *)0);
        perror("can't execute cat");
    }
    else
    {
        printf("\nChild process:");
        printf("\n\tChildprocess parent id:\t %d", getppid());
        sprintf(s, "\n\tChild process id :\t%d", getpid());
        write(1, s, strlen(s));
        printf(" ");
        printf(" ");
        printf(" ");
        execvp(ar[2], &ar[2]);
        perror("can't execute");
    }
}


// # Run the program - parent will cat test.txt, child will run ls
// ./1a test.txt ls -la

// # Or try with pwd command
// ./1a test.txt pwd