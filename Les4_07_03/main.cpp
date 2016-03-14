/*
 * main.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: uauser
 */

#include <iostream>
using namespace std;

class Datum {
public:
	Datum(int d, int m, int j) { // Geen return waarde!
		dag = d;
		maand = m;
		jaar = j;
	}

//private:
	int dag, maand, jaar;
	bool isSchrikkeljaar(){
		return jaar % 4 == 0;
	}
};

int main() {
	Datum d{1,2,3};
	d.dag = 5;
	d.maand = 3;
	d.jaar = 2016;
	cout << d.isSchrikkeljaar();
}
