#include "SetIterator.h"
#include "Set.h"

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
SetIterator::SetIterator(const Set& m) : set(m)
{
	this->currentNode = m.head;
}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
void SetIterator::first() {

	this->currentNode = set.head;
}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
void SetIterator::next() {
	if (!valid()) {
		throw std::exception();
	}
	this->currentNode = set.elemsNext[currentNode];

}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
TElem SetIterator::getCurrent()
{
	if (!valid())
	{
		throw std::exception();
	}
	return set.elems[currentNode];
}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
bool SetIterator::valid() const {
	//TODO - Implementation
	
	return this->currentNode != -1;

}



