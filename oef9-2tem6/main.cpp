/*
 * main.cpp
 * @author Matthijs Lasure
 * @date 2-jun.-2016
 */


#include <iostream>
#include <fstream>
#include "vector_7.h"

using namespace std;

int main() {
//	Vector v{5};
//	Vector v2{5};
//	v.set(0,100);
//	v2 = v;
//	cout << v2.get(0);
//	v2.set(0,10);
//	cout << v.get(0) << "  " << v2.get(0);

	Vector vec1{5};
	Vector vec2{vec1};
	Vector vec3{20};

	vec3 = vec2;

	cout << vec3.size();

	vec1.resize(100);

	cout << endl;

	int size, def;
	cout << "Geef grootte & standaardwaarde: ";
	cin >> size >> def;

	int *ar = new int[size];
	for (int i = 0; i < size; i++) {
		ar[i] = def;
	}

	for(int i = 0; i < size; i++) {
		cout << &ar[i] << "\t" << ar[i] << endl;
	}

	delete[] ar;
}



