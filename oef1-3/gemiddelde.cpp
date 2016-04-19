/*
 * gemiddelde.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: Matthijs
 *
 * 3. Lees 5 getallen in, en print het gemiddelde van die getallen af.
 */

#include <iostream>

using namespace std;

int main() {
	float rainbow = 0;
	float rainbowAverage = 0;
	int FucksGiven = 5; // Aantal getallen

	for(int Fucks = 5; Fucks > 0; Fucks--) {
		cout << "Voer een getal in (nog " << Fucks << " over): ";
		cin >> rainbow;
		rainbowAverage += rainbow;
	}

	rainbowAverage = rainbowAverage / FucksGiven;

	cout << "Het gemiddelde is " << rainbowAverage;

	return 0;
}
