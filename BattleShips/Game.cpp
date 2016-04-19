/*
 * Game.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <limits>
#include <iostream>
#include <string>
#include "Game.h"
#include "GameBoard.h"
#include "Graphics.h"
#include "AI.h"

using namespace std;

Game::Game(int xi, int yi, int difficulty) {
	gameOver = false;
	xLimit = xi;
	yLimit = yi;

	board1 = GameBoard { xLimit, yLimit };
	board2 = GameBoard { xLimit, yLimit };

	// Instellen HTML
	battlefield.setDimensions(xLimit, yLimit); // Set limits

	// Instellen AI
	gladOS.init(difficulty, xLimit, yLimit);
}

/*
 * GameLoop: dit is deel van het spel waarbij er geschoten moet worden
 * Zal returnen wanneer er een Game Over is
 */
void Game::gameLoop() {
	myShips = board1.getShipCoords();

	// Initiële draw
	draw();

	// DEBUG
//	for (Coordinates s : myShips) {
//		cout << s.getX() << " " << s.getY() << endl;
//	}

	int cyclus = 0;
	int hasHit = 0;

	while (!gameOver) {
		cyclus++;
		cout << "Spelronde " << cyclus << endl;
		Coordinates pInput { 0, 0 };

		// Speler
		// ======
		// Vraag input
//		pInput = player(xLimit, yLimit);
//		hasHit = board2.fire(pInput);
//		if (hasHit > 0) { // Hit
//			// check game over
//			if (hasHit == 2)
//			if(board2.hasLost()) {
//				cout << "Alle schepen van speler 2 zijn gezonken! Je hebt gewonnen!" << endl;
//				gameOver = true;
//			}
//		} else {
//			cout << "De raket op (" << pInput.getX() << " " << pInput.getY()
//					<< ") heeft niets geraakt!" << endl;
//		}

		// Draw
		draw();

		// Stop het spel indien player1 gewonnen heeft
		if (gameOver)
			break;

		// AI
		// ==
		cout << "AI speelt..." << endl;
		pInput = gladOS.getMove(board1);
		hasHit = board1.fire(pInput);

		// Laat het weten aan de AI
		gladOS.hasHit(pInput, hasHit);

		if (hasHit > 0) {
			// check game over
			if (board1.hasLost()) {
				cout
						<< "Alle schepen van speler 1 zijn gezonken! Je hebt verloren!"
						<< endl;
				gameOver = true;
			}
		} else {
			cout << "De raket op (" << pInput.getX() << " " << pInput.getY()
					<< ") heeft niets geraakt!" << endl;
		}

		// Draw again
		draw();
	}
}

/*
 * addShip: voeg een schip toe aan een speler
 * @param board de eigenaar van het schip. 1 = player, 2 = AI
 * @param pos de positie van het schip
 * @param length lengte van het schip
 * @param richting de orientatie van het schip (h / v)
 * @param name de naam van het schip
 */
void Game::addShip(int board, Coordinates pos, int length, char richting,
		string name) {
	if (board == 1)
		board1.addShip(pos, length, richting, name);
	else
		board2.addShip(pos, length, richting, name);
}

/*
 * checkBounds: check of een nieuw schip niet buiten de limieten gaat
 * @param pos de positie van het schip
 * @param length de lengte van het schip
 * @param richting de orientatie van het schip (h / v)
 * @return True indien het schip op deze plaats gelegd mag worden
 */
bool Game::checkBounds(Coordinates pos, int length, char richting) {
	if (richting == 'h') {
		if (pos.getX() + length - 1 > xLimit)
			return (false);
		else
			return (true);
	} else {
		if (pos.getY() + length - 1 > yLimit)
			return (false);
		else
			return (true);
	}
}

/*
 * checkClipped: controleer of een nieuw schip niet zal botsen met bestaande schepen
 * @param board welke speler te controleren
 * @param pos coords van het nieuwe schip
 * @param length lengte van het nieuwe schip
 * @param richting oriëntatie van het nieuwe schip
 * @return True indien er een conflict zal optreden
 */
bool Game::checkClipped(int board, Coordinates pos, int length, char richting) {
	vector<Coordinates> shipCoords;

	// Haal de juiste coords op
	if (board == 1)
		shipCoords = board1.getShipCoords();
	else
		shipCoords = board2.getShipCoords();

	if (richting == 'h') { // Horizontaal, dus x'en aanpassen
		for (Coordinates existing : shipCoords) { // Voor alle bestaande schepen
			for (int i = 0; i < length; i++) { // Voor alle posities die ingenomen zullen worden
				if (existing.getX() == pos.getX() + i
						&& existing.getY() == pos.getY())
					return (true);
			}
		}
	} else { // Vertikaal, dus y'en aanpassen
		for (Coordinates existing : shipCoords) { // Voor alle bestaande schepen
			for (int i = 0; i < length; i++) { // Voor alle posities die ingenomen zullen worden
				if (existing.getX() == pos.getX()
						&& existing.getY() == pos.getY() + i)
					return (true);
			}
		}
	}

	// Niets heeft gereturned, dus geen conflict
	return (false);
}

/*
 * player: vraag de input van de player, en controleer
 * @param xLimit de grootte van het spelbord in de X richting
 * @param yLimit de grootte van het spelbord in de Y richting
 * @return ingegeven coordinaten
 */
Coordinates Game::player(int xLimit, int yLimit) {
	Coordinates input { 0, 0 };
	bool inputOK = false;
	int x, y;

	do {
		cout << "Klaar om te schieten, geef de coordinaten in: ";

		cin >> x >> y;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Check de input
		if (x > 0 && x <= xLimit && y > 0 && y <= yLimit) {
			input.setX(x);
			input.setY(y);

			// Check of er daar nog niet gevuurd is
			if (board2.checkMissile(input)) {
				cout << "Daar is al geschoten. Probeer opnieuw!" << endl;
				inputOK = false;
			} else {
				inputOK = true;
			}
		} else {
			cout << "Foute input! Voer 2 gehele getallen in tussen 1 en "
					<< xLimit << " voor de X en tussen 1 en " << yLimit
					<< " voor de Y!" << endl;
			inputOK = false;
		}
	} while (!inputOK);

	return (input);
}

void Game::draw() {
	battlefield.draw(myShips, board2.getHits(), board2.getMissiles(),
			board1.getHits(), board1.getMissiles());
}

void Game::drawInit() {
	myShips = board1.getShipCoords();
	draw();
}
