/*
 * 
 *	@Author Sven Arnouts
 *  @Date 22-mrt.-2016
 */

#include <iostream>
#include "myMathLib.h"

using namespace std;

int main() {
	//Definieer de variabelen
	float hoek;
	long double macht;

	cout << "Geef een hoek in radialen: " << endl;
	cin >> hoek;
	cout << "Geef een float: " << endl; //test abs-functie
	cin >> macht;
	cout << abs(macht) << endl;
	cout << power(10, -8) << endl;
	cout << "De sinus van deze hoek is gelijk aan " << sin(hoek);
}


