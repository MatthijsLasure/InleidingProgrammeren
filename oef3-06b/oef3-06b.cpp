/*
 * oef3-06b.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>
#include <string>

using namespace std;

int main() {

	string binair = "";
	int getal = 0;
	int tmp = 0;
	char binCijfer;

	cout << "Geef een binair getal? ";
	cin >> binair;

	for (int i = binair.size() - 1; i >= 0; i-- ) {
		binCijfer = binair[i];
		if(binair[i] == '1') tmp = 1; else tmp = 0;
		cout << tmp;
		tmp *= 2^(binair.size() - i - 1);
		getal += tmp;
	}
	cout << endl;

	cout << getal;

	return 0;
}
