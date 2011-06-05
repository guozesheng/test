#include <iostream>
using namespace std;

class A 
{
protected:
    void show()
    {
        cout<<"Hello in A"<<endl;
    }
};

class B : public A
{
public:
    void show()
    {
        A :: show();
    }
};

int main(int argc, const char *argv[])
{
    B b;
    b.show();
    
    return 0;
}
