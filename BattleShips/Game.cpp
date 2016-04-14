/*
 * Game.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <iostream>
#include "Game.h"
#include "GameBoard.h"
#include "Graphics.h"

using namespace std;

Game::Game(int xi, int yi) {
	gameOver = false;
	xLimit = xi;
	yLimit = yi;

	board1 = GameBoard{xLimit, yLimit};
	board2 = GameBoard{xLimit, yLimit};

	// Initiële draw
	battlefield.setDimensions(xLimit, yLimit); // Set limits
	battlefield.draw(myShips, board2.getMissiles(), board2.getHits(), board1.getMissiles(), board1.getHits());


	while(! gameOver) {
		// Speler
		// TODO acties => functie
		Coordinates pInput = player(xLimit, yLimit);
		board2.fire(pInput);

		// Draw

		// AI
		// TODO AI
	}
}

/*
 * player: vraag de input van de player, en controleer
 * @return ingegeven coordinaten
 */
Coordinates player(int xLimit, int yLimit) {
	Coordinates input{0,0};
	bool inputOK = false;
	int x, y;

	do {
		cout << "Klaar om te schieten, geef de coördinaten in: ";
		cin >> x >> y;
		// Check de input
		if (x > 0 && x < xLimit && y > 0 && y < yLimit ) {
			inputOK = true;
		} else {
			cerr << "Foute input! Voer 2 gehele getallen in tussen 1 en "
					<< xLimit << " voor de X en "
					<< yLimit << " voor de Y!" << endl;
			inputOK = false;
		}
	} while (!inputOK);

	input.setX(x);
	input.setY(y);

	return(input);
}
