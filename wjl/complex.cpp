#include <iostream>
using namespace std;

class Complex 
{
public:
    //Complex ();
    //Complex (double r, double i);
    Complex (double r = 0, double i = 0)
    {
        real = r;
        img = i;
    }
    void print ();
    Complex operator + (Complex &c);
    Complex operator + (double x);

    //friend class B_t;

private:
    double real;
    double img;
};

int main(int argc, const char *argv[])
{
    Complex c1(12, 20), c2(23, 12), c;

    c = c1 + c2;
    c.print();
    c = c1+20;
    c.print();
    
    return 0;
}

//Complex :: Complex ()
//{
    //real = 0;
    //img = 0;
//}

//Complex :: Complex (double r = 0, double i = 0)
//{
    //real = r;
    //img = i;
//}

void Complex :: print()
{
    cout<<"real="<<real<<", img="<<img<<endl;
}

Complex Complex :: operator + (Complex &c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;

    return temp;
}

Complex Complex :: operator + (double x)
{
    Complex temp;
    temp.real = real + x;
    temp.img = img;
    return temp;
}
