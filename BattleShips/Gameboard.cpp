/*
 * Gameboard.cpp
 * Opslag voor schepen en bommen van een speler. Bevat ook functies ter manipulatie en controle.
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <iostream>
#include "GameBoard.h"

using namespace std;

/*
 * Constructor
 * @param x De spelgrootte, in de X richting
 * @param y De spelgrootte, in de Y richting
 */
GameBoard::GameBoard(int x, int y) {
	xLimit = x;
	yLimit = y;
}

/*
 * getShipCoords: geef alle locaties ingenomen door de schepen van dit GameBoard
 * @return Vector met de coordinaten
 */
vector<Coordinates> GameBoard::getShipCoords() {
	vector<Coordinates> total; // Vector met alle plaatsen
	vector<Coordinates> temp; // Vector met plaatsen van 1 schip

	// Loop over alle schepen
	for (Ship ship : myShips) {
		temp = ship.getCoords(); // Vraag alle locaties van een schipo
		for (Coordinates c : temp) {
			total.push_back(c); // Zet alle locaties bij op de vector
		}
	}
	return (total);
}

/*
 * fire: Vuur een raket af op een locatie op dit bord. In geval van een hit, print info
 * @param missile de coordinaten van de raket
 * @return 0 voor gemist, 1 voor hit, 2 voor gezonken
 */
int GameBoard::fire(Coordinates missile) {
	// Zet op de lijst van raketten
	myMissiles.push_back(missile);
	// Loop over alle schepen, check of ze geraakt zijn
	// Note: referencing: de schepen moeten aangepast worden indien geraakt
	for (Ship &ship : myShips) { // Loop over alle schepen
		if (ship.isHit(missile)) { // Vuur raket af op schip, check resultaat
			// Print info
			cout << "De raket op (" << missile.getX() << " " << missile.getY()
					<< ") heeft een schip geraakt!" << endl;
			// Zet raket op lijst met hits
			myHits.push_back(missile);

			// Check of het schip gezonken is, print info
			if (ship.isDead()) {
				cout << "Het schip " << ship.getName() << " is gezonken!"
						<< endl;
				return (2);
			} else
				return (1); // Niet gezonken
		} // Einde isHit
	} // Einde loop

	// For lus heeft niets gereturned, dus niets geraakt, dus false
	return (0);
}

/*
 * hasLost Check of dat de speler verloren heeft
 * @return True indien alle schepen gezonken zijn
 */
bool GameBoard::hasLost() {
	for (Ship ship : myShips) { // Loop over alle schepen
		if (!ship.isDead()) { // Een schip drijft nog
			return (false); // Dus nog niet verloren!
		}
	}
	// Alle schepen zijn gezonken
	return (true);
}

/*
 * checkMissile: check of er al een raket is afgevuurd op de gegeven locatie / het een legale plaats is
 * @param newMissile de coordinates van de nieuwe raket
 * @return True indien er al een raket is afgevuurd op die plaats, of het niet binnen de grenzen ligt
 */
bool GameBoard::checkMissile(Coordinates newMissile) {
	// Check grenzen
	if (newMissile.getX() > xLimit || newMissile.getX() < 1
			|| newMissile.getY() > yLimit || newMissile.getY() < 1)
		return (true);

	// Loop over alle afgevuurde missiles
	for (Coordinates missile : myMissiles) {
		// Check of er al een is
		if (newMissile.getX() == missile.getX()
				&& newMissile.getY() == missile.getY())
			return (true);
	}

	return (false);
}
