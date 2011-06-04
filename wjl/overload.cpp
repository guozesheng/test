#include <iostream>
using namespace std;

int add(int x, int y)
{
    cout<<"int:";
    
    return x + y;
}

double add(double x, double y)
{
    cout<<"double:";

    return x + y;
}

int main(int argc, const char *argv[])
{
    cout<<"add(3, 4) = "<<add(3, 4)<<endl;
    cout<<"add(2.0, 3.0) = "<<add(2.0, 3.0)<<endl;
    
    return 0;
}
