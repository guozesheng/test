#include <iostream>
using namespace std;

class animal_t 
{
public:
    animal_t(int weight): weight(weight)
    {
        cout<<"animal_t construct"<<endl;
    }
    ~animal_t()
    {
        cout<<"animal_t deconstruct"<<endl;
    }
    void breath()
    {
        cout<<"It's breathing"<<endl;
    }
    void sleep()
    {
        cout<<"It's sleeping."<<endl;
    }
    void show_info()
    {
        cout<<"weight:"<<weight<<endl;
    }

protected:
    void eat()
    {
        cout<<"It's eating."<<endl;
    }

private:
    int weight;
    void shout()
    {
        cout<<"It's shouting."<<endl;
    }
};

class person_t : public animal_t
{
public:
    person_t(int weight, int tall) : animal_t(weight), tall(tall)
    {
        cout<<"person_t construct"<<endl;
    }
    ~person_t()
    {
        cout<<"person_t deconstruct"<<endl;
    }
    void speak()
    {
        cout<<"I can speak."<<endl;
    }
    void eat()
    {
        animal_t::eat();    // The eat() in the parent class is protected.
    }
    void show_info()
    {
        cout<<"tall:"<<tall<<endl;
        animal_t::show_info();
    }
private:
    int tall;
    int age;
};

int main(int argc, const char *argv[])
{
#if 0
    person_t people(55, 176);

    people.breath();
    people.speak();
    people.eat();
    people.show_info();
#endif

#if 1
    person_t *p = new person_t(55, 176);
    p->show_info();

    int i(10);
    cout<<i<<endl;

    delete p;
#endif

    return 0;
}
