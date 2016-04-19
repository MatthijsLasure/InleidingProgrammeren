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
#include "AI.h"

class Game {
public:
	Game(int, int, int);
	void gameLoop();
	void addShip(int, Coordinates, int, char, string);

	bool checkBounds(Coordinates, int, char);

	bool checkClipped(int, Coordinates, int, char);

	void drawInit();

private:
	int xLimit, yLimit;

	int difficulty;

	GameBoard board1 { 1, 1 }; // De speler
	GameBoard board2 { 1, 1 }; // AI

	//AI
	AI gladOS;

	vector<Coordinates> myShips;

	Graphics battlefield;

	bool gameOver;

	/*
	 * player: vraag de input van de player, en controleer
	 * @param xLimit de grootte van het spelbord in de X richting
	 * @param yLimit de grootte van het spelbord in de Y richting
	 * @return De ingegeven coordinaten
	 */
	Coordinates player(int, int);

	void draw();
};

#endif /* GAME_H_ */
