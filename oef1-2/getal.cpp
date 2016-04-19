/*
 * getal.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: Matthijs
 *
 * 2. Lees een getal in (bv. 5), en print dan "Mijn lievelingsgetal is 5!" af.
 */

#include <iostream>

using namespace std;

int main() {

	float myLittlePony = 0;

	cout << "Voer uw lievelingsgetal in: ";
	cin >> myLittlePony;
	cout << "Mijn lievelingsgetal is " << myLittlePony << "!\n";

	return 0;
}
