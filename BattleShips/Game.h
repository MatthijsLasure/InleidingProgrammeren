#ifndef GAME_H_
#define GAME_H_

/*
 * Game.h
 * @author Matthijs Lasure
 * @date 13-apr.-2016
 */

#include "GameBoard.h"
#include "Graphics.h"

class Game {
public:
	Game();
private:
	GameBoard board1; // De speler
	GameBoard board2; // AI

	Graphics battlefield;

	bool gameOver;
};




#endif /* GAME_H_ */
