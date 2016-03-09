/*
 * oef3-06.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

int main() {
	int getal = 0;
	string binair = "";

	cout << "Geef een decimaal getal in? ";
	cin >> getal;

	while ( getal != 0 ) {
		if (getal % 2 == 0) {// Even
			binair = "0" + binair;
		} else {
			binair = "1" + binair;
		}
		getal /= 2;
	}

	cout << binair;

	return 0;
}
