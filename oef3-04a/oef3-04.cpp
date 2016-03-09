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
	int limit = 1000;

	for ( int i = 0; i < limit; i++) {
		if( i % 3 == 0 || i % 5 == 0 ) {
			som += i;
		}
	}
	cout << "De som is " << som << endl;
}


