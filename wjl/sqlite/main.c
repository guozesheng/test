#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

int rscallback(void *p, int argc, char **argv, char **argvv);
int rscallback_table(void *p, int argc, char **argv, char **argvv);

int i_row = 0;

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
    if (rc != SQLITE_OK) 
    {
        perror("sqlite open");
        exit(1);
    }

    sprintf(sql, "SELECT * FROM mytable");

    sqlite3_get_table(db, sql, &result, &nr, &nc, &errmsg);

    for (i = 1; i < nr + 1; i++) 
    {
        for (j = 0; j < nc; j++) 
        {
            printf("%s, ", result[i*nc + j]);
        }
        printf("\n");
    }

    sprintf(sql, "INSERT INTO mytable VALUES(NULL, \"China\", 1)");
    sqlite3_exec(db, sql, 0, 0, &errmsg);

    sprintf(sql, "SELECT * FROM mytable");
    sqlite3_exec(db, sql, rscallback, &empty, &errmsg);

    sprintf(sql, "SELECT * FROM mytable WHERE name = \"XiaoGuo\"");
    sqlite3_exec(db, sql, rscallback, &empty, &errmsg);

    sprintf(sql, "DELETE FROM mytable WHERE name = \"China\"");
    sqlite3_exec(db, sql, 0, 0, &errmsg);

    sprintf(sql, "SELECT * FROM mytable");
    sqlite3_exec(db, sql, rscallback, &empty, &errmsg);

    printf("\n");
    sprintf(sql, "SELECT * FROM mytable");
    i_row = 0;
    sqlite3_exec(db, sql, rscallback_table, &empty, &errmsg);
    
    sqlite3_close(db);
    return 0;
}

int rscallback(void *p, int argc, char **argv, char **argvv)
{/*{{{*/
    int i;
    *(int *)p = 0;

    for (i = 0; i < argc; i++) 
    {
        printf("%s = %s ", argvv[i], argv[i]?argv[i]:"NULL");
    }

    printf("\n");
    return 0;
}/*}}}*/

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
