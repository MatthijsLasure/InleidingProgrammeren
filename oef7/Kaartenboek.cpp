/*
 * KaartenBoek.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "Kaartenboek.h"

#include <vector>

Kaartenboek::Kaartenboek() {
	mijnKaarten.reserve(52);
	getrokkenKaarten.reserve(52);

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			mijnKaarten.push_back(Kaart { KaartType(i), KaartWaarde(j) });
		}
	}
}

Kaart Kaartenboek::trekKaart() {
	int r = rand() % geefAantal() + 1;
	Kaart k = mijnKaarten[r];
	std::swap(mijnKaarten[r], mijnKaarten.back());
	getrokkenKaarten.push_back(k);
	return (k);
}

void Kaartenboek::schudKaarten() {
	int j = 0;
	for (int i = mijnKaarten.size() - 1; i > 0; i--) {
		j = rand() % i;
		std::swap(mijnKaarten[i], mijnKaarten[j]);
	}
}

void Kaartenboek::reset() {
	getrokkenKaarten.clear();
	schudKaarten();
}
