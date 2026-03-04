
// Implementation of directory management using the following system
// calls of UNIX operating system: opendir, readdir

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
int main(int c, char *arg[])
{
    DIR *d;
    struct dirent *r;
    int i = 0;
    if (c < 2)
    {
        printf("Usage: %s <directory_path>\n", arg[0]);
        return 1;
    }
    d = opendir(arg[1]);
    if (d == NULL)
    {
        perror("Error opening directory");
        return 1;
    }
    printf("\n\t NAME OF ITEM \n");
    while ((r = readdir(d)) != NULL)
    {
        printf("\t %s \n", r->d_name);
        i = i + 1;
    }
    printf("\n TOTAL NUMBER OF ITEM IN THAT DIRECTORY IS %d \n", i);
    closedir(d);
    return 0;
}


// ./1b /home/shresthashim/Downloads/os