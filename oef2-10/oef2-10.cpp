/*
 * Main function for oef2-10
 * @author: Matthijs Lasure
 * @Date: 04/03/2016
 */

#include <iostream>

using namespace std;

int main() {

	// Variabelen
	int getal;

	// Inpout
	cout << "Geef een getal? ";
	cin >> getal;

	// Main loop: 1 regel per loop
	for (int i = 0; i < getal; i++) {
		// Loop voor spaties. Begin: veel spaties, eind: geen spaties
		for (int j = 2 * getal - 2 * i - 2; j > 0; j--) {
			cout << " ";
		}
		// Loop voor getallen: met spatie ertussen
		for (int j = 1; j <= 2*i + 1; j++) {
			cout << j << " ";
		}
		// Volgende lijn
		cout << endl;
	}

	return 0;
}
