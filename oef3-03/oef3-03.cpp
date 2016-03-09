/*
 * oef3-03.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: uauser
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int F = 0;
	vector<int> vorige = {0, 0};

	cout << "Geef een getal in? ";
	cin >> n;

	for ( int i = 0; i <= n; i++ ) {
		if ( i == 0 ) {
			F = 0;
		} else if (i == 1) {
			F = 1;
		} else {
			F = vorige[1] + vorige[2];
		}
		vorige[2] = vorige[1];
		vorige[1] = F;
		cout << F << " ";
	}
}
