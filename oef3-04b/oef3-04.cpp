/*
 * oef3-04.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

int main() {

	int som = 0;
	int a, b, c;

	cout << "Geef eerste deler in? ";
	cin >> a;
	cout << "Geef tweede deler in? ";
	cin >> b;
	cout << "Geef limiet in? ";
	cin >> c;

	for ( int i = 0; i < c; i++) {
		if( i % a == 0 || i % b == 0 ) {
			som += i;
		}
	}
	cout << "De som is " << som << endl;
}


