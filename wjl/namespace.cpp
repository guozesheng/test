#include <iostream>
#include <cstring>
using namespace std;
namespace my
{
    char name[20] = "CCU";  // Can you guess why the size is 20?
    void show_name()
    {
        cout<<name<<endl;
    }
}
namespace your
{
    char name[] = "XiaoGuo";
    void show_name()
    {
        cout<<name<<endl;
    }
}

int main(int argc, const char *argv[])
{
    using namespace my;
    //my::show_name();
    show_name();
    strcpy(name, "ZhangSan");
    show_name();
    your::show_name();

    return 0;
}
