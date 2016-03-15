/*
 * oef4.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */


#include <iostream>
#include <string>

using namespace std;

void omkeren(string& in) {
	string out = in;
	for (int i = in.length() - 1; i >= 0; i--) {
		out[in.length() - i - 1] = in[i];
	}
	in = out;
}

string omkeren2(string in) {
	string out = in;
	for (int i = in.length() - 1; i >= 0; i--) {
		out[in.length() - i - 1] = in[i];
	}
	return out;
}

bool palindroom(string& a) {
	string b = omkeren2(a);
	return a == b;
}

int main() {
	string input; // = "Appelflauwte";
	cout << "String ingeven? ";
	cin >> input;
	string output1 = input;
	omkeren(output1);
	cout << output1 << endl;
	string output2 = omkeren2(input);
	cout << output2 << endl;

	bool isPalin = palindroom(input);
	cout << "Palindroom: " << isPalin << endl;

}

