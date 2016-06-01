#ifndef SPELER_H_
#define SPELER_H_

/*
 * Speler.h
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <String>

#include "Kaartenboek.h"

class Speler {
public:
	Speler(std::string n, int l) :
			naam(n), leeftijd(l) {
	}

	std::string geefNaam() {
		return (naam);
	}
	int geefLeeftijd() {
		return (leeftijd);
	}

	Kaart trekKaart(Kaartenboek&);

	void nieuweOverwinning() {
		overwinningen++;
	}
	int geefOverwinningen() {
		return (overwinningen);
	}

	void nieuwVerlies() {
		verliezen++;
	}
	int geefVerliezen() {
		return (verliezen);
	}

	void printKaarten();

	void reset() {
		mijnKaarten.clear();
	}

private:
	std::string naam;
	int leeftijd;

	std::vector<Kaart> mijnKaarten;

	int overwinningen = 0;
	int verliezen = 0;

};

#endif /* SPELER_H_ */
