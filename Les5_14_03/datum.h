/*
 * datum.h
 *
 *  Created on: Mar 14, 2016
 *      Author: uauser
 */

#ifndef DATUM_H_
#define DATUM_H_

class datum {
private:
	int dag;
	int maand;
	int jaar;

public:
	int getDag();
	int getMaand();
	int getJaar();
};



#endif /* DATUM_H_ */
