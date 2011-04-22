/*
打印变量的地址
*/

int adda = 1;
int addb = 1;

int add(int a; int b)
{
    int aa = 1;
    int bb = 1;
    static int sta_a = 1;
    printf("<add.c> address static a = 0X%x \n", &sta_a);
    printf("<add.c> static a = %d \n", sta_a);
    printf("<add.c> address aa = 0X%x \n", &aa);
    printf("<add.c> address bb = 0X%x\n", &bb);
    printf("<add.c> address adda = 0X%x\n", &adda);
    printf("<add.c> address addb = 0X%x\n", &addb);

    return a + b;
}
