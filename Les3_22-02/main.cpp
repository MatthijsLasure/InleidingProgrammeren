/*
 * main.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: uauser
 */


#include <iostream>
#include <vector>

using namespace std;


int main() {

	cerr << "hlol\n";

	vector<int> getallen = { 0, 1, 2, 3};

	cout << getallen.size() << flush;

	for(int i = 0; i < getallen.size(); i++) {
		cout << getallen[i] << " ";
	}
	cout << endl;

	return 0;
}

