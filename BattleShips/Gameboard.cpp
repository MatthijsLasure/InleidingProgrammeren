/*
 * Gameboard.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(int x, int y) {
	xLimit = x;
	yLimit = y;
}

/*
 * getShipCoords: geef alle locaties ingenomen door de schepen van dit GameBoard
 * @return Vector met de coordinaten
 */
vector<Coordinates> GameBoard::getShipCoords() {
	vector<Coordinates> total;
	vector<Coordinates> temp;

	for (Ship ship : myShips) {
		temp = ship.getCoords();
		for (Coordinates c : temp) {
			total.push_back(c);
		}
		//total.insert(total.end(), ship.getCoords().begin(), ship.getCoords().end());
	}
	return(total);
}

/*
 * fire vuur een raket af op een locatie op dit bord. In geval van een hit, print info
 * @param missile de coordinaten van de raket
 * @return 0 voor gemist, 1 voor hit, 2 voor gezonken
 */
int GameBoard::fire(Coordinates missile) {
	// Zet op de lijst van raketten
	myMissiles.push_back(missile);
	// Loop over alle schepen, check of ze geraakt zijn
	// Note: geen loop over array, maar met indiches: we moeten de params in de vector aanpassen,
	// niet aan een gekopieerd object
	for (Ship &ship : myShips) {
		if(ship.isHit(missile)) {
			cout << "De raket op (" << missile.getX() << " " << missile.getY()
					<< ") heeft een schip geraakt!" << endl;
			myHits.push_back(missile);

			if (ship.isDead()) {
				cout << "Het schip " << ship.getName() << " is gezonken!" << endl;
				return (2);
			}
			else return (1);
		}
	}

	// For lus heeft niets gereturned, dus niets geraakt, dus false
	return(0);
}

/*
 * hasLost Check of dat de speler verloren heeft
 * @return True indien alle schepen gezonken zijn
 */
bool GameBoard::hasLost() {
	for (Ship ship : myShips) {
		if(!ship.isDead()) { // Een schip drijft nog
			return(false);
		}
	}
	// Alle schepen zijn gezonken
	return(true);
}

/*
 * addShip: voeg een nieuw schip toe aan de vloot
 * @param pos Coordinaten van het nieuwe schip
 * @param length lengte van het nieuwe schip
 * @param richting orientatie van het nieuwe schip
 * @param naam De naam van het nieuwe schip
 */
void GameBoard::addShip(Coordinates pos, int length, char richting, string name) {
	myShips.push_back(Ship{pos, length, richting, name});
}

/*
 * checkMissile: check of er al een raket is afgevuurd op de gegeven locatie
 * @param newMissile de coordinates van de nieuwe raket
 * @return True indien er al een raket is afgevuurd op die plaats
 */
bool GameBoard::checkMissile(Coordinates newMissile) {
	// Loop over alle afgevuurde missiles
	for(Coordinates missile : myMissiles) {
		// Check of er al een is
		if (newMissile.getX() == missile.getX() && newMissile.getY() == missile.getY()) return true;
	}
	return false;
}
