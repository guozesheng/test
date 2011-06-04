#include <iostream>
using namespace std;

//typedef struct point
class POINT
{
private:
    int x;
    int y;

public:
    POINT(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    POINT()
    {
        x = 0;
        y = 0;
    }
    ~POINT()
    {
    }
    void set_x(int m)
    {
        x = m;
    }
    void set_y(int n)
    {
        if (n < 768) 
        {
            y = n;
        }
        else 
        {
            y = 0;
            cout<<"The y > 768"<<endl;
        }
    }
    void show_point()
    {
        //cout<<"pt.x="<<pt.x<<endl<<"pt.y="<<pt.y<<endl;
        //cout<<"pt.x="<<this.x<<endl<<"pt.y="<<this.y<<endl;
        cout<<"x="<<x<<endl<<"y="<<y<<endl;
    }

} ;

int main(int argc, const char *argv[])
{
    POINT pt(5, 9);

    //pt.x = 9;
    //pt.y = 5;

    //cout<<"pt.x="<<pt.x<<endl<<"pt.y="<<pt.y<<endl;
    //pt.set_x(9);
    //pt.set_y(800);
    pt.show_point();
    
    return 0;
}
