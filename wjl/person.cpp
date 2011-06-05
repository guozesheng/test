#include <iostream>
#include <cstring>
using namespace std;

class Person 
{
public:
    Person ();
    Person (char *name);
    Person (Person &x);
    char *get_name();
    ~Person ();

private:
    char *name;
};

int main(int argc, const char *argv[])
{
    char *p = new char[12];

    strcpy(p, "pycoming");
    Person one(p);
    Person two;
    //Person three(one);

    delete []p;

    cout<<one.get_name()<<endl;

    two = one;
    cout<<two.get_name()<<endl;

    //three = one + two;
    //cout<<three.get_name()<<endl;
    
    //delete []p;
    return 0;
}

Person :: Person()
{
    name = NULL;
}

Person :: Person(char *name)
{
    this->name = new char[strlen(name) + 1];
    //this->name = name;
    strcpy(this->name, name);
}

Person :: Person(Person &x)
{
    this->name = new char[strlen(x.name) + 1];
    strcpy(this->name, x.name);
}

Person :: ~Person()
{
    if (name) 
    {
        delete []name;
        name = NULL;
    }
}

char * Person :: get_name()
{
    return name;
}
