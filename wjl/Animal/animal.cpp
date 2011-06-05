#include <iostream>
#include "main.h"
using namespace std;

animal_t :: animal_t(int weight)
    : weight(weight)
{
    cout<<"animal_t construct"<<endl;
}

animal_t :: ~animal_t()
{
    cout<<"animal_t deconstruct"<<endl;
}

void animal_t :: breath()
{
    cout<<"It's breathing"<<endl;
}

void animal_t :: sleep()
{
    cout<<"It's sleeping."<<endl;
}

void animal_t :: show_info()
{
    cout<<"weight:"<<weight<<endl;
}

void animal_t :: eat()
{
    cout<<"It's eating."<<endl;
}

void animal_t :: shout()
{
    cout<<"It's shouting."<<endl;
}

person_t :: person_t(int weight, int tall)
    : animal_t(weight), tall(tall)
{
    cout<<"person_t construct"<<endl;
}

person_t :: ~person_t()
{
    cout<<"person_t deconstruct"<<endl;
}

void person_t :: speak()
{
    cout<<"I can speak."<<endl;
}

void person_t :: eat()
{
    animal_t::eat();     // The eat() in the parent class is protected.
}

void person_t :: show_info()
{
    cout<<"tall:"<<tall<<endl;
    animal_t::show_info();
}

