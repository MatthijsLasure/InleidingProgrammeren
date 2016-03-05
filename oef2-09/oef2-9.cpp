/*
 * Main function for exercise 2-9
 * @author: Matthijs Lasure
 * @date: 04/03/2016
 */

#include <iostream>

using namespace std;

int main () {
	// Variabelen
	int x, y;

	// Inlezene
	cout << "Geef een hoogte? ";
	cin >> x;
	cout << "Geef eeen breedte? ";
	cin >> y;

	// Volle rechthoek
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << "*";
		}
		cout << endl;
	}

	// Witregel
	cout << endl;

	// Lege rechthoek
	for (int j = 0; j < y; j++) {
		cout << "*";
	}
	cout << endl;

	for (int i = 0; i < x - 2; i++) {
		cout << "*";
		for (int j = 0; j < y - 2; j++) {
			cout << " ";
		}
		cout << "*" << endl;
	}

	for (int j = 0; j < y; j++) {
		cout << "*";
	}

	return 0;
}
