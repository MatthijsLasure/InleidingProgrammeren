/*
 * Coordinates.h
 *
 * Created on: 06 Apr 2016
 * Author: Glenn Daneels
 *
 * Class that holds a x and y coordinate.
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_

class Coordinates {
public:
	/**
	 * Constructor.
	 * @param x The initial x-coordinate.
	 * @param y The initial y-coordinate.
	 */
	Coordinates(const int& x, const int& y) : m_x(x), m_y(y) {}
	/**
	 * Getter for the x coordinate.
	 * @return The x coordinate.
	 */
	int getX() const { return m_x; }
	/**
	 * Getter for the y coordinate.
	 * @return The y coordinate.
	 */
	int getY() const { return m_y; }
	/**
	 * Setter for the X coordinate.
	 * @param x The x coordinate.
	 */
	void setX(const int& x) { m_x = x; }
	/**
	 * Setter for the Y coordinate.
	 * @param y The y coordinate.
	 */
	void setY(const int& y) { m_y = y; }
private:
	int m_x;
	int m_y;
};

#endif /* COORDINATES_H_ */
