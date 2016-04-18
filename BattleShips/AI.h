#ifndef AI_H_
#define AI_H_

/*
 * AI.h
 * @author Matthijs Lasure
 * @date 15-apr.-2016
 */

#include <vector>
#include "Coordinates.h"
#include "GameBoard.h"
//#include "Game.h"

using namespace std;

class AI {
public:
	AI();

	void init(int, int, int);

	Coordinates getMove(GameBoard board);

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
	 * 1: schip geraakt, zoeken #1
	 * 2: zoeken #2
	 * 3: zoeken #3
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
	int xLimit, yLimit;

	Coordinates lastHit{0, 0};
	Coordinates firstHit{0, 0};

	vector<Coordinates> checkers;
};




#endif /* AI_H_ */
