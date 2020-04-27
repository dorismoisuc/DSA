#include "SortedSetIterator.h"
#include <exception>

using namespace std;

// BC = AC = WC = theta(1)
SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	this->currentNode = m.head;
}

// BC = AC = WC = theta(1)
void SortedSetIterator::first() {
	
	currentNode = multime.head;
}

// BC = AC = WC = theta(1)
void SortedSetIterator::next() {
	if (currentNode == NULL)
		throw exception("Invalid current node");
	this->currentNode = currentNode->next;

}

// BC = AC = WC = theta(1)
TElem SortedSetIterator::getCurrent()
{
	if (currentNode == NULL)
		throw exception("Invalid current node");
	TElem elem = currentNode->value;
	return elem;

	return NULL_TELEM;

	
}

// BC = AC = WC = theta(1)

bool SortedSetIterator::valid() const {
	if (currentNode != NULL)
		return true;
	return false;
}

// moves the current element from the iterator k steps forward,
// or makes the iterator invalid if there are less than k elements left in the Set.
// throws an exception if the iterator is invalid or if k is negative or zero
// BC = theta(1) - if k is <= 0 or the iterator is invalid 
// WC = theta(k) where k is the number of steps
// OVERALL COMPLEXITY: O(k)
void SortedSetIterator::jumpForward(int k)
{
	if (k <= 0)
		throw exception();
	while (k && currentNode != nullptr)
	{
			currentNode = currentNode->next;
			k--;
	}

}
/*
{
	if (!valid() || k<=0)
		throw exception();
	//int i = 0;
	while (k && index != nullptr)
	{
		if (index->next != nullptr)
		{
			index = index->next;
			//i++;
			k--;
		}
		else
			index = nullptr;
	}
	if (!valid())
		throw exception();
}*/