/*
 * AI.cpp
 * Bevat de logica van de AI; heeft functies voor initialisatie, genereren van een stap en analyseren van deze stap
 * @author Matthijs Lasure
 * @date 15-apr.-2016
 */

#include "AI.h"
#include "GameBoard.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Constructor
 */
AI::AI() {
}
;

/*
 * init: initieer de AI
 * @param diffi Moeilijkheidsgraad AI
 * @param xL Grootte van het bord, x richting
 * @param yL Grootte van het bord, y richting
 */
void AI::init(int diffi, int xL, int yL) {
	difficulty = diffi;
	xLimit = xL;
	yLimit = yL;

	// Maak de checkers matrix indien gevraagd, zie ook de header
	if (difficulty <= 1) {
		// Vul de checkers matrix
		bool value = false;
		bool colInit = false;

		// Bepaal of het eerste vakje in het patroon ligt.
		if (rand() % 100 + 1 > 50)
			colInit = true;

		// Loop over alle kolommen
		for (int i = 0; i < xLimit; i++) {
			if (colInit) {
				colInit = false;
				value = true;
			} else {
				colInit = true;
				value = false;
			}
			for (int j = 0; j < yLimit; j++) { // Loop over alle rijen
				if (value) { // Indien in het patroon, voeg de vector toe
					checkers.push_back(Coordinates { i + 1, j + 1 });
					value = false;
				} else
					value = true;
			}
		}
	} // Einde checkers matrix init

	// Stel de juiste modus in
	if (difficulty >= 2) {
		mode = 6; // Random hunt
		defmode = 6; // Standaard rollback mode
	} else {
		mode = 0; // Checkers
		defmode = 0;
	}
}

/*
 * getMove: vraag de AI om een locatie om te bombarderen.
 * @param board Het spelbord waarop gebombardeerd moet worden.
 */
Coordinates AI::getMove(GameBoard board) {
	// Antwoord
	Coordinates answer { 0, 0 };
	// Vector met beschikbare plaatsen, zie verder
	vector < Coordinates > avail;
	/*
	 * r: willekeurig getal
	 * x, y: willekeurige coordinaten
	 */
	int r, x, y;

	// Onderneem actie afhankelijk van de mode
	switch (mode) {
	case 0: // Niets geraakt, vuur in checkerboard patroon

		// Verwijder alle locaties in het patroon waar niet meer gebombardeerd kan worden.
		checkers.erase(
				// Erase: verwijder de coords op het einde
				remove_if(
						// Zet alle coords op het einde die niet voldoen aan de functie
						checkers.begin(), checkers.end(),
						[&board](const Coordinates & o) {return (board.checkMissile(o));}),
				checkers.end());

		// Als er nog locaties zijn in het patroon, doe dan voort
		if (checkers.size() > 0) {
			// Pak een willekeurige locatie, en check nog eens of er gebombardeerd mag worden
			r = rand() % checkers.size();
			answer = checkers[r];
		} else { // Geen plek meer over, bombardeer random. Zie ook case 6
			// Zet de mode op 6, aangezien er niet meer in een patroon gebombardeerd kan worden
			defmode = 6;
			mode = 6;
			do { // Blijf random locaties genereren tot er een goede tussen zit.
				x = rand() % xLimit + 1;
				y = rand() % yLimit + 1;

				answer = Coordinates { x, y };

			} while (board.checkMissile(answer));
		}
		break;
	case 1: // Er is geraakt, vuur in de omgeving

		// Stel een lijst op met de beschikbare plaatsen waar geschoten kan worden.
		for (int i = -1; i <= 1; i += 2) {
			// West en East
			answer = Coordinates { i + firstHit.getX(), firstHit.getY() };
			if (!board.checkMissile(answer))
				avail.push_back(answer);

			// South en North
			answer = Coordinates { firstHit.getX(), i + firstHit.getY() };
			if (!board.checkMissile(answer))
				avail.push_back(answer);
		} // Einde opstellen avail

		// Als er locaties beschikbaar zijn, pak er dan 1
		if (avail.size() > 0) {

			answer = avail[rand() % avail.size()];

			// Extraheer de zoekrichting
			x = answer.getX() - firstHit.getX();
			y = answer.getY() - firstHit.getY();

			// Slaag de zoekrichting op
			if (x == -1)
				zoekrichting = 3; // West
			else if (x == 1)
				zoekrichting = 1; // East
			else if (y == -1)
				zoekrichting = 0; // North
			else
				zoekrichting = 2; // South

		} else { // Geen plaats beschikbaar, bombardeer willekeurig
			// Zet de mode terug op standaard
			mode = defmode;
			do {
				x = rand() % xLimit + 1;
				y = rand() % yLimit + 1;

				answer = Coordinates { x, y };

			} while (board.checkMissile(answer));
		} // Einde IF AVAIL.SIZE
		break; // Einde case 1

	case 4: // Een zoekrichting is bekend uit 1, bombardeer nu in die richting
		// Vertrek van de vorige hit
		answer = lastHit;

		// Bepaal de correcte locatie adhv de zoekrichting
		switch (zoekrichting) {
		case 0: // North
			answer.setY(lastHit.getY() - 1);
			break;
		case 1: // East
			answer.setX(lastHit.getX() + 1);
			break;
		case 2: // South
			answer.setY(lastHit.getY() + 1);
			break;
		case 3: // West
			answer.setX(lastHit.getX() - 1);
			break;
		} // Einde switch zoekrichting

		// Als er niet gebombardeerd kan worden (Out of Bounds, al gevuurd), naar mode 5
		if (!board.checkMissile(answer)) // Check legit, anders andere kant
			break; // Er kan gevuurd worden, break uit de switch
		else { // Er kan niet gevuurd worden
			   // Switch mode en zoekrichting
			mode = 5;
			if (zoekrichting > 1)
				zoekrichting -= 2;
			else
				zoekrichting += 2;
			lastHit = firstHit;
		}
		// Geen break: ga verder naar mode 5
	case 5: // De andere zoekrichting is gefaald, draai om en doe verder
		// Vertrek van de vorige hit
		answer = lastHit;

		// Bepaal de correcte locatie adhv de zoekrichting
		switch (zoekrichting) {
		case 0: // North
			answer.setY(lastHit.getY() - 1);
			break;
		case 1: // East
			answer.setX(lastHit.getX() + 1);
			break;
		case 2: // South
			answer.setY(lastHit.getY() + 1);
			break;
		case 3: // West
			answer.setX(lastHit.getX() - 1);
			break;
		} // Einde switch zoekrichting

		// Indien er niet gevuurd kan worden, ga terug naar standaard, na 1 random schot
		if (!board.checkMissile(answer))
			break; // Indien ok, break en return het antwoord
		else { // Indien niet legit, blijf in de switch, en ga naar 6
			   // Zet de mode terug op standaard
			mode = defmode;
		}
	case 6: // Volledig willekeurig schieten
		// Do zolang de locatie niet legaal is
		do {
			// Genereer een random plaats
			x = rand() % xLimit + 1;
			y = rand() % yLimit + 1;

			answer = Coordinates { x, y };

		} while (board.checkMissile(answer));

	} // Einde switch mode

	// Geef het antwoord terug.
	return (answer);
}

