/*
 * Graphics.h
 *
 *  Created on: 07 Apr 2016
 *  Author: Glenn Daneels
 *
 * Class that draws a graphical representation of the battleships game.
 * It writes the graphical (html) output to the show.html file.
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <vector>
#include "Coordinates.h"

using namespace std;

class Graphics {
public:
	/**
	 * Constructor.
	 */
	Graphics();
	/**
	 * Setter that sets the dimensions of the game board. Necessary for drawing the game board correctly.
	 * @param width The width of the game board.
	 * @param height The height of the game board.
	 */
	void setDimensions(const int& width, const int& height);
	/**
	 * Redraws the graphical battleships interfaces to the show.html file.
	 * @param friendlyShips ALL the coordinates of all the human player's ships.
	 * @param friendlyHits The coordinates of all hits caused by a bomb of the human player.
	 * @param friendlyBombs The coordinates of all the bombs placed by the human player.
	 * @param hostileHits The coordinates of all hits caused by a bomb of the AI player.
	 * @param hostileBombs The coordinates of all the bombs placed by the AI player.
	 */
	void draw(const vector<Coordinates>& friendlyShips, const vector<Coordinates>& friendlyHits, const vector<Coordinates>& friendlyBombs, const vector<Coordinates>& hostileHits, const vector<Coordinates>& hostileBombs);
private:
	int m_width;
	int m_height;
};

#endif /* GRAPHICS_H_ */
