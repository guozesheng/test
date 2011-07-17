#include <stdio.h>
#include <sqlite3.h>

int rscallback(void *p, int argc, char **argv, char **argvv);

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    int rc;
    char sql[4096];
    char *errmsg = NULL;
    char **result;
    int nr = 0, nc = 0;
    int i, j;
    int empty = 1;

    rc = sqlite3_open("mydb", &db);
    sprintf(sql, "SELECT * FROM mytable");
    printf("%s\n", sql);

    sqlite3_get_table(db, sql, &result, &nr, &nc, &errmsg);

    for (i = 1; i < nr + 1; i++) 
    {
        for (j = 0; j < nc; j++) 
        {
            printf("%s, ", result[i*nc + j]);
        }
        printf("\n");
    }

    sqlite3_exec(db, sql, rscallback, &empty, &errmsg);
    
    return 0;
}

int rscallback(void *p, int argc, char **argv, char **argvv)
{
    int i;
    *(int *)p = 0;

    for (i = 0; i < argc; i++) 
    {
        printf("%s = %s ", argvv[i], argv[i]?argv[i]:"NULL");
    }

    printf("\n");
    return 0;
}
