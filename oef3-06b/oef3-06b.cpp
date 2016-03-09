/*
 * oef3-06b.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	string binair = "";
	int getal = 0;
	int tmp = 0;
	int j;
	char binCijfer;

	cout << "Geef een binair getal? ";
	cin >> binair;

	for (int i = 0; i < binair.length(); i++ ) {
		j = binair.size() - i - 1;
		binCijfer = binair[j];
		if(binCijfer == '1') {
			tmp = 1;
		} else {
			tmp = 0;
		}
		tmp = tmp * pow(2, i);
		getal += tmp;
	}
	cout << endl;

	cout << getal;

	return 0;
}