/*
 * hasHit: verwerkt de feedback, gegeven door het spel, en bepaald daarmee de acties in de volgende ronde(s)
 * @param hit De coordinaten van het laatste schot
 * @param severity Het resultaat van het schot. 0 = mis, 1 = hit, 2 = gezonken
 */
void AI::hasHit(Coordinates hit, int severity) {
	// Indien iets geraakt is, zet de laatste hit op de huidige hit
	if (severity > 0)
		lastHit = hit;

	// Indien er alleen maar op checkerboard of full random gebombardeerd wordt, moet de AI niets doen
	if (difficulty == 2 || difficulty == 0) {
		// Acties afhankelijk van de huide mode
		switch (mode) {
		case 0: // Niet op jacht, onderneem actie
		case 6:
			if (severity == 1) { // Alleen een hit > ga naar hunting node
				mode = 1;
				firstHit = hit;
			}
			// Ineens gezonken, blijf dan in deze mode
			// Indien gemist, doe niets
			break; // We zijn hier klaar
		case 1: // Er is een schip geraakt en er is al minstens 1 keer gevuurd in de omgeving
			if (severity == 1) // Een tweede hit, dus we weten de oriëntatie van het schip. Ga naar mode 4
				mode = 4;
			else if (severity == 2) // Het schip is gezonken. Schakel terug naar standaard modus
				mode = defmode;
			break;

		case 4: // Schieten op de rest vh schip, deel 1
			if (severity == 0) { // Gemist, dus schiet in de andere richting
				mode = 5;
				lastHit = firstHit;
				if (zoekrichting > 1)
					zoekrichting -= 2;
				else
					zoekrichting += 2;
			} else if (severity == 2)
				mode = defmode;
			break;

		case 5: // Schieten op de rest vh schip, deel 2
			if (severity == 2 || severity == 0) // Indien gezonken: we zijn hier klaar
			// Indien gemist: iets is niet ok. Eg met meerdere schepen tegen elkaar. Terugvallen naar standaard
				mode = defmode;
			break;
		}
	}
}
