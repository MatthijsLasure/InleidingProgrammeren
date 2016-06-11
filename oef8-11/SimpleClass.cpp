/*
 * SimpleClass.cpp
 * @author Matthijs Lasure
 * @date 1-jun.-2016
 */

#include "SimpleClass.h"

SimpleClass::SimpleClass() {
	// TODO Auto-generated constructor stub
}

SimpleClass::SimpleClass(const SimpleClass& s) {
	i = s.i;
	j = s.j;
}

SimpleClass& operator=(const SimpleClass& s) {

	i = s.i;
	*j = *s.j;
}

void SimpleClass::print() {
	cout << i << " " << *j;
}
