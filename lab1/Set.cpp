#include "Set.h"
#include "SetITerator.h"
#include<stdlib.h>

Set::Set() {
	//TODO - Implementation
	numberOfElements = 0;
	capacity = 100;
	elems = new TElem[capacity];
}

/* COMPLEXITY FOR THE ADD FUNCTION //
search - BC -> theta(1);
		 WC -> theta(numberOfElements) 
		 AC -> theta(numberOfElements) + theta(numberOfElements)
resize - BC -> theta(0) ; when there is no resize needed
		 WC -> theta(numberOfElements)
		 AC -> [theta(numberOfElements) * (0 + numberOfElements)] / 2 

add - BC = WC = AC = theta(1)

If the element exists on the first position: theta(1)
If the element exists on the last position(or average): theta(numberOfElements)
If the element doesn't exist, but resize is needed: theta(numberOfElements) + theta(numberOfElements) + theta(1)=
												  : theta(2*numberOfElements) ~= theta(numberOfElements)
If the element doesn't exist and the resize is not needed: theta(numberOfElements)+theta(0)+theta(1)=theta(numberOfElements)

BC = theta(1) - element is in the set, on the first position
WC = theta(2*numberOfElements) - element is added and the resize is needed
AC = theta(numberOfElements) 

OVERALL COMPLEXITY = O(numberOfElements)
*/	 

bool Set::add(TElem elem) {
	//TODO - Implementation
	if (search(elem) == true)
		return false;
	if (numberOfElements + 1 > capacity)
	{
		TElem* newElems = new TElem[2 * capacity];
		capacity *= 2;
		for (int it = 0; it < numberOfElements; it++)
		{
			newElems[it] = elems[it];
		}
		delete[](elems);
		elems = newElems;
	}
	elems[numberOfElements++] = elem;
	return true;

}
/* OVERALL COMPLEXITY FOR REMOVE / 

search - BC -> theta(1);
		 WC -> theta(numberOfElements)
		 AC -> theta(numberOfElements) + theta(numberOfElements)


BC: If the element doesn't exist : theta(numberOfElements) 
AC: If the element exists on the first position: theta(1) + theta(numberOfElements) = theta(numberOfElements) 
WC: If the element exists on the last position: theta(numberOfElements) + theta(numberOfElements)
	= theta(2*numberOfElements)

OVERALL complexity: theta(numberOfElements)


*/

bool Set::remove(TElem elem) {
	//TODO - Implementation
	int index = -1;
	for (int it = 0; it < numberOfElements; it++)
		if (elems[it] == elem)
		{
			index = it;
			numberOfElements--;
			break;
		}
	if (index != -1)
		for (int it = index + 1; it < numberOfElements + 1; it++)
			elems[it - 1] = elems[it];
	if (index == -1)
		return false;
	else
		return true;
}
/*
search 
BC -> theta(1) ; if the element is found on the first position
WC -> theta(numberOfElements) ; if the element exists and it's on the last position
AC -> theta(numberOfElements) ; if the element doesn't exist
*/
bool Set::search(TElem elem) const {
	//TODO - Implementation
	for (int it = 0; it < numberOfElements; it++)
		if (elems[it] == elem)
			return true;
	return false;
}

// complexity = theta(1)
int Set::size() const {
	//TODO - Implementation
	return numberOfElements;
}

// complexity = theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	return numberOfElements == 0;
}


Set::~Set() {
	//TODO - Implementation
	delete[](elems);
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}

