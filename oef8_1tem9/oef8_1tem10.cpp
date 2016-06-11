/*
 * oef8.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <vector>
#include <iostream>

using namespace std;

void deel2(double& var) {
	cout << &var;
}

void deel4a(double*& ptr) {
	cout << &ptr;
}

void deel4b(double* ptr) {
	cout << *ptr;
}

void deel5(double* ptr) {
	cout << ptr;
}

// Deel 06
//========
void swapValuesByReference(double& a1, double& a2) {
	double temp = a1;
	a1 = a2;
	a2 = temp;
}

// Deel 07
//========
void swapValuesByPointer(double* p1, double* p2) {
	double temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// Deel 08
//========
void swapPointers(double*& p1, double*& p2) {
	double* temp = p1;
	p1 = p2;
	p2 = temp;
}

// Deel 10
//========
void sort(double a[], int length) {
	for(int i=length - 1; i > 0; i--) {
		for (int j=0; j < i; j++) {
			if(a[j] > a[j+1])
				swapValuesByReference(a[j], a[j+1]);
		}
	}
}


int main() {
	// Deel 01
	//========
	double var1 = 15.0;
	double var2 = 20.0;

	//double* p_tovar1 = &var1;

	// Deel 02
	//========
	cout << "Deel 02" << endl;
	cout << "Var1\t";
	deel2(var1);
	cout << endl;

	cout << "Var2\t";
	deel2(var2);
	cout << endl;

	// Deel 03
	//========
	double* ptr1 = new double{5.0};
	double* ptr2 = new double{10.0};

	// Deel 04 + 05
	//=============
	cout << "Deel 04 + 05" << endl;
	cout << "Ptr1\t";
	deel4a(ptr1);
	cout << "\t";
	deel4b(ptr1);
	cout << "\t";
	deel5(ptr1);
	cout << endl;

	cout << "Ptr2\t";
	deel4a(ptr2);
	cout << "\t";
	deel4b(ptr2);
	cout << "\t";
	deel5(ptr2);
	cout << endl;

	// Deel 06 + 07
	//=============
	cout << endl;
	cout << "Deel 06+07: Before SVBR\t" << var1 << "\t" << var2 << endl;
	swapValuesByReference(var1, var2);
	cout << "SwapValuesByReference\t" << var1 << "\t" << var2 << endl;
	swapValuesByPointer(&var1, &var2);
	cout << "SwapValuesByPointer\t" << var1 << "\t" << var2 << endl;

	// Deel 08
	//========
	cout << "Deel 08: Before SB\t" << *ptr1 << "\t" << *ptr2 << endl;
	swapPointers(ptr1, ptr2);
	cout << "SwapPointers\t\t" << *ptr1 << "\t" << *ptr2 << endl;

	// Deel 09
	//========
	const double* d8a1 = new double{7.5};
	const double* d8a2 = new double{2.0};

	// Error!
//	double temp = *d8a1;
//	*d8a1 = *d8a2;
//	*d8a2 = temp;

	cout << "Deel 09: Before const swap\t" << *d8a1 << "\t" << *d8a2 << endl;
	const double *temp = d8a1;
	d8a1 = d8a2;
	d8a2 = temp;
	cout << "Deel 09: After const swap\t" << *d8a1 << "\t" << *d8a2 << endl;

	double* const d8b1 = new double{1.5};
	double* const d8b2 = new double{8.0};

	// Fails compiling!
//	double* const temp2 = const d8a1;
//	d8a1 = d8a2;
//	d8a2 = temp2;

	cout << "Deel 09: Before pointer swap\t" << *d8b1 << "\t" << *d8b2 << endl;
	double temp2 = *d8b1;
	*d8b1 = *d8b2;
	*d8b2 = temp2;
	cout << "Deel 09: After pointer swap\t" << *d8b1 << "\t" << *d8b2 << endl;

	// Deel 10
	//========
	int limit = 10;
	double* a = new double[limit];
	for(int i=0; i<limit;i++) a[i] = rand() % 1000;

	for(int i=0; i<limit;i++) cout << a[i] << "\t";
	cout << endl;
	sort(a, limit);
	for(int i=0; i<limit;i++) cout << a[i] << "\t";
	cout << endl;

	delete[] a;
}



