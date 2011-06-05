#include <iostream>
#include "main.h"
using namespace std;

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
    person_t *person = new person_t(55, 175);

    cout<<"person:";
    person->show_info();

    animal_t *animal;

    animal = person;
    cout<<endl<<"animal:";
    animal->show_info();

    animal = new animal_t(65);
    cout<<endl<<"animal:";
    animal->show_info();

    animal = person;
    cout<<endl<<"animal:";
    animal->show_info();

    //int i(10);
    //cout<<i<<endl;

    delete person;
#endif

#if 0
    animal_t q;

#endif

    return 0;
}
