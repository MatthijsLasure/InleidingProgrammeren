/*
 * Main function for exercise 2-8
 *@Author: Matthijs Lasure
 *@Date: 04/03/2016
 */

#include <iostream>

using namespace std;

int main() {
	// Variabelen
	int input;
	int uren, minuten, seconden;

	// Vraag de input
	cout << "Geef een getal? ";
	cin >> input;

	// Omzetten
	uren = input / 3600;
	minuten = (input - uren * 3600) / 60;
	seconden = input - uren * 3600 - minuten * 60;

	// Printen
	cout << uren << " uren; " << minuten << " minuten; " << seconden << " seconden.";

	return 0;
}
