#include <iostream>
using namespace std;
template <typename T, typename P>
//T sum (T x, P y)
//{
    //return x + y + z;
//}
class Csum 
{
public:
    Csum ();
    void sum(T x, T y);
    void sum(T x, P y);
    void sum(P x, P y);
    void show(void);

private:
    T ret;
};

int main(int argc, const char *argv[])
{
    Csum<char, double>one;

    one.sum(2, 'a');
    one.show();
    
    return 0;
}

template <typename T, typename P>
Csum<T, P> :: Csum()
{
    ret = 0;
}

template <typename T, typename P>
void Csum<T, P> :: show(void)
{
    cout<<"ret = "<<ret<<endl;
}

template <typename T, typename P>
void Csum<T, P> :: sum(T x, T y)
{
    ret = x + y;
}

template <typename T, typename P>
void Csum<T, P> :: sum(T x, P y)
{
    ret = x + y;
}

template <typename T, typename P>
void Csum<T, P> :: sum(P x, P y)
{
    ret = x + y;
}
