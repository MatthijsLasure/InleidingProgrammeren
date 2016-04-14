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

	for (Ship ship : myShips) {
		total.insert(total.end(), ship.getCoords().begin(), ship.getCoords().end());
	}
	return(total);
}

bool GameBoard::fire(Coordinates missile) {
	for (Ship ship : myShips) {
		if(ship.isHit(missile)) {
			cout << "De raket op (" << missile.getX() << " " << missile.getY()
					<< ") heeft het schip " << ship.getName()
					<< " (lengte " << ship.getLength() << ") geraakt!" << endl;
			return(true);
		}
	}
	return(false);
}
