/*
 * oef3-02a.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<char> lol = {'A', 'B', 'C'};

	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			for (int k = 0; k < 3; k++ ) {
				if( i != j && i != k && j != k) {
					cout << lol[i] << lol[j] << lol[k] << endl;
				}
			}
		}
	}


}


