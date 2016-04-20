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

/*
 * Game: constructor
 * @param xi grootte van het veld, x richting
 * @param yi grootte van het veld, y richting
 * @param diffi moeilijkheidsgraad AI
 */
Game::Game(int xi, int yi, int diffi) :
		xLimit(xi), yLimit(yi), difficulty(diffi) {

	// Instellen gameboards
	board1 = GameBoard { xLimit, yLimit }; // speler ships + vijand bommen
	board2 = GameBoard { xLimit, yLimit }; // AI ships + speler bommen

	// Instellen output grenzen
	battlefield.setDimensions(xLimit, yLimit); // Set limits

	// Instellen AI
	gladOS.init(difficulty, xLimit, yLimit);
}

/*
 * GameLoop: dit is deel van het spel waarbij er geschoten moet worden
 * Zal returnen wanneer er een Game Over is
 */
void Game::gameLoop() {
	// Haal alle coordinaten op die ingenomen zijn door de schepen van de player.
	myShips = board1.getShipCoords();

	// Initiële draw
	draw();

	// Bijhouden wleke ronde het is
	int cyclus = 0;

	/*
	 * Var met info over laatste hit
	 * 0: gemist
	 * 1: geraakt
	 * 2: gezonken
	 */
	int hasHit = 0;

	while (!gameOver) { // Start gLoop
		// Nieuwe spelronde
		cyclus++;
		cout << "Spelronde " << cyclus << endl;

		// Zet input op 0
		Coordinates pInput { 0, 0 };

		// ================================
		// Speler
		// ================================

		// Vraag input
		pInput = player(xLimit, yLimit);

		// Vuur op gegeven plaats!
		hasHit = board2.fire(pInput);

		// Indien er iets geraakt is, onderneem actie
		if (hasHit > 0) {
			// Indien het schip gezonken is, check of het spel over is
			if (hasHit == 2)
				if (board2.hasLost()) { // Laat de speler weten, en zet de vars juist
					cout
							<< "Alle schepen van speler 2 zijn gezonken! Je hebt gewonnen!"
							<< endl;
					gameOver = true;
				}
		} else { // Er is niets geraakt
			cout << "De raket op (" << pInput.getX() << " " << pInput.getY()
					<< ") heeft niets geraakt!" << endl;
		} // Einde IF HASHIT

		// Teken het bord. Dit is vooral handig indien de AI veel tijd nodig heeft.
		draw();

		// Stop het spel indien player1 gewonnen heeft
		if (gameOver)
			break;

		// ================================
		// AI
		// ================================
		cout << "AI speelt..." << endl;

		// Vraag de input
		pInput = gladOS.getMove(board1);

		// De AI heeft voldoende safety checks om illegale moves te voorkomen.
		// Indien dit niet het geval is (e.g. bij gebruik van een andere AI), wordt de user geïnformeerd.
		if (board1.checkMissile(pInput)) {
			cerr
					<< "De AI heeft onwettig geschoten! Er is een probleem met het ontwerp."
					<< endl << pInput.getX() << " " << pInput.getY() << endl;
		}

		// Vuur op gegeven plaats!
		hasHit = board1.fire(pInput);

		// Laat het resultaat weten aan de AI
		gladOS.hasHit(pInput, hasHit);

		// Indien er iets geraakt is, onderneem actie
		if (hasHit > 0) {
			// Indien het schip gezonken is, check of het spel over is
			if (board1.hasLost()) { // Laat de speler weten, en zet de vars juist
				cout
						<< "Alle schepen van speler 1 zijn gezonken! Je hebt verloren!"
						<< endl;
				gameOver = true;
			}
		} else { // Er is niets geraakt
			cout << "De raket op (" << pInput.getX() << " " << pInput.getY()
					<< ") heeft niets geraakt!" << endl;
		} // Einde IF HASHIT

		// Teken het bord opnieuw.
		draw();

	} // End gLoop
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

	// Do zolang de input niet OK is
	do {
		cout << "Klaar om te schieten, geef de coordinaten in: ";

		// Vraag input
		cin >> x >> y;
		cin.clear(); // Kuis de stream, om ongelukjes te vermijden
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Check of de input binnen de grenzen is
		if (x > 0 && x <= xLimit && y > 0 && y <= yLimit) {
			input.setX(x);
			input.setY(y);

			// Check of er daar nog niet gevuurd is
			if (board2.checkMissile(input)) {
				cout << "Daar is al geschoten. Probeer opnieuw!" << endl;
				inputOK = false;
			} else { // Binnen grenzen
				inputOK = true;
			}
		} else { // Niet binnen grenzen, print fout
			cout << "Foute input! Voer 2 gehele getallen in tussen 1 en "
					<< xLimit << " voor de X en tussen 1 en " << yLimit
					<< " voor de Y!" << endl;
			inputOK = false;
		}
	} while (!inputOK); // Einde DO

	return (input);
}

/*
 * drawInit: teken het bord voor het spel begonnen is.
 * Deze functie is publiek, zodat de MAIN functie deze kan aanroepen tijdens de invoer van de schepen.
 */
void Game::drawInit() {
	myShips = board1.getShipCoords();
	draw();
}
