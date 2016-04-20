#ifndef GAME_H_
#define GAME_H_

/*
 * Game.h
 * Bevat de gamelogica voor het spel zelf. Bevat ook alle info over schepen etc.
 * @author Matthijs Lasure
 * @date 13-apr.-2016
 */

#include "Coordinates.h"
#include "GameBoard.h"
#include "Graphics.h"
#include "AI.h"

class Game {
public:
	/*
	 * Game: constructor
	 * @param xi grootte van het veld, x richting
	 * @param yi grootte van het veld, y richting
	 * @param diffi moeilijkheidsgraad AI
	 */
	Game(int, int, int);

	/*
	 * GameLoop: dit is deel van het spel waarbij er geschoten moet worden
	 * Zal returnen wanneer er een Game Over is
	 */
	void gameLoop();

	/*
	 * addShip: voeg een schip toe aan een speler
	 * @param board de eigenaar van het schip. 1 = player, 2 = AI
	 * @param pos de positie van het schip
	 * @param length lengte van het schip
	 * @param richting de orientatie van het schip (h / v)
	 * @param name de naam van het schip
	 */
	void addShip(int, Coordinates, int, char, string);

	/*
	 * checkBounds: check of een nieuw schip niet buiten de limieten gaat
	 * @param pos de positie van het schip
	 * @param length de lengte van het schip
	 * @param richting de orientatie van het schip (h / v)
	 * @return True indien het schip op deze plaats gelegd mag worden
	 */
	bool checkBounds(Coordinates, int, char);

	/*
	 * checkClipped: controleer of een nieuw schip niet zal botsen met bestaande schepen
	 * @param board welke speler te controleren
	 * @param pos coords van het nieuwe schip
	 * @param length lengte van het nieuwe schip
	 * @param richting oriëntatie van het nieuwe schip
	 * @return True indien er een conflict zal optreden
	 */
	bool checkClipped(int, Coordinates, int, char);

	/*
	 * drawInit: teken het bord voor het spel begonnen is.
	 * Deze functie is publiek, zodat de MAIN functie deze kan aanroepen tijdens de invoer van de schepen.
	 */
	void drawInit();

private:
	// Limieten van het bord
	int xLimit, yLimit;

	// Moeilijkheidsgraad AI
	int difficulty;

	GameBoard board1 { 1, 1 }; // De speler
	GameBoard board2 { 1, 1 }; // AI

	//AI
	AI gladOS;

	// Schepen van de player
	vector<Coordinates> myShips;

	// Voor grafische interface
	Graphics battlefield;

	bool gameOver = false;

	/*
	 * player: vraag de input van de player, en controleer
	 * @param xLimit de grootte van het spelbord in de X richting
	 * @param yLimit de grootte van het spelbord in de Y richting
	 * @return ingegeven coordinaten
	 */
	Coordinates player(int, int);

	/*
	 * draw: verkorte functie om het bord te tekenen.
	 * Bespaard wat typwerk, en indien de implementatie veranderd moet het maar 1 keer aangepast worden.
	 */
	void draw() {
		battlefield.draw(myShips, board2.getHits(), board2.getMissiles(),
				board1.getHits(), board1.getMissiles());
	}

};

#endif /* GAME_H_ */
