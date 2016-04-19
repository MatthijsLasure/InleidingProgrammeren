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

	vector<Coordinates> getMissiles() {
		return (myMissiles);
	}
	;
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

	bool hasLost();

	void addShip(Coordinates, int, char, string);

	bool checkMissile(Coordinates);

private:
	int xLimit, yLimit;
	vector<Ship> myShips;
	vector<Coordinates> myMissiles; // Gemiste raketten van de andere
	vector<Coordinates> myHits; // Hits toegebracht door de andere
};

#endif /* GAMEBOARD_H_ */
