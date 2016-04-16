/*
 * Ship.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <string>
#include <iostream>
#include "Coordinates.h"
#include "Ship.h"

using namespace std;

/*
 * Constructor van de klasse Ship
 * @param pos Originele positie van het schip zoals opgegeven door de speler
 * @param length Lengte van het schip
 * @param richting Ori�ntatie van het schip: horizontaal / verticaal
 * @param name Naam van het schip
 */
Ship::Ship(Coordinates pos, int lengthi, char richting, string name) {
	// Reserveer plaats
	length = lengthi;
	hits = 0;

	if ( richting == 'h' ) { // Horizontaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates{pos.getX() + i, pos.getY()});
		}
	} else { // Vertikaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates{pos.getX(), pos.getY() + i});
		}
	}

	// Variabelen instellen
	dead = false; // Het schip leeft nog bij de initialisatie
	schipNaam = name; // Ingeven van de naam

}

/*
 * Check of het schip geraakt is door een raket, en stelt de variabelen in indien ja
 * @param missile Coordinaten van de afgevuurde raket
 * @return True indien het schip geraakt is
 */
bool Ship::isHit(Coordinates missile) {
	// Loop over alle locaties vh schip
	for (Coordinates loc : locations) {
		if(missile.getX() == loc.getX() && missile.getY() == loc.getY()) { // Hit!

			hits++;
			cout << hits << endl;
			if(hits == length) {
				dead = true;
				cout << "Schip '" << schipNaam << "' is gezonken!";
			}
			return(true);

		}
	}
	return(false); // Miss!
}
