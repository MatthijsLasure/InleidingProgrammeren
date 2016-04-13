/*
 * ZeeSlag.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <iostream>
#include "Coordinates.h"
#include "Ship.h"

using namespace std;

int main() {
	// Initialisatie
	cout << "Klaar voor een spelletje zeeslag?\n(C) Matthijs Lasure" << endl;
	// TODO config lezen
	// TODO config checken voor errors

	// TODO inlezen coords
	// TODO checken coords
	Ship fregat{Coordinates{1,1}, 5, 'H', "Fregat"};
	cout << fregat.isHit(Coordinates{1,5}) << endl;
	for (int i = 1; i < 6; i++) {
		fregat.isHit(Coordinates{1,i});
	}

	// Start het spel!


	// Terminatie van het programma
	cout << "Programma is afgelopen. Tot de volgende keer!" << endl;
	return(0);
}
