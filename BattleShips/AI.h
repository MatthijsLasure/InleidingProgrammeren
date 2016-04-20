#ifndef AI_H_
#define AI_H_

/*
 * AI.h
 * Bevat de logica van de AI; heeft functies voor initialisatie, genereren van een stap en analyseren van deze stap
 * @author Matthijs Lasure
 * @date 15-apr.-2016
 */

#include <vector>
#include "Coordinates.h"
#include "GameBoard.h"

using namespace std;

class AI {
public:
	/*
	 * Constructor
	 */
	AI();

	/*
	 * init: initieer de AI
	 * @param diffi Moeilijkheidsgraad AI
	 * @param xL Grootte van het bord, x richting
	 * @param yL Grootte van het bord, y richting
	 */
	void init(int, int, int);

	/*
	 * getMove: vraag de AI om een locatie om te bombarderen.
	 * @param board Het spelbord waarop gebombardeerd moet worden.
	 */
	Coordinates getMove(GameBoard board);

	/*
	 * hasHit: verwerkt de feedback, gegeven door het spel, en bepaald daarmee de acties in de volgende ronde(s)
	 * @param hit De coordinaten van het laatste schot
	 * @param severity Het resultaat van het schot. 0 = mis, 1 = hit, 2 = gezonken
	 */
	void hasHit(Coordinates, int);

private:
	/*
	 * Moeilijkheidsgraad vd AI
	 * DEFCON 0: checkerboard + shipfinder
	 * DEFCON 1: checkerboard strat
	 * DEFCON 2: Shipfinder
	 * DEFCON 3: Full Random
	 */
	int difficulty = 0;

	/*
	 * De status van de AI
	 * 0: niet op jacht, op zoek naar schepen
	 * 1: schip geraakt, zoeken
	 * 2: zoeken #2 # BUITEN GEBRUIK
	 * 3: zoeken #3 # BUITEN GEBRUIK
	 * 4: volgen van een schip, richting 1
	 * 5: volgen van een schip, richting 2
	 * 6: op zoek naar schepen, niet volgens patroon
	 */
	int mode = 0;

	int defmode = 0; // Standaard modus

	/*
	 * De zoekrichting bij de jacht
	 * 0 N
	 * 1 E
	 * 2 S
	 * 3 W
	 */
	int zoekrichting = 0;

	// Limieten van het spelbord
	int xLimit, yLimit;

	// Intern nodige coordinaten voor opslag laatste hit
	Coordinates lastHit { 0, 0 };
	Coordinates firstHit { 0, 0 }; // Eerste hit op een schip

	// Opslag dambordpatroon
	vector<Coordinates> checkers;
};

#endif /* AI_H_ */
