#ifndef SHIP_H_
#define SHIP_H_

/*
 * Ship.h
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <string>
#include <vector>
#include "Coordinates.h"

using namespace std;

class Ship {
public:
	/*
	 * Constructor van de klasse Ship
	 * @param pos Originele positie van het schip zoals opgegeven door de speler
	 * @param length Lengte van het schip
	 * @param richting Ori�ntatie van het schip: horizontaal / verticaal
	 * @param name Naam van het schip
	 */
	Ship(Coordinates pos, int length, char richting, string name);

	/*
	 * Getter: lengte
	 */
	int getLength() {
		return (length);
	}

	/*
	 * Getter: naam
	 */
	string getName() {
		return (schipNaam);
	}

	/*
	 * Check of het schip gezonken is.
	 * @return True indien het schip gezonken is.
	 */
	bool isDead() {
		return (dead);
	}

	/*
	 * Check of het schip geraakt is door een raket/bom, en stelt de variabelen in indien ja
	 * @param missile Coordinaten van de afgevuurde raket
	 * @return True indien het schip geraakt is
	 */
	bool isHit(Coordinates missile);

	/*
	 * Geef de locaties terug
	 * @return een vector met coordinaten
	 */
	vector<Coordinates> getCoords() {
		return (locations);
	}

private:
	bool dead = false; // Is het ship volledig gebombardeerd?
	int length = 0; // lengte
	int hits = 0; // Aantal hits

	vector<Coordinates> locations; // Vector met de bezette locaties door het schip
	string schipNaam; // Naam van het schip

};

#endif /* SHIP_H_ */
