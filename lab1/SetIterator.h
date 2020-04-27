#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	//TODO - Representation
	int index; //the index with which we parse the set

public:
	void first();
	void next();
	
	//changes the current element from the iterator to the previous element, 
	//or, if the current element was the first, makes the iterator invalid
	//throws an exception if the iterator is not valid

	void previous();
	TElem getCurrent();
	bool valid() const;

};


