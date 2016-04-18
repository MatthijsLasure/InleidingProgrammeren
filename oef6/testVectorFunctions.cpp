/*
 * testVectorFunctions.cpp
 * @author Matthijs Lasure
 * @date 18-apr.-2016
 */

#include <iostream>
#include "myVectorFunctions.h"

using namespace std;

int main() {
	vector<int> test = {0, 1, 5, 6};
	string s = toString(test);
	cout << "String: " << s << endl;

	cout << "Sum: " << sum(test) << endl;

	mult(test, 5);

	cout << "Mult 5: " << toString(test) << endl;

	swap(test, 1, 3);
	cout << "Swap 1-3: " << toString(test) << endl;

	sort(test);

	cout << "Sort: " << toString(test) << endl;
	cout << "isSorted: " << isSorted(test) << endl;
	cout << "hasDuplicates: " << hasDuplicates(test) << endl;

	reverse(test);
	cout << "Reverse: " << toString(test) << endl;

	rotate(test);
	cout << "Rotate: " << toString(test) << endl;

	return(0);
}


