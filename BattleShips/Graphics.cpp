/*
 *  * Graphics.cpp
 *
 *  Created on: 07 Apr 2016
 *      Author: gdaneels
 */

#include <iostream>
#include <fstream>
#include "Graphics.h"

using namespace std;

/**
 * Constructor.
 */
Graphics::Graphics() {}

/**
 * Setter that sets the dimensions of the game board. Necessary for drawing the game board correctly.
 * @param width The width of the game board.
 * @param height The height of the game board.
 */
void Graphics::setDimensions(int width, int height) {
	m_width = width;
	m_height = height;
}

/**
 * Redraws the graphical battleships interfaces to the show.html file.
 * @param friendlyShips ALL the coordinates of all the human player's ships.
 * @param friendlyHits The coordinates of all hits caused by a bomb of the human player.
 * @param friendlyBombs The coordinates of all the bombs placed by the human player.
 * @param hostileHits The coordinates of all hits caused by a bomb of the AI player.
 * @param hostileBombs The coordinates of all the bombs placed by the AI player.
 */
void Graphics::draw(vector<Coordinates> friendlyShips, vector<Coordinates> friendlyBombs, vector<Coordinates> friendlyHits, vector<Coordinates> hostileHits, vector<Coordinates> hostileBombs) {
	ofstream output{"show.html"};
	if(!output) {
		cout << "Het output bestand kon niet geopend worden\n" << endl;
	} else {
		string refreshRate = "1000";

		output << "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\"><html><head><script src=\"battleships.js\"></script><link rel=\"stylesheet\" type=\"text/css\" href=\"battleships.css\"><title></title></head><body onload=\"checkForRefresh(" << refreshRate << ");\">" << endl;
		output << "<h1>Battleships</h1><div style=\"text-align: center\"><div style=\"display: inline-block;\"><input type=\"button\" value=\"Vernieuw 1 keer\" onClick=\"window.location.reload()\"><input type=\"button\" onclick=\"startRefresh(" << refreshRate << ")\" id=\"start\" value=\"Start automatisch vernieuwen\"><input type=\"button\" onclick=\"stopRefresh()\" id=\"stop\" value=\"Stop automatisch vernieuwen\"><br /><br />" << endl;
		// Draw the bombs table.
		output << "<table id=\"bombs\">" << endl;
		output << "<tr><td align=\"center\" colspan=\"" << m_width + 1 << "\"><b>Your Placed Bombs</b></td></tr><tr><td></td>" << endl;
		for (int x = 1; x <= m_width; x++)
			output << "<td>" << x << "</td>" << endl;
		output << "</tr>" << endl;
		for (int y = 1; y <= m_height; y++) {
			output << "<tr><td>" << y << "</td>" << endl;
			for (int x = 1; x <= m_width; x++) {
				bool isBombCell = false;
				bool isHitCell = false;
				for (auto bomb : friendlyBombs) {
					if (x == bomb.getX() && y == bomb.getY()) {
						isBombCell = true;
						for (auto hitCoord : friendlyHits) {
							if (x == hitCoord.getX() && y == hitCoord.getY()) {
								isHitCell = true;
								break;
							}
						}
						break;
					}
				}
				if (isBombCell && isHitCell)
					output <<  "<td id=\"bomb-hit\"><img id=\"bomb-image\"></td>" << endl;
				else if (isBombCell)
					output << "<td id=\"bomb\"><img id=\"bomb-image\"></td>" << endl;
				else
					output << "<td></td>" << endl;
			}
			output << "</tr>" << endl;
		}
		output << "</table>" << endl;

		output << "</td id=\"container\"><td>" << endl;

		// Draw the bombs table.
		output << "<table id=\"ships\">" << endl;
		output << "<tr><td align=\"center\" colspan=\"" << m_width + 1 << "\"><b>Your Ships and Hits</b></td></tr><tr><td></td>" << endl;
		for (int x = 1; x <= m_width; x++)
			output << "<td>" << x << "</td>" << endl;
		output << "</tr>" << endl;
		for (int y = 1; y <= m_height; y++) {
			output << "<tr><td>" << y << "</td>" << endl;
			for (int x = 1; x <= m_width; x++) {
				bool isShipCell = false;
				bool isHitCell = false;
				bool isBombCell = false;
				for (auto shipCoord : friendlyShips) {
					if (x == shipCoord.getX() && y == shipCoord.getY()) {
						isShipCell = true;
						for (auto hitCoord : hostileHits) {
							if (x == hitCoord.getX() && y == hitCoord.getY()) {
								isHitCell = true;
								break;
							}
						}
						break;
					}
				}
				for (auto bombCoord : hostileBombs) {
					if (x == bombCoord.getX() && y == bombCoord.getY()) {
						isBombCell = true;
						break;
					}
				}
				if (isShipCell && isHitCell)
					//output <<  "<td id=\"ship\"><img id=\"hit-image\" /></td>" << endl;
					output <<  "<td id=\"bomb-hit\"><img id=\"hit-image\" /></td>" << endl;
				else if (isShipCell)
					output << "<td id=\"ship\"></td>" << endl;
				else if (isBombCell)
					output << "<td id=\"bomb\"><img id=\"bomb-image\"></td>" << endl;
				else
					output << "<td></td>" << endl;
			}
			output << "</tr>" << endl;
		}
		output << "</table>" << endl;

		output << "</div></div>" << endl;
		output << "</body></html>" << endl;
	}
}



