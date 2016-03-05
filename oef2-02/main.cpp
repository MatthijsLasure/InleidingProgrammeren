/*
 * Main function for exercise 2-1
 * @author: Mattthijs Lasure
 * @Date 04/02016
 */

#include <iostream>

using namespace std;

int main() {
	// Definiëer de variabelen
	int intNummer;
	double doubleNummer;
	char charNummer;
	bool boolNummer;

	// Lees de gevraagde waarde in
	cout << "Welke double wilt u omzetten? ";
	cin >> doubleNummer;

	// Zet de juiste waarden
	intNummer = doubleNummer;
	charNummer = doubleNummer;
	boolNummer = doubleNummer;

	// Print de variabelen
	cout << "double = " << doubleNummer << endl;
	cout << "int = " << intNummer << endl;
	cout << "char = " << charNummer << endl;
	cout << "bool = " << boolNummer << endl;

}

