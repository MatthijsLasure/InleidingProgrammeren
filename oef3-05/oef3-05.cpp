/*
 * oef3-05.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

int main() {

	string lijn = "ABRACADABRA";

	for ( int i = 0; i < lijn.length(); i++ ) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < lijn.length() - i; j++) {
			cout << lijn[j] << " ";
		}
		cout << endl;
	}
}
