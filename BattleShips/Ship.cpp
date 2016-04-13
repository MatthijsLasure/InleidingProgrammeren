/*
 * Ship.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <string>
#include "Coordinates.h"
#include "Ship.h"

using namespace std;

/*
 * Constructor van de klasse Ship
 * @param pos Originele positie van het schip zoals opgegeven door de speler
 * @param length Lengte van het schip
 * @param richting Oriëntatie van het schip: horizontaal / verticaal
 * @param name Naam van het schip
 */
Ship::Ship(Coordinates pos, int length, char richting, string name) {
	// Reserveer plaats
	locations.reserve(length);
	hits.reserve(length);

	if ( richting == 'H' ) { // Horizontaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates{pos.getX() + i, pos.getY()});
			hits.push_back(false); // Is nog niet geraakt
		}
	} else { // Vertikaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates{pos.getX(), pos.getY() + i});
			hits.push_back(false); // Is nog niet geraakt
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
	int i = 0;
	// Loop over alle locaties vh schip
	for (Coordinates loc : locations) {
		if(missile.getX() == loc.getX() && missile.getY() == loc.getY()) { // Hit!

			hits[i] = true;
			checkSunk();
			return(true);

		}
		i++;
	}
	return(false); // Miss!
}

/*
 * Check of het schip gezonken is, en zet de boolean correct.
 */
void Ship::checkSunk() {
	for (bool hit : hits) {
		if( ! hit ) { // Has not sunk
			return;
		}
	}
	// Has sunk
	dead = true;
}
