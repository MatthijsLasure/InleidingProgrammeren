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
Ship::Ship(Coordinates pos, int lengthi, char richting, string name) :
		length(lengthi) {

	if (richting == 'h') { // Horizontaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates { pos.getX() + i, pos.getY() });
		}
	} else { // Vertikaal
		// Voor de hele lengte, maak een nieuwe Coordinates in de vector aan
		for (int i = 0; i < length; i++) {
			// Zet de coords bij op de vector
			locations.push_back(Coordinates { pos.getX(), pos.getY() + i });
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
		if (missile.getX() == loc.getX() && missile.getY() == loc.getY()) { // Hit!
			hits++;
			if (hits == length) // Als er evenveel hits zijn als het schip lang is, dan zinkt het
				dead = true;
			return (true);
		}
	}
	return (false); // Miss!
}
