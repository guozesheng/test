#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int my_ls(const char *path);

int main(int argc, const char *argv[])
{
    char path[] = "./";

    my_ls(path);
    
    return 0;
}

int my_ls(const char *path)
{
    DIR *mydir;
    struct dirent *myreaddir;

    if ((mydir = opendir(path)) == NULL) 
    {
        perror("opendir");
        exit(1);
    }

    while ((myreaddir = readdir(mydir)) != NULL) 
    {
        printf("%s: %c\n", myreaddir->d_name, myreaddir->d_type);
    }
    
    closedir(mydir);
    return 0;
}
