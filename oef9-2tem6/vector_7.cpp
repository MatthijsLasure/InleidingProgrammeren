#include "vector_7.h"

Vector::Vector(int size) : s{size}, max{2*size} {
	elementen = new double[max];
	for(int i=0; i<max; i++){
		elementen[i]=0.0;
	}
}

Vector::Vector(const Vector& v) :  s{v.s}, max{v.max}, elementen{new double[v.s]} {
	for(int i=0; i<v.s; i++){
		elementen[i]=v.get(i);
	}
}

void Vector::push_back(double d){
	if(s>=max) resize(max*2);
	elementen[s++]=d;
}

Vector& Vector::operator=(const Vector& a){
	delete[] elementen;
	elementen = new double[a.max];
	max = a.max;
	for(int i=0; i<a.max; i++){
		elementen[i]=a.get(i);
	}
	s=a.s;
	return *this;
}


void Vector::resize(int newmax){
	double* oude_elementen = elementen;
	elementen = new double[newmax];
	for(int i=0; i<max; i++)
		elementen[i]=oude_elementen[i];
	cout << "Deleting";
	delete[] oude_elementen;
	cout << "Done";
	max=newmax;
}


