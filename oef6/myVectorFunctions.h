#ifndef MYVECTORFUNCTIONS_H_
#define MYVECTORFUNCTIONS_H_

/*
 * myVectorFunctions.h
 * @author Matthijs Lasure
 * @date 18-apr.-2016
 */

#include <vector>
#include <string>

using namespace std;

string toString(vector<int>&);

int sum(vector<int>&);

int max(vector<int>&);

void mult(vector<int>&, int);

void swap(vector<int>&, int, int);

void sort(vector<int>&);

bool isSorted(vector<int>&);

bool hasDuplicates(vector<int>&);

void reverse(vector<int>&);

void rotate(vector<int>&);


#endif /* MYVECTORFUNCTIONS_H_ */
