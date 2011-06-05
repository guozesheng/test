#include <iostream>
using namespace std;
class Animal
{
    public:
        const char *saywhat(void) { return "Hehe";}
};
class Cow: public Animal
{
    public:
        virtual const char *saywhat(void) { return "Moo"; }
};
class Dog: public Animal
{
    public:
        virtual const char *saywhat(void) { return "Bark"; }
};
void whosay(const char *who, Animal *a)
{
    cout<<who<<" says '"<<a->saywhat()<<"'"<<endl;
}
int main()
{
    Cow debby;
    Dog puppy;
    whosay("Debby", &debby);
    whosay("Puppy", &puppy);
    cout<<"sizeof(Cow)="<<sizeof(Cow)<<endl;
    return 0;
}

