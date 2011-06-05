#ifndef MAIN_H
#define MAIN_H

class animal_t 
{
public:
    animal_t(int weight);
    ~animal_t();
    void breath();
    void sleep();
    virtual void show_info();
    /*void show_info();*/

protected:
    void eat();

private:
    int weight;
    void shout();
};

/*class person_t : public animal_t*/
class person_t 
{
public:
    person_t(int weight, int tall);
    ~person_t();
    void speak();
    void eat();
    /*virtual void show_info();*/
    void show_info();
private:
    int tall;
    int age;
};

#endif
