#ifndef SIMPLECLASS_H_
#define SIMPLECLASS_H_

/*
 * SimpleClass.h
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include <iostream>

using namespace std;

class SimpleClass {
private :
	int i ;
	int* j ;
public :
	SimpleClass (); // Constructor .
	SimpleClass (const SimpleClass &); // Copy constructor .
	SimpleClass& operator=(const SimpleClass &); // Assignment operator .
	void print (); // Print i en j uit .
};

#endif /* SIMPLECLASS_H_ */
