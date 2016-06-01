/*
 * Spel.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "Spel.h"

using namespace std;

Spel::Spel(Speler s1, Speler s2, int ar) : speler1(s1), speler2(s2), aantalRondes(ar) {
	Kaart k1;
	Kaart k2;

	for(int x = 0; x < aantalRondes; x++) {
		for (int ronde = 0; ronde < 26; ronde++) {
			k1 = speler1.trekKaart(kb);
			k2 = speler2.trekKaart(kb);

			if (k1 > k2){
				speler1.nieuweOverwinning();
				speler2.nieuwVerlies();
			} else if (k1 < k2) {
				speler1.nieuwVerlies();
				speler2.nieuweOverwinning();
			}
		}
		cout << "Speler 1: " << speler1.geefNaam() << " (" << speler1.geefLeeftijd() <<
				" jaar), " << speler1.geefOverwinningen() << " / " << speler1.geefVerliezen() << endl;
		speler1.printKaarten();
		cout << "Speler 2: " << speler2.geefNaam() << " (" << speler2.geefLeeftijd() <<
				" jaar), " << speler2.geefOverwinningen() << " / " << speler2.geefVerliezen() << endl;
		speler2.printKaarten();

		kb.reset();
		speler1.reset();
		speler2.reset();
	}

	if(speler1.geefOverwinningen() > speler2.geefOverwinningen())
		cout << "Speler 1: " << speler1.geefNaam() << " heeft gewonnen!" << endl;
	else
		cout << "Speler 2: " << speler2.geefNaam() << " heeft gewonnen!" << endl;

}

