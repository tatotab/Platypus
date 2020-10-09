#include <iostream>
#include <time.h>
#include "Platypus.h"
using namespace std;

Platypus::Platypus() {
    cout << "creating dead Platypus as default" << endl;
    weight = 0.0;
    age = 0;
    name = '-';
    gender = '-';
    alive = 0;
    mutant = 0;
}

Platypus::Platypus(float weight, short age, char name, char gender)
    :weight(weight), age(age), name(name), gender(gender) {
    alive = true;
    mutant = false;
    cout << "Platypus "<<name << " Created" << endl;
}

void Platypus::PrintAttributes(ostream& out) {
    out << "--- Printing Platypus attributes... ---" << endl;
    out<<( (alive) ? "Platypus is alive": "Platypus is not alive" )<< endl;
    out<<( (mutant) ? "It is mutant" : "It is not mutant") << endl;
    out << "Platypus weights: " << weight << " Pounds"
        << "\nAge: " << age
        << "\nName: " << name
        << "\nGender: " << gender << endl;
}

ostream& operator<<(ostream& out, Platypus pl) {
    pl.PrintAttributes(out);
    return out;
}
void Platypus::Age_me() {
    cout << "Platypus is aging" << endl;
    if (alive) {
        age++;
        //2% chance of becoming mutant 
        /// if random out of 1-50 range equals to 1, so 1 out of any 50 (2%) then it becomes mutant
        srand(time(NULL));
        if (50 == (rand() % 50 + 1)) {
            mutant = true;
            cout << "Your Platypus turned into Mutant" << endl;
        }
        else {
            cout << "Platypus did not turn into mutant" << endl;
        }
        //chance of death = weight*10 (%)
        deathChance = 10 * weight;
        if ((rand() % 100) < deathChance) {  
            // generating 100 num and check if this num is in range 0 - deathChance
            alive = false;
            cout << "Unfortunately your Platypus died" << endl;
        }
        else {
            cout << "Platipus is still alive" << endl;
        }
        cout << "Incremented age: " << age << endl;
    }
}

void Platypus::Fight(Platypus &other) {
    cout << "\nPlatypus " << this->name << " and Platypus " << other.name << " are fighting" << endl;
    srand(time(NULL));
    if ((rand() % 100 + 1) < (weight / other.weight) * 50) {
        other.alive = false;
        cout <<other.name << " platypus died\n\n";
    }
    else {
        alive = false;
        cout << this->name<< " platypus died\n\n";
    }
}

void Platypus::Eat() {
    cout << "Platypus is eating" << endl;
    srand(time(NULL));
    weight += weight * (rand() % 50 + 1.0) * 0.001;
    cout << (alive ? "Is alive" : "Platypus Died") << " \nHas Weight: " << weight << " Pounds" << endl;
}

void Platypus::Hatch() {
    alive = true;
    mutant = false;
    age = 0;
    srand(time(NULL));
    (rand() % 2) ? gender = 'm'  :  gender = 'f';
        name = 'A' + (rand() % 26);
    weight = (rand() % 10 + 1.0) / 10.0;
    cout << "Platypus " << name << " hatched" << endl;
}

