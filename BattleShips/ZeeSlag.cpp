/*
 * ZeeSlag.cpp
 * @author Matthijs Lasure
 * @date 12-apr.-2016
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <time.h>

#include "Coordinates.h"
#include "Ship.h"
#include "Game.h"

using namespace std;

int main() {
	// Initialisatie
	cout << "Klaar voor een spelletje zeeslag?\n(C) Matthijs Lasure" << endl;

	// initialize random seed
	srand(time(NULL));

	// Arguments
	int difficulty = 3;

	// config init
	vector<string> shipNames;
	vector<int> shipLengths;
	vector<int> shipCounts;
	string tempName;
	int tempLength, tempCount;
	int xLimit, yLimit;
	bool inputOK;

	cout << "Geef de naam van een configuratiebestand in: ";
	string configName = "";

	getline(cin, configName);
	cout << configName << endl;
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	ifstream config { configName.c_str() };
	if (!config) {
		cout << "Error reading config! Check filename and access." << endl;
		return (1);
	}

	cout
			<< "Geef de moeilijksheidsgraad van de AI. Volgende opties zijn mogelijk:"
			<< endl;
	cout << "3: Volledig random" << endl;
	cout << "2: Shiphunter: zal naar de rest van het schip zoeken bij een hit"
			<< endl;
	cout << "1: Checkerboard: zal in een dampatroon bombarderen" << endl;
	cout << "0: Hardcore: zelfde als modes 1 + 2." << endl;

	cin >> difficulty;
	if (difficulty < 0 || difficulty > 3) {
		cout << "Slechte input. Moeilijkheidsgraad is 3";
		difficulty = 3;
	}
	cout << "Moeilijkheidsgraad AI (3 easy --> 0 hard): " << difficulty << endl;

	// config lezen
	cout << "Inlezen van de config..." << endl;

	string line;
	stringstream sline;
	int pos = 0;

	while (getline(config, line)) {
		if (line[0] != '#') {
			pos++;
			sline << line << endl;
			if (pos == 1) {
				sline >> xLimit >> yLimit;
			} else {
				sline >> tempName >> tempLength >> tempCount;
				shipNames.push_back(tempName);
				shipLengths.push_back(tempLength);
				shipCounts.push_back(tempCount);
			}
		}
	}
	cout << "Veldgrootte: " << xLimit << " x " << yLimit << endl;
	for (int i = 0; i < shipNames.size(); i++) {
		cout << shipNames[i] << " " << shipLengths[i] << " " << shipCounts[i]
				<< endl;
	}

	// TODO config checken voor errors

	// Init classe
	bool doRepeat = false;
	do {
		cout << "Initialiseren van het spel..." << endl;
		Game zeeslag { xLimit, yLimit, difficulty };

		// Inlezen
		cout << "Inlezen coordinaten..." << endl;
		int x, y;
		char dir;

		zeeslag.drawInit();

		// Player
		if (false) {
			for (int i = 0; i < shipNames.size(); i++) {
				for (int j = 0; j < shipCounts[i]; j++) {
					inputOK = false;
					// Loop tot er een juiste input is
					do {
						// Vraag
						cout << "Geef de positie van een " << shipNames[i]
								<< "(lengte " << shipLengths[i]
								<< ") (X Y dir): ";

						// Antwoord
						cin >> x >> y >> dir;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						if (dir == 'H')
							dir = 'h';
						else if (dir == 'V')
							dir = 'v';

						Coordinates input { x, y }; // Process

						// Check de input
						if (x > 0 && x <= xLimit && y > 0 && y <= yLimit
								&& (dir == 'h' || dir == 'v')) {
							// Input is OK, check of het schip niet buiten de grenzen valt
							if (zeeslag.checkBounds(input, shipLengths[i],
									dir)) {
								// Binnen grenzen, check of er geen conflict is
								if (zeeslag.checkClipped(1, input,
										shipLengths[i], dir)) {
									// Zal botsen, dus opnieuw vragen
									cout
											<< "Daar ligt al een schip. Probeer opnieuw."
											<< endl;
									inputOK = false;
								} else {
									// Geen problemen, dus voeg het schip toe.
									zeeslag.addShip(1, input, shipLengths[i],
											dir, shipNames[i]);
									zeeslag.drawInit();
									inputOK = true;
								}
							} else {
								// Buiten grenzen
								cout
										<< "Het schip ligt niet binnen de grenzen. Probeer opnieuw."
										<< endl;
								inputOK = false;
							}
						} else {
							// Slechte input
							cout
									<< "De gegevens zijn incorrect. Geef 2 gehele getallen en een 'h' of een 'v'."
									<< endl;
							cout << "X moet tussen 1 en " << xLimit
									<< " liggen, en Y tussen 1 en " << yLimit
									<< "." << endl;
						}
					} while (!inputOK);
				}
			}
		} else {
			for (int i = 0; i < shipNames.size(); i++) {
				for (int j = 0; j < shipCounts[i]; j++) {
					inputOK = false;
					// Loop tot er een juiste input is
					do {
						x = rand() % xLimit + 1;
						y = rand() % yLimit + 1;
						if (rand() % 100 < 50)
							dir = 'h';
						else
							dir = 'v';

						Coordinates input { x, y }; // Process

						// Check de input
						if (x > 0 && x <= xLimit && y > 0 && y <= yLimit
								&& (dir == 'h' || dir == 'v')) {
							// Input is OK, check of het schip niet buiten de grenzen valt
							if (zeeslag.checkBounds(input, shipLengths[i],
									dir)) {
								// Binnen grenzen, check of er geen conflict is
								if (zeeslag.checkClipped(1, input,
										shipLengths[i], dir)) {
									// Zal botsen, dus opnieuw vragen
									inputOK = false;
								} else {
									// Geen problemen, dus voeg het schip toe.
									zeeslag.addShip(1, input, shipLengths[i],
											dir, shipNames[i]);
									inputOK = true;
								}
							} else {
								// Buiten grenzen
								inputOK = false;
							}
						} else {
							// Slechte input
							inputOK = false;
						}
					} while (!inputOK);
				}
			}
		}

		// AI
		for (int i = 0; i < shipNames.size(); i++) {
			for (int j = 0; j < shipCounts[i]; j++) {
				inputOK = false;
				// Loop tot er een juiste input is
				do {
					x = rand() % xLimit + 1;
					y = rand() % yLimit + 1;
					if (rand() % 100 < 50)
						dir = 'h';
					else
						dir = 'v';

					Coordinates input { x, y }; // Process

					// Check de input
					if (x > 0 && x <= xLimit && y > 0 && y <= yLimit
							&& (dir == 'h' || dir == 'v')) {
						// Input is OK, check of het schip niet buiten de grenzen valt
						if (zeeslag.checkBounds(input, shipLengths[i], dir)) {
							// Binnen grenzen, check of er geen conflict is
							if (zeeslag.checkClipped(2, input, shipLengths[i],
									dir)) {
								// Zal botsen, dus opnieuw vragen
								inputOK = false;
							} else {
								// Geen problemen, dus voeg het schip toe.
								zeeslag.addShip(2, input, shipLengths[i], dir,
										shipNames[i]);
								inputOK = true;
							}
						} else {
							// Buiten grenzen
							inputOK = false;
						}
					} else {
						// Slechte input
						inputOK = false;
					}
				} while (!inputOK);
			}
		}

		// Start het spel!
		zeeslag.gameLoop();

		string repeat;
		cout << "Dit spel is afgelopen. Wil je nog eens spelen (y/j/ja voor ja, anders nee): ";
		cin >> repeat;
		if (repeat == "y" || repeat == "j" || repeat == "ja")
			doRepeat = true;
		else
			doRepeat = false;
	} while (doRepeat);

	// Terminatie van het programma
	cout << "Programma is afgelopen. Tot de volgende keer!" << endl;
	return (0);
}

