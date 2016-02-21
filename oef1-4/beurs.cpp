/*
 * beurs.cpp
 *
 *  Created on: 17 Feb 2016
 *      Author: Matthijs
 *
 * 4. Lees een bedrag in euro in, en print af hoeveel dat bedrag vandaag in pond en dollar waard is.
 */

#include <iostream>

using namespace std;

int main() {
	float euro2dollar = 1.114255; // https://www.google.be/search?q=1+�+in+%24
	float euro2pond = 0.778119184; // https://www.google.be/search?q=1+�+in+�&oq=1+�+in+�
	float myMoney = 0;

	cout << "Voer een bedrag in: ";
	cin >> myMoney;
	cout << myMoney << " � is respectievelijk " << (myMoney * euro2dollar) << " US$ of " << (myMoney * euro2pond) << "UK£ waard.\n";

	return 0;
}


