#ifndef VECTOR_7_H_
#define VECTOR_7_H_

/*
 * vector_7.h
 * @author Matthijs Lasure
 * @date 2-jun.-2016
 */


#include <iostream>
#include <fstream>
using namespace std;


class Vector{
private:
	int s;
	int max;
	double* elementen;

public:
	Vector(int size);
	Vector(const Vector& v);

	void resize(int newmax);

	void push_back(double d);

	int size() const{return s;}
	~Vector(){delete[] elementen;}
	Vector& operator=(const Vector& a);

	void set(int n, double v){
		//Could be improved: no error handling
		elementen[n]=v;
	}
	double get(int n) const {
		//Could be improved: no error handling
		return elementen[n];
	}
};



#endif /* VECTOR_7_H_ */
