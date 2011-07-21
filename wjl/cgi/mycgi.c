#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int i, n = 0;
    char c;
    char name[50];
    char sex[5];
    char temp[4096];
    char tname[4096];
    char tsex[4096];
    char *p;
    char *pt;
    char *ptemp;

    printf("Content type: text/plain\n\n");

    if (getenv("CONTENT_LENGTH")) 
    {
        n = atoi(getenv("CONTENT_LENGTH"));
    }

    for (i = 0; i < n; i++) 
    {
        c = getchar();
        temp[i] = c;
    }
    temp[i] = '\0';

    if ((p = strtok(temp, "&"))) 
    {
        strcpy(tname, p);
    }
    if ((p = strtok(NULL, "&"))) 
    {
        strcpy(tsex, p);
    }

    if ((p = strtok(tname, "="))) 
    {
        if (strcmp(p, "name")) 
        {
            strcpy(name, strtok(NULL, "="));
        }
        else if (strcmp(p, "sex")) 
        {
            strcpy(sex, strtok(NULL, "="));
        }
    }
    if ((p = strtok(NULL, "="))) 
    {
        if (strcmp(p, "name")) 
        {
            strcpy(name, strtok(NULL, "="));
        }
        else if (strcmp(p, "sex")) 
        {
            strcpy(sex, strtok(NULL, "="));
        }
    }

    printf("%s\n", tname);
    printf("%s\n", tsex);
    putchar('\n');
    fflush(stdout);
    printf("Hello, world!\n");
    return 0;
}

#if 0
int htoi(char *s)
{
    char *digits = "0123456789ABCDEF";
    if (islower(s[0])) 
    {
        s[0] = toupper(s[0]);
    }
    if (islower(s[1])) 
    {
        s[1] = toupper(s[0]);
    }

    return 16 * (strchr(digits, s[0]));
}
#endif
