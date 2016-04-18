/*
 * myVectorFunctions.cpp
 * @author Matthijs Lasure
 * @date 18-apr.-2016
 */

#include <vector>
#include <string>
#include "myVectorFunctions.h"

using namespace std;

string toString(vector<int> &a) {
	string out = "";
	bool isFirst = true;
	for (int elem : a) {
		if (! isFirst) out += ", ";
		else isFirst = false;

		out += to_string(elem);
	}
	return(out);
}

int sum(vector<int> &a) {
	int total = 0;
	for (int elem : a) {
		total += elem;
	}
	return (total);
}

void mult(vector<int> &a, int b) {
	for (int &elem : a) {
		elem *= b;
	}
}

void swap(vector<int> &a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void sort(vector<int> &a) {
	int last = a.size();
	for (int l = last; l > 0; l--) {
		for (int i = 1; i < l; i++) {
			if (a[i] < a[i-1]) swap(a, i, i-1);
		}
	}
}

bool isSorted(vector<int> &a) {
	for(int i = 1; i < a.size(); i++)
		if (a[i] < a[i-1]) return(false);

	return(true);
}

bool hasDuplicates(vector<int> &a) {
	int value = 0;
	for (int i = 0; i < a.size(); i++) {
		value = a[i];
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] == value) return(true);
		}
	}
	return(false);
}

void reverse(vector<int> &a) {
	int temp = 0;
	for (int i = 0; i < a.size() / 2; i++) {
		temp = a[i];
		a[i] = a[a.size() - i - 1];
		a[a.size() - i - 1] = temp;
	}
}

void rotate(vector<int> &a) {
	a.insert(a.begin(), a[a.size()-1]);
	a.pop_back();
}
