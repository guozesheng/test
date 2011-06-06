#include <iostream>
using namespace std;

class friendFun_t;

class B
{
public:
    void show(friendFun_t &obj);
};

class friendFun_t 
{
    friend void B :: show(friendFun_t &obj);
    //friend class B;
public:
    friendFun_t (int x, int y);
    void print ();

private:
    //public:
    //protected:
    int x;
    int y;
};

void B :: show(friendFun_t &obj)
{
    cout<<obj.x+obj.y<<endl;
}

int main(int argc, const char *argv[])
{
    friendFun_t a(3, 5);
    B b;

    a.print();

    b.show(a);
    
    return 0;
}

friendFun_t :: friendFun_t (int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
}

void friendFun_t :: print ()
{
    cout<<"x:"<<x<<", y:"<<y<<endl;
}
