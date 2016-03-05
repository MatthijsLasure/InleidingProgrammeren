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
	cout << "Welke char wilt u omzetten? ";
	cin >> charNummer;

	// Zet de juiste waarden
	intNummer = charNummer;
	doubleNummer = charNummer;
	boolNummer = charNummer;

	// Print de variabelen
	cout << "int = " << intNummer << endl;
	cout << "double = " << doubleNummer << endl;
	cout << "char = " << charNummer << endl;
	cout << "bool = " << boolNummer << endl;

}

