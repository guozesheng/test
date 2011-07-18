#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int rscallback_table(void *p, int argc, char **argv, char **argvv);

int i_row = 0;

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    int rc;
    char sql[4096];
    char *errmsg = NULL;
    int empty = 1;
    int flag = 1;

    rc = sqlite3_open("mydb", &db);
    if (rc != SQLITE_OK) 
    {
        perror("sqlite open");
        exit(1);
    }

    while (flag) 
    {
        i_row = 0;
        printf("mydms>");
        fgets(sql, 4096, stdin);
        sqlite3_exec(db, sql, rscallback_table, &empty, &errmsg);
    }

    
    sqlite3_close(db);
    return 0;
}

int rscallback_table(void *p, int argc, char **argv, char **argvv)
{
    int i;
    *(int *)p = 0;

    if (!i_row) 
    {
        for (i = 0; i < argc; i++) 
        {
            printf("%s\t", argvv[i]);
        }
        printf("\n");
    }

    for (i = 0; i < argc; i++) 
    {
        printf("%s\t", argv[i]?argv[i]:"NULL");
    }

    i_row++;
    printf("\n");
    return 0;
}
