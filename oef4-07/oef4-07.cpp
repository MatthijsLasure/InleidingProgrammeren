/*
 * oef4-07.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: uauser
 */

#include <iostream>
#include <string>

using namespace std;

void encode(string& in) {
	string temp = in;
	for (int i = 0; i < in.length(); i++) {
		temp[i] = in[i] + 3;
	}
	in = temp;
}

void encode2(string& in) {
	string temp = in;
	for(int i = 0; i < in.length(); i++) {
		temp[i] = in[i] + 3;
		if( temp[i] > 'z') temp[i] -= 26;
		else if(temp[i] > 'Z') temp[i] -= 26;
	}
	in = temp;
}
void decode2(string& in) {
	string temp = in;
	for(int i = 0; i < in.length(); i++) {
		temp[i] = in[i] - 3;
		if( temp[i] < 'A') temp[i] += 26;
		else if(temp[i] < 'a') temp[i] += 26;
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
	string input;

	cout << "Geef een tekst? ";
	//cin >> input;
	getline(cin, input);
	//input = heyo;
	encode2(input);
	cout << "Encoded: " << input << endl;
	decode2(input);
	cout << "Decoded: " << input << endl;
}
