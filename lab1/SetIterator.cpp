#include "SetIterator.h"
#include "Set.h"
#include<exception>
using namespace std;

// complexity = theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	index = 0;
}

// complexity = theta(1)
void SetIterator::first() {
	//TODO - Implementation
	index = 0;
}

// complexity = theta(1)
void SetIterator::next() {
	//TODO - Implementation
	if (!valid())
		throw exception();
	index++;
}

// complexity = theta(1)
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (!valid())
		throw exception();
	return set.elems[index];
	//return NULL_TELEM;
}
// complexity = theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
	if (index >= set.size() || index < 0)
		return false;
	return true;
}

// complexity = theta(1) = BC = AC = WC
void SetIterator::previous()
{
	if (!valid())
		throw exception();
	index--;

}


