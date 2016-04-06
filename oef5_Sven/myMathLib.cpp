/*
 * 	Function defenitions for math library
 *	@Author Sven Arnouts
 *  @Date 22-mrt.-2016
 */

#include <iostream>

using namespace std;

double power( float a, int b) {
	double output = 1;
	if (b > 0) {
		for (float i = b; i > 0; i--) {
			output *= a;
		}
	}
	else {
		for (float i = -b; i > 0; i-- )
			output /= a;
	}
	return output;
}

const float PI = 3.14159265358979;

long double abs (long double a) {
	if (a < 0)
		return -1 * a;
	return a;
}

long double fac (int a) {
	long double output = 1;
	for (int i = a; i > 0; i--) {
		output *= i;
	}
	return output;
}

long double sin (float rad) {
	long double epsilon = 0;
	long double output = 0;
	int n = 0;
	do {
		epsilon = power(-1, n) * power(rad, 2 * n + 1) / fac (2 * n + 1);
		output += epsilon;
		n++;
		cout << power(-1, n) << "\t" << power(rad, 2 * n + 1) << "\t" << fac (2 * n + 1)
																<< "\t" << abs(epsilon) << endl;
	} while (abs(epsilon) > power (10, -5));
	return output;
}



