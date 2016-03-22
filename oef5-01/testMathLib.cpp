/*
 * testMathLib.cpp
 *
 *  Created on: 22-mrt.-2016
 *      Author: Matthijs
 */

#include <iostream>
#include <iomanip>

#include "myMathLib.h"

using namespace std;

int main() {
	float x;

	cout << "Geef een getal: ";
	cin >> x;

	cout << power(2,-5) << endl;
	cout << fac(6) << endl;

	cout << "De sinus is " << sin(x) << endl;
	cout << "De cosinus is " << cos(x) << endl;
	cout << "De tangens is " << tan(x) << endl;

	cout << "Geef een hoek in radialen: ";
	cin >> x;
	cout << "Dit is " << radToDeg(x) << " graden." << endl;
	cout << "Geef een hoek in graden: " << endl;
	cin >> x;
	cout << "Dit is " << degToRad(x) << " radialen." << endl;

	return 0;
}
