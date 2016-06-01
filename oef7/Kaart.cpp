/*
 * Kaart.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "Kaart.h"

bool operator==(const Kaart& a, const Kaart& b) {
	return (a.waarde() == b.waarde() && a.type() == b.type());
}
bool operator<(const Kaart& a, const Kaart& b) {
	int wa = (int) a.waarde();
	int wb = (int) b.waarde();
	int ta = (int) a.type();
	int tb = (int) b.type();
	return (wa < wb || (wa == wb && ta > tb));
}
bool operator>(const Kaart& a, const Kaart& b) {
	return (!(a == b || a < b));
}

std::ostream& operator<<(std::ostream& o, const Kaart& a) {
	return (o << a.toString());
}

int Kaart::wieWint(Kaart k) const {
	if (*this == k)
		return (0);
	else if (*this < k)
		return (-1);
	else
		return (1);
}

std::string Kaart::toString() const {
	std::vector<std::string> t_namen = { "Harten", "Ruiten", "Schoppen",
			"Klaveren" };
	std::vector<std::string> w_namen = { "", "Aas", "Twee", "Drie", "Vier",
			"Vijf", "Zes", "Zeven", "Acht", "Negen", "Tien", "Boer", "Dame",
			"Heer" };
	return (t_namen[(int) t] + " " + w_namen[(int) w]);
}

