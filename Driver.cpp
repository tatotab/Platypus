#include "Platypus.h"
#include <iostream>
using namespace std;
int main() {
	Platypus deadPlatipus;
	cout << deadPlatipus << endl;
	
	Platypus pl1(2, 3, 'A', 'M');
	cout << endl;
	Platypus pl2;
	pl2.Hatch();
	pl1.Fight(pl2);

	Platypus pl3(3, 4, 'J', 'M');
	pl3.Eat();
	cout << endl;

	Platypus pl4(2, 3, 'K', 'F');
	pl4.Age_me();

	return 0;
}	