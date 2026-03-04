//  Write a programs to simulate UNIX commands like ls, grep, etc

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main(int ag, char *arg[])
{
    char buf[200], line[200];
    int i, j, n, fd1, count = 0, opt;
    if (ag == 4)
    {
        fd1 = open(arg[3], 0);
        if (strcmp(arg[1], "-c") == 0)
            opt = 2;
        if (strcmp(arg[1], "-i") == 0)
            opt = 3;
    }
    else if (ag == 3)
    {
        fd1 = open(arg[2], 0);
        opt = 1;
    }
    if (fd1 == -1)
        printf("error in opening");
    j = 0;
    switch (opt)
    {
    case 1:
        while ((n = read(fd1, buf, sizeof(line))) > 0)
        {
            for (i = 0; i < n; i++, j++)
            {
                if (buf[i] != '\n')
                    line[j] = buf[i];
                else
                {
                    line[j] = '\n';
                    if (strstr(line, arg[1]) != 0)
                        write(1, line, j + 1);
                }
            }
        }
        break;
    case 2:
        while ((n = read(fd1, buf, sizeof(line))) > 0)
        {
            for (i = 0; i < n; i++, j++)
            {
                if (buf[i] != '\n')
                    line[j] = buf[i];
                else
                {
                    line[j] = '\n';
                    if (strstr(line, arg[2]) != 0)
                        count = count + 1;
                    j = -1;
                }
            }
        }
        printf("%d \n", count);
        break;
    case 3:
        while ((n = read(fd1, buf, sizeof(line))) > 0)
        {
            for (i = 0; i < n; i++, j++)
            {
                if (buf[i] != '\n')
                    line[j] = buf[i];
                else
                {
                    line[j] = '\n';
                    if (strcasestr(line, arg[2]) != 0)
                        write(1, line, j + 1);
                    j = -1;
                }
            }
        }
        break;
    }
    close(fd1);
}

// ./1 Hello test.txt               # Find lines with "Hello"
// ./1 -c test test.txt             # Count lines with "test"
// ./1 -i hello test.txt            # Case-insensitive search for "hello"