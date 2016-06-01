/*
 * Speler.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "Speler.h"

Kaart Speler::trekKaart(Kaartenboek& kb) {
	Kaart k = kb.trekKaart();
	mijnKaarten.push_back(k);
	return (k);
}

void Speler::printKaarten() {
	for (Kaart k : mijnKaarten) {
		std::cout << k << std::endl;
	}
}
