#include <iostream>
using namespace std;
#ifndef PLATYPUS
#define PLATYPUS

class Platypus
{
public: 
    Platypus(); //default constructor
    Platypus(float, short, char, char);//constructor
    void PrintAttributes(ostream&);
    void Age_me();
    void Fight(Platypus&);
    void Eat();
    void Hatch();

private: 
    float weight;
    short age, deathChance = 0;
    char name, gender; 
    bool alive, mutant; 
};

ostream& operator<<(ostream&, Platypus);
#endif