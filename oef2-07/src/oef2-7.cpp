/*
 * Main function for oef 2-7
 *@Author: Matthijs Lasure
 *@Date: 04/03/2016
 */

#include <iostream>

using namespace std;

int main() {
	// Variabelen aanmaken
	int getal;

	// Vraag de input
	cout << "Geef een getal? ";
	cin >> getal;

	// Check of het getal even is
	if ( getal%2 == 0 ) {
		cout << "Het getal " << getal << " is een even getal." << endl;
	} else {
		cout << "Het getal " << getal << " is een oneven getal." << endl;
	}

	return 0;
}
