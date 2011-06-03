#include <iostream>
using namespace std;

typedef struct point
{
    int x;
    int y;
} POINT;

int main(int argc, const char *argv[])
{
    POINT pt;

    pt.x = 9;
    pt.y = 5;

    cout<<"pt.x="<<pt.x<<endl<<"pt.y="<<pt.y<<endl;
    
    return 0;
}
