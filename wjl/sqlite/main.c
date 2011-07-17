#include <stdio.h>
#include <sqlite3.h>

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    int rc;
    char sql[4096];
    char *errmsg = NULL;

    rc = sqlite3_open("mydb", &db);
    sprintf(sql, "SELECT * FROM mydb");
    rc = sqlite3_exec(db, sql, 0, 0, &errmsg);
    if (rc == SQLITE_OK) 
    {
        printf("Successful!\n");
    }
    
    return 0;
}
