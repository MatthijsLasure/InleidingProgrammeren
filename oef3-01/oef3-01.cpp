/*
 * oef3-01.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

int main() {

	int i = 0;

	for ( i = 0; i < 10; i++ ) {
		cout << i << endl;
	}

	i = 0;

	while( i < 10 ) {
		cout << i << endl;
		i++;
	}

	i = 0;

	do {
		cout << i << endl;
		i++;
	} while ( i < 10 );

}

