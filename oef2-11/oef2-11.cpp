/*
 * Main function for oef2-11
 * @author: Matthijs Lasure
 * @Date: 05/03/2016
 */

#include <iostream>

using namespace std;

int main() {

	// Variabelen
	int getal;
	bool isPrime = true;
	int i = 5; // Loop var

	// Inpout
	cout << "Geef een getal? ";
	cin >> getal;

	if(getal <= 1) isPrime = false;
	else if(getal <= 3) isPrime = true;
	else if(getal % 2 == 0 || getal % 3 == 0) isPrime = false;
	else {
		while (i*i <= getal) {
			if ( getal % i == 0 || getal % (i + 2) == 0) {
				isPrime = false;
				i = getal;
			}
			i += 6;
		}
	}

	if (isPrime) cout << getal << " is een priemgetal!";
	else cout << getal << " is geen priemgetal!";

	return 0;
}
