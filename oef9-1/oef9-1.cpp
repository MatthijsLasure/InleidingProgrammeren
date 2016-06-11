/*
 * oef9-1.cpp
 * @author Matthijs Lasure
 * @date 2-jun.-2016
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using namespace std;

int main() {

	// Rand
	std::random_device r;


	std::default_random_engine e1(r());
	std::uniform_real_distribution<float> uni(0,1);

	float vx, vy;

	int x = 1000000;
	int hits = 0;

	for(int i = 0; i < x; i++) {
		vx = uni(e1);
		vy = uni(e1);
		if(vx*vx + vy*vy < 1) hits++;
	}

	float pi = 4 * (float) hits / (float) x;
	cout << "Pi: " << pi << endl;

	return(0);
}

