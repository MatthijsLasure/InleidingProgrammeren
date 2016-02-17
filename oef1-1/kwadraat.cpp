/*
 * kwadraat.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: Matthijs
 *
 * 1. Lees een getal in, en print het kwadraat van dat getal af.
 */

#include <iostream>

using namespace std;


int main() {
	float uwMoeder = 0;

	cout << "Voer een getal in: ";
	cin >> uwMoeder;
	cout <<"Het kwadraat van " << uwMoeder << " is " << (uwMoeder * uwMoeder);

	return 0;
}
