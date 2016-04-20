/*
 * ZeeSlag.cpp
 * Hoofdbestand voor het spel: bevat main()
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

	// Arguments
	int difficulty = 3;

	bool doRepeat = false;
	do {
		// Initialisatie
		cout << "Klaar voor een spelletje zeeslag?" << endl;

		// initialize random seed
		srand(time(NULL));

		// config init
		vector<string> shipNames; // Namen
		vector<int> shipLengths; // Lengtes
		vector<int> shipCounts; // Aantal per type

		// Tijdelijke variabelen voor inlezen
		string tempName;
		int tempLength, tempCount;
		bool inputOK;

		// Limieten spelbord
		int xLimit, yLimit;

		// Vraag om config bestand
		cout << "Geef de naam van een configuratiebestand in: ";
		string configName = "";
		getline(cin, configName);

		// Probeer bestand te openen, print error indien niet
		ifstream config { configName.c_str() };
		if (!config) {
			cerr
					<< "Fout bij het lezen van het bestand. Start het programma opnieuw!"
					<< endl;
			return (1); // Stoppen
		}

		// Vraag moeilijkheidsgraad
		cout
				<< "Geef de moeilijksheidsgraad van de AI. Volgende opties zijn mogelijk:"
				<< endl;
		cout << "3: Volledig random" << endl;
		cout
				<< "2: Shiphunter: zal naar de rest van het schip zoeken bij een hit"
				<< endl;
		cout << "1: Checkerboard: zal in een dampatroon bombarderen" << endl;
		cout << "0: Hardcore: zelfde als modes 1 + 2." << endl;

		// IN
		cin >> difficulty;
		if (difficulty < 0 || difficulty > 3) { // Indien slechte input, zet op standaard
			cout << "Slechte input. Moeilijkheidsgraad is 3.";
			difficulty = 3;
		}

		// INLEZEN CONFIG
		cout << "Inlezen van de config..." << endl;

		string line;
		stringstream sline;
		int pos = 0;

		while (getline(config, line)) { // Zolang er ingelezen kan worden
			if (line[0] != '#') { // Indien het geen comment is
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
		} // einde WHILE

		// Print veldgrootte af ter controle
		cout << "Veldgrootte: " << xLimit << " x " << yLimit << endl;
		// Print alle schepen af
		for (int i = 0; i < shipNames.size(); i++) {
			cout << shipNames[i] << " " << shipLengths[i] << " "
					<< shipCounts[i] << endl;
		}

		// TODO config checken voor errors

		// Init classe
		cout << "Initialiseren van het spel..." << endl;
		Game zeeslag { xLimit, yLimit, difficulty }; // Maak het object aan

		// Inlezen
		cout << "Inlezen coordinaten..." << endl;
		int x, y; // Temp voor posities
		char dir; // Temp voor orientatie

		// Teken een leeg veld
		zeeslag.drawInit();

		// Player input
		if (true) {
			for (int i = 0; i < shipNames.size(); i++) { // Loop over alle schepen
				for (int j = 0; j < shipCounts[i]; j++) { // Loop over het aantal per schip
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

								} // End if checkClipped

							} else { // Van if checkBounds

								// Buiten grenzen
								cout
										<< "Het schip ligt niet binnen de grenzen. Probeer opnieuw."
										<< endl;
								inputOK = false;

							}
						} else { // Van if goede input
							// Slechte input
							cout
									<< "De gegevens zijn incorrect. Geef 2 gehele getallen en een 'h' of een 'v'."
									<< endl;
							cout << "X moet tussen 1 en " << xLimit
									<< " liggen, en Y tussen 1 en " << yLimit
									<< "." << endl;
						} // Einde IF goede input

					} while (!inputOK); // End Do inputOK

				} // End For Aantal

			} // End for schepen

		} else { // Rand
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
		for (int i = 0; i < shipNames.size(); i++) { // Voor alle schepen
			for (int j = 0; j < shipCounts[i]; j++) { // Voor alle per schip
				inputOK = false;
				// Loop tot er een juiste input is
				do { // Genereer random positie
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
				} while (!inputOK); // END DO inputOK
			} // End For aantal
		} // End For schepen

		// Start het spel!
		zeeslag.gameLoop();

		// Vraag of de speler nog eens wilt
		string repeat;
		cout << "Dit spel is afgelopen. Wil je nog eens spelen (y/j/ja//*): ";
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
