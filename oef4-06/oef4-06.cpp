/*
 * oef4-06.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

float CelToFahr(float temp) {
	return 9 * temp / 5 + 32;
}
float FahrToCel(float temp) {
	return 5 * temp / 9 - 18;
}

int main() {

	float inTemp1;
	float inTemp2;

	cout << "Temperatuur in Celcius? ";
	cin >> inTemp1;
	cout << "Dit is " << CelToFahr(inTemp1) << " Fahrenheit." << endl;

	cout << "Temperatuur in Fahrenheit? ";
	cin >> inTemp2;
	cout << "Dit is " << FahrToCel(inTemp2) << " Celcius." << endl;


	return 0;
}


