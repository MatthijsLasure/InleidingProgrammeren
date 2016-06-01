#ifndef KAARTENBOEK_H_
#define KAARTENBOEK_H_

/*
 * KaartenBoek.h
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <vector>
#include "Kaart.h"

class Kaartenboek {
public:
	Kaartenboek();

	Kaart trekKaart();

	void schudKaarten();

	int geefAantal() {
		return (mijnKaarten.size() - getrokkenKaarten.size());
	}

	void reset();

private:
	std::vector<Kaart> mijnKaarten;
	std::vector<Kaart> getrokkenKaarten;
};

#endif /* KAARTENBOEK_H_ */
