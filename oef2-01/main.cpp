/*
 * Main function for exercise 2-1
 * @author: Mattthijs Lasure
 * @Date 04/02016
 */

#include <iostream>

using namespace std;

int main() {
	// Definiëer de variabelen
	int ingelezenNummer;
	double doubleNummer;
	char charNummer;
	bool boolNummer;

	// Lees de gevraagde waarde in
	cout << "Welke integer wilt u omzetten? ";
	cin >> ingelezenNummer;

	// Zet de juiste waarden
	doubleNummer = ingelezenNummer;
	charNummer = ingelezenNummer;
	boolNummer = ingelezenNummer;

	// Print de variabelen
	cout << "int = " << ingelezenNummer << endl;
	cout << "double = " << doubleNummer << endl;
	cout << "char = " << charNummer << endl;
	cout << "bool = " << boolNummer << endl;

}

