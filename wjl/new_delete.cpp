#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    int *arraysize = new int;

    cin>>*arraysize;

    cout<<*arraysize<<endl;

    int *array=new int[*arraysize];

    for(int i=0;i<*arraysize;i++)
    {
        array[i]=i;
    }

    for(int i=0;i<*arraysize;i++)
    {
        cout<<array[i]<<",";
    }
    cout<<endl;

    delete[] array;
    delete arraysize;
    return 0;
}
