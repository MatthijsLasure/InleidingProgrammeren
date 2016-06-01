/*
 * main.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <iostream>
#include <String>
#include <time.h>

#include "Kaartenboek.h"
#include "Spel.h"

using namespace std;

int main() {

	srand(time(NULL));
	int rondes = 0;

	string naam1;
	string naam2;
	int leeftijd1;
	int leeftijd2;

	cout << "Aantal ronden? ";
	cin >> rondes;

	cout << "Naam & leeftijd speler 1: ";
	cin >> naam1 >> leeftijd1;

	cout << "Naam & leeftijd speler 2: ";
		cin >> naam2 >> leeftijd2;

	Speler s1{naam1, leeftijd1};
	Speler s2{naam2, leeftijd2};

	Spel mijnSpel{s1, s2, rondes};

	return 0;
}

