/*
 * oef4_04.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

int power(int a, int b) {
	int result = a;
	for (int i = 1; i < b; i++) {
		result *= a;
	}
	return result;
}

int main() {
	int input1 = 0;
	int input2 = 0;
	cout << "Geef een getal? ";
	cin >> input1;
	cout << "Geef een macht? ";
	cin >> input2;

	int output = power(input1, input2);
	cout << "Power is " << output << endl;
}
