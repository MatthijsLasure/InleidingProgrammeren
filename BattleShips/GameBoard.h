#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

/*
 * GameBoard.h
 * @author Matthijs Lasure
 * @date 13-apr.-2016
 */

#include <vector>
#include "Ship.h"
#include "Coordinates.h"

class GameBoard {
public:
	/*
	 * Constructor: stelt de grootte in van het bord
	 * @param x grootte van het bord in de X richting
	 * @param y grootte van het bord in de Y richting
	 */
	GameBoard(int, int);

	/*
	 * Getter: Alle raketten afgevuurd op dit bord
	 */
	vector<Coordinates> getMissiles() {
		return (myMissiles);
	}
	;

	/*
	 * Getter: Alle raketten die iets geraakt hebben op dit bord
	 */
	vector<Coordinates> getHits() {
		return (myHits);
	}
	;

	/*
	 * getShipCoords: geef alle locaties ingenomen door de schepen van dit GameBoard
	 * @return Vector met de coordinaten
	 */
	vector<Coordinates> getShipCoords();

	/*
	 * fire: inkomende raket van de vijand, check indien hit, reageer
	 * @param missile de positie van de raket
	 * @return 0 voor gemist, 1 voor hit, 2 voor gezonken
	 */
	int fire(Coordinates);

	/*
	 * hasLost Check of dat de speler verloren heeft
	 * @return True indien alle schepen gezonken zijn
	 */
	bool hasLost();

	/*
	 * addShip: Setter: voeg een nieuw schip toe aan de vloot
	 * @param pos Coordinaten van het nieuwe schip
	 * @param length lengte van het nieuwe schip
	 * @param richting orientatie van het nieuwe schip
	 * @param naam De naam van het nieuwe schip
	 */
	void addShip(Coordinates pos, int length, char richting, string name) {
		myShips.push_back(Ship { pos, length, richting, name });
	}

	/*
	 * checkMissile: check of er al een raket is afgevuurd op de gegeven locatie / het een legale plaats is
	 * @param newMissile de coordinates van de nieuwe raket
	 * @return True indien er al een raket is afgevuurd op die plaats, of het niet binnen de grenzen ligt
	 */
	bool checkMissile(Coordinates);

private:
	// Grootte van het bord
	int xLimit, yLimit;

	// Verzameling posities
	vector<Ship> myShips;

	vector<Coordinates> myMissiles; // Gemiste raketten van de andere
	vector<Coordinates> myHits; // Hits toegebracht door de andere
};

#endif /* GAMEBOARD_H_ */
