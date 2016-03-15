/*
 * oef4-05.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */


#include <iostream>

using namespace std;

long faculteit(int in) {
	long output = 1;
	for (int i = 1; i <= in; i++) {
		output *= i;
	}
	return output;
}

long variaties(int n, int k) {
	return faculteit(n) / faculteit(n - k);
}

long combinaties(int n, int k) {
	return faculteit(n) / (faculteit(k) * faculteit(n - k));
}

int main() {

	int input;
	cout << "Geef een getal? ";
	cin >> input;
	long outputA = faculteit(input);
	cout << input << "! = " << outputA << endl;

	int n = 0;
	int k = 0;

	cout << "Aantal elementen? ";
	cin >> n;
	cout << "Aantal gekozen elementen? ";
	cin >> k;
	long V = variaties(n, k);
	cout << "Aantal variaties = " << V << endl;

	long C = combinaties(n, k);
	cout << "Aantal combinaties = " << C << endl;

	return 0;
}

