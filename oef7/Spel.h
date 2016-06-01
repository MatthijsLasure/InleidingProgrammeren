#ifndef SPEL_H_
#define SPEL_H_

/*
 * Spel.h
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "Kaart.h"
#include "Kaartenboek.h"
#include "Speler.h"


class Spel {
public:
	Spel(Speler, Speler, int);

private:
	Kaartenboek kb;

	Speler speler1{"Smith",0};
	Speler speler2{"Smith",0};

	int aantalRondes;
};

#endif /* SPEL_H_ */
