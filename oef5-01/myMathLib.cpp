/*
 * myMathLib.cpp
 *
 *  Created on: 22-mrt.-2016
 *      Author: Matthijs
 */

#include <iostream>

using namespace std;

long double power(long double a, int b) {
	long double out = 1;
	if (b >= 0) {
		for (int i = 0; i < b; i++) {
			out *= a;
		}
	} else {
		for (int i = 0; i < -1 * b; i++) {
			out /= a;
		}
	}
	return(out);
}

long double abs(long double in) {
	if (in < 0) return -1 * in;
	return in;
}

long long fac(int n) {
	long long out = 1;
	for (int i = 1; i <= n; i++) {
		out *= i;
	}
	return out;
}

const float PI =  3.14159265358979;

long double sin(float in) {
	long double epsilon = 13515513;
	long double out = 0;
	int n = 0;
	do {
		epsilon = power(-1, n) * power(in, 2 * n + 1) / fac(2 * n + 1);
		cout << power(-1,n) << " " << power(in, 2 * n + 1) << " " << fac(2 * n + 1) << endl;
		out += epsilon;
		n++;
	} while (abs(epsilon) > power(10,-5)); // moest -8
	return out;
}

float cos(float in) {
	long double epsilon = 13515513;
	float out = 0;
	int n = 0;
	do {
		epsilon = power(-1, n) * power(in, 2 * n) / fac(2 * n);
		out += epsilon;
		n++;
	} while (abs(epsilon) > power(10,-5)); // moest -8
	return out;
}

float tan(float in) {
	return sin(in) / cos(in);
}

float degToRad(float in) {
	return in * PI / 180;
}

float radToDeg(float in) {
	return in * 180 / PI;
}
