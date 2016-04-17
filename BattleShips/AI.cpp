/*
 * AI.cpp
 * @author Matthijs Lasure
 * @date 15-apr.-2016
 */

#include "AI.h"
#include "GameBoard.h"
#include <stdlib.h>

AI::AI() { };

void AI::init(int diffi, int xL, int yL) {
	difficulty = diffi;
	xLimit = xL;
	yLimit = yL;

	// Maak de checkers matrix indien gevraagd
	if (difficulty <= 1) {
		// Vul de checkers matrix
		bool value = false;
		bool rowInit = false;
		if (rand() % 100 + 1 > 50) rowInit = true;

		for (int i = 0; i < xLimit; i++) {
			if (rowInit) rowInit = false;
			else rowInit = true;
			value = rowInit;
			for (int j = 0; j < yLimit; j++) {
				if (value) {
					checkers.push_back(Coordinates{i + 1,j + 1});
					value = false;
				} else value = true;
			}
		}
	} // Einde checkers matrix init

	if (difficulty >= 2) mode = 6; // Random hunt
	else mode = 0; // Checkers
}

Coordinates AI::getMove(GameBoard board) {
	Coordinates answer{0,0};
	int abc;
	switch (mode) {
	case 0: // Checkerboard pattern
		if (checkers.size() > 0) {
			do {
				abc = rand() % checkers.size();
				answer = checkers[abc];
			} while (board.checkMissile(answer));
			checkers.erase(checkers.begin() + abc);
		} else {
			do {
				int x = rand() % xLimit + 1;
				int y = rand() % yLimit + 1;

				answer = Coordinates{x, y};

			} while (board.checkMissile(answer));
		}
		break;
	case 1: // Has hit once, fire in vicinity
	case 2:
	case 3:
	case 4:
	case 5:
		answer = lastHit;
		switch (zoekrichting) {
		case 0: // North
			answer.setY(lastHit.getY() - 1);
			break;
		case 1: // East
			answer.setX(lastHit.getX() + 1);
			break;
		case 2: // South
			answer.setY(lastHit.getY() + 1);
			break;
		case 3: // West
			answer.setX(lastHit.getX() - 1);
			break;
		}
		break;
	case 6:
		do {
			int x = rand() % xLimit + 1;
			int y = rand() % yLimit + 1;

			answer = Coordinates{x, y};

		} while (board.checkMissile(answer));

	}

	return(answer);
}

void AI::hasHit(Coordinates hit, int severity) {
	if (severity > 0) lastHit = hit;

	if (difficulty == 2 || difficulty == 0) {
		switch (mode) {
		// Not hunting a ship
		case 0:
		case 6:
			if (severity == 1) {
				mode = 1;
				firstHit = hit;
				zoekrichting = rand() % 3;
			} else if (severity == 2) { // Mocht er ooit een 1 vak schip zijn :)
				if (difficulty <= 1) mode = 0;
				else mode = 6;
			}
			break;
		// First hunting, looking for the rest of the ship
		case 1:
		case 2:
			if (severity == 0) zoekrichting++;
			else if(severity == 1) mode = 4;
			else {
				if (difficulty <= 1) mode = 0;
				else mode = 6;
			}
			break;
		// 3e hunt, indien geen hit, veronderstel op de 4e plaats
		case 3:
			if (severity == 0) {
				zoekrichting++;
				mode = 4;
			} else if (severity == 1) mode = 4;
			else {
				if (difficulty <= 1) mode = 0;
				else mode = 6;
			}
			break;
		// Schieten op de rest vh schip, deel 1
		case 4:
			if (severity == 0) {
				mode = 5;
				zoekrichting += 2;
				lastHit = firstHit;
				if (zoekrichting > 3) zoekrichting -= 4;
			}
			else if(severity == 2) {
				if (difficulty <= 1) mode = 0;
				else mode = 6;
			}
			break;
		// Schieten op de rest vh schip, deel 2
		case 5:
			if (severity == 2) {
				if (difficulty <= 1) mode = 0;
				else mode = 6;
			}
			break;
		}
	}
}
