#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

/*
 * GameBoard.h
 * @author Matthijs Lasure
 * @date 13-apr.-2016
 */

#include <vector>
#include "Ship.h"
#include "Coordinates.h"

class GameBoard {
public:

private:
	vector<Ship> myShips;
	vector<Coordinates> myMissiles;
};




#endif /* GAMEBOARD_H_ */
