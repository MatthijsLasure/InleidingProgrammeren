#ifndef GAME_H_
#define GAME_H_

/*
 * Game.h
 * @author Matthijs Lasure
 * @date 13-apr.-2016
 */

#include "Coordinates.h"
#include "GameBoard.h"
#include "Graphics.h"

class Game {
public:
	Game(int, int);

private:
	int xLimit, yLimit;

	GameBoard board1{1,1}; // De speler
	GameBoard board2{1,1}; // AI

	const vector<Coordinates> myShips = board1.getShipCoords();

	Graphics battlefield;

	bool gameOver;

};

Coordinates player(int, int);

Coordinates AI();


#endif /* GAME_H_ */
