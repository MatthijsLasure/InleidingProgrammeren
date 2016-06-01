#ifndef KAART_H_
#define KAART_H_

/*
 * Kaart.h
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <iostream>
#include <vector>

enum class KaartType {
	Harten, Ruiten, Schoppen, Klaveren
};

enum class KaartWaarde {
	Aas = 1,
	Twee,
	Drie,
	Vier,
	Vijf,
	Zes,
	Zeven,
	Acht,
	Negen,
	Tien,
	Boer,
	Dame,
	Heer
};

class Kaart {
public:
	// Constructors
	Kaart() :
			t { KaartType::Harten }, w { KaartWaarde::Aas } {
	}
	Kaart(KaartType type, KaartWaarde waarde) :
			t(type), w(waarde) {
	}

	// Getters
	KaartType type() const {
		return (t);
	}
	KaartWaarde waarde() const {
		return (w);
	}

	// Setters
	void type(KaartType type) {
		t = type;
	}
	void waarde(KaartWaarde waarde) {
		w = waarde;
	}

	// Misc
	std::string toString() const;
	int wieWint(Kaart k) const;

private:
	KaartType t;
	KaartWaarde w;
};

// Operators
bool operator==(const Kaart&, const Kaart&);
bool operator<(const Kaart&, const Kaart&);
bool operator>(const Kaart&, const Kaart&);
std::ostream& operator<<(std::ostream&, const Kaart&);

#endif /* KAART_H_ */
