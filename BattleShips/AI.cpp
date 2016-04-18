/*
 * AI.cpp
 * @author Matthijs Lasure
 * @date 15-apr.-2016
 */

#include "AI.h"
#include "GameBoard.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

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

	if (difficulty >= 2) {
		mode = 6; // Random hunt
		defmode = 6;
	}
	else {
		mode = 0; // Checkers
		defmode = 0;
	}
}

Coordinates AI::getMove(GameBoard board) {
	cout << "GetMove" << endl;
	Coordinates answer{0,0};
	vector<Coordinates> avail;
	int abc, x, y;
	switch (mode) {
	case 0: // Checkerboard pattern
		for (int i = 0; i < checkers.size(); i++) {
			if (board.checkMissile(checkers[i])) {
				checkers.erase(checkers.begin() + i);
			}
		}
		if (checkers.size() > 0) {
			cout << "getMove case 0 checkers" << checkers.size() << endl;
			for ( Coordinates c : checkers)
				cout << c.getX() << " " << c.getY() << endl;
			do {
				abc = rand() % checkers.size();
				answer = checkers[abc];
			} while (board.checkMissile(answer));
		} else {
			defmode = 6;
			mode = 6;
			cout << "getMove case 0 rand" << endl;
			do {
				int x = rand() % xLimit + 1;
				int y = rand() % yLimit + 1;

				answer = Coordinates{x, y};

			} while (board.checkMissile(answer));
		}
		break;
	case 1: // Has hit once, fire in vicinity
		for (int i = -1; i <= 1; i += 2) {
			answer = Coordinates{i + firstHit.getX(), firstHit.getY()};
			if(! board.checkMissile(answer))
				avail.push_back(answer);

			answer = Coordinates{firstHit.getX(), i + firstHit.getY()};
			if(! board.checkMissile(answer))
				avail.push_back(answer);
		}
		answer = avail[rand() % avail.size()];

		x = answer.getX() - firstHit.getX();
		y = answer.getY() - firstHit.getY();

		if (x == -1) zoekrichting = 3; // West
		else if (x == 1) zoekrichting = 1; // East
		else if (y == -1) zoekrichting = 0; // North
		else zoekrichting = 2; // South

		break;
	case 2: // Deprecated
	case 3:
		break;
	case 4:
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
		if ( !board.checkMissile(answer)) // Check legit, anders andere kant
			break;
		else {
			mode = 5;
			zoekrichting += 2;
			if (zoekrichting > 3) zoekrichting -= 4;
			lastHit = firstHit;
		}
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
		if ( !board.checkMissile(answer)) // Check legit
			break;
		else {
			mode = defmode;
		}
	case 6:
		cout << "getMove case 6 rand" << endl;
		do {
			int x = rand() % xLimit + 1;
			int y = rand() % yLimit + 1;

			answer = Coordinates{x, y};

		} while (board.checkMissile(answer));

	}

	return(answer);
}

void AI::hasHit(Coordinates hit, int severity) {
	cout << "hasHit" << endl;
	if (severity > 0) lastHit = hit;

	if (difficulty == 2 || difficulty == 0) {
		switch (mode) {
		// Not hunting a ship
		case 0:
		case 6:
			if (severity == 1) {
				mode = 1;
				firstHit = hit;
			} else if (severity == 2) // Mocht er ooit een 1 vak schip zijn :)
				mode = defmode;
			break;
		// First hunting, looking for the rest of the ship
		case 1:
			if(severity == 1) mode = 4;
			else if (severity == 2)
				mode = defmode;
			break;
		case 2: // Deprecated
		case 3:
			break;
		// Schieten op de rest vh schip, deel 1
		case 4:
			if (severity == 0)
				mode = 5;
			else if(severity == 2)
				mode = defmode;
			break;
		// Schieten op de rest vh schip, deel 2
		case 5:
			if (severity == 2 || severity == 0)
				mode = defmode;
			break;
		}
	}
}
