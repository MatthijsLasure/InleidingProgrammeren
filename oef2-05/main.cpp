/*
 * Main function for exercise 2-5
 *@date: 4/03/2016
 *@author: Matthijs Lasure
 */

#include <iostream>

using namespace std;

int main() {

	// Definieer variabelen
	int variabele1, variabele2, variabele3;

	// Vraag de input
	cout << "Geef integer 1? ";
	cin >> variabele1;
	cout << "Geef integer 2? ";
	cin >> variabele2;
	cout << "Geef integer 3? ";
	cin >> variabele3;

	if ( variabele1 < variabele2 && variabele1 < variabele3 ) {
		cout << variabele1 << ", ";
		if (variabele2 < variabele3 ) {
			cout << variabele2 << ", " << variabele3 << endl;
		} else {
			cout << variabele3 << ", " << variabele2 << endl;
		}
	} else if ( variabele2 < variabele1 && variabele2 < variabele3 ) {
		cout << variabele2 << ", ";
		if (variabele1 < variabele3 ) {
			cout << variabele1 << ", " << variabele3 << endl;
		} else {
			cout << variabele3 << ", " << variabele1 << endl;
		}
	} else {
		cout << variabele3 << ", ";
		if (variabele1 < variabele2 ) {
			cout << variabele1 << ", " << variabele2 << endl;
		} else {
			cout << variabele2 << ", " << variabele1 << endl;
		}

	}

	// Print de variabelen


}
