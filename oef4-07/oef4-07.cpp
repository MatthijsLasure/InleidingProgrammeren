/*
 * oef4-07.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */

#include <iostream>

using namespace std;

void encode(string& in) {
	string temp = in;
	for (int i = 0; i < in.length(); i++) {
		temp[i] = in[i] + 3;
	}
	in = temp;
}

void decode(string& in) {
	string temp = in;
	for (int i = 0; i < in.length(); i++) {
		temp[i] = (char) ( (int) in[i] - 3);
	}
	in = temp;
}

int main() {
	char heyo[10000];
	string input;

	cout << "Geef een tekst? ";
	//cin >> input;
	getline(cin, input);
	//input = heyo;
	encode(input);
	cout << "Encoded: " << input << endl;
	decode(input);
	cout << "Decoded: " << input << endl;
}
