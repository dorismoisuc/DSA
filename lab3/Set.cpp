#include "Set.h"
#include "SetITerator.h"

/* 
/*
 ***********************INITIALIZATION COMPLEXITY************************

	BC = WC = AC = theta(n), where n is the initial capacity
	OVERALL COMPLEXITY = theta(n)

 ************************************************************************
*/

Set::Set() {
	int indexFOR=1;
	this->capacity = initialCap; 
	this->elems = new TElem[capacity]; 
	this->elemsNext = new int[capacity];
	this->head = -1;
	this->length = 0;
	
	// initializing the nexts for the elems

	for (indexFOR = 1; indexFOR <= this->capacity - 1; indexFOR++)
	{
		this->elemsNext[indexFOR] = indexFOR + 1;
	}

	this->elemsNext[this->capacity-1] = -1;
	
	// putting firstEmpty on the position where the index begins 

	this->firstEmpty = 1;
}

/*
****************************ADD COMPLEXITY****************************

 -> BC = theta(1) if the element already exists on the first position
                  and can't be added


 -> AC = theta(length) if the element already exists on the last position
					   and will not be added
					   or if the element will be added and is not found


 -> WC = theta(2*length) { theta(length) from doing the resize +
						   + theta(length) from adding the element } 

	OVERALL COMPLEXITY= O(n)

***********************************************************************

*/
bool Set::add(TElem elem) {
	//TODO - Implementation

	int currentNode;

	// if there are no more nexts
	// it needs a resize 

	if (this->firstEmpty == -1)
	{
		TElem* newElems = new TElem[this->capacity * 2];
		int* newNext = new int[this->capacity * 2];
		
		// initializing the first half of the newElems and 
		// newNext with the previous elems and nexts

		for (int i = 1; i < this->capacity; i++)
		{
			newElems[i] = this->elems[i];
			newNext[i] = this->elemsNext[i];
		}

		// initializing the next half of the newNext 

		for (int i = this->capacity; i <= this->capacity * 2 - 1; i++)
		{
			newNext[i] = i + 1;
		}

		// initializing the last newNext with -1 

		newNext[(this->capacity * 2) -1] = -1;
		
		// deleting the previous elems and elemsNext
		delete[] this->elems;
		delete[] this->elemsNext;
		
		// and reinitializing them with the 2*capacity 
		// elems and elemsNext obtained from resize

		this->elems = newElems;
		this->elemsNext = newNext;
		this->firstEmpty = this->capacity;
		this->capacity = 2 * this->capacity;
	}

	// if the set is empty, it means the head == -1 
	// and we add the element on the head's position 

		if (this->head == -1)
		{
			this->length++;
			this->elems[this->firstEmpty] = elem;
			this->head = this->firstEmpty;
			//cout << "FIRST EMPTY PT PRIMUL ELEM: " << firstEmpty << endl;
			this->firstEmpty = this->elemsNext[this->firstEmpty];
			//cout << "FIRST EMPTY AFTER: " << firstEmpty << endl;
			this->elemsNext[this->head] = -1;
			return true;
		}

	// if the elem is to be added on a non empty set

		else
		{
			currentNode = this->head;
			
			// verifying if the element already exists in the set
			// if it does we return false and it will not be added
			
			while (currentNode != -1)
			{
				if (this->elems[currentNode] == elem)
				{
					return false;
				}
				currentNode = this->elemsNext[currentNode];
			}


			// if it doesn't already exist, it will be added on the first position ( head's ) 
			if (currentNode == -1)

			{
				auto newNode = this->firstEmpty;
				this->firstEmpty = this->elemsNext[this->firstEmpty];
				
				//cout << "Current Node: " << currentNode << endl;
				//cout << "First empty: " << firstEmpty << endl;
				
				this->elems[newNode] = elem;
				this->elemsNext[newNode] = this->head;
				this->head = newNode;
				this->length++;
				return true;
				
				
				/*
				
				this->elems[this->firstEmpty] = elem;
				this->elems[currentNode] = this->firstEmpty;
				this->firstEmpty = this->elemsNext[firstEmpty];
				this->elemsNext[currentNode] = -1;
				return true;*/
			}
		}

	return false;
}
/*
**************************REMOVE COMPLEXITY**************************

-> BC = theta(1) if the element exists on the first position
	             or if the set is empty

-> AC = theta(n) if the element is found on an average position
  

-> WC = theta(n) if the element is not found or 
				 if the element is found on the last position

  OVERALL COMPLEXITY = O(n) 


*********************************************************************
*/
bool Set::remove(TElem elem) {
	//TODO - Implementation
	int index1 = 1, index2 = 1;
	int prevNode = -1;
	int currentNode;
	currentNode = this->head;

	// parses the set until it finds the element
	// for delete
	
	while (currentNode != -1 && elems[currentNode] != elem)
	{
		prevNode = currentNode;
		currentNode = elemsNext[currentNode];
	}

	// if the element is not found
	// return false

	if (currentNode == -1)
		return false;

	// if the element to be deleted 
	// is the head

	if (prevNode == -1)
		{
			
			// the next element is put on the head's position

			this->head = this->elemsNext[currentNode];
			this->elemsNext[currentNode] = firstEmpty;
			this->firstEmpty = currentNode;
			this->length--;
			return true;
		}

	// if the element to be deleted
	// is in any position but the head 

	else
	{
		this->elemsNext[prevNode] = this->elemsNext[currentNode];
		this->elemsNext[currentNode] = firstEmpty;
		this->firstEmpty = currentNode;
		this->length--;
		return true;
	}
		
}

/*
***************************SEARCH COMPLEXITY*************************** 

 -> BC = theta(1); if the set is empty 
				   or if the element is found on the first position
 -> WC = theta(n) ; if the element is found on the last position 
				    or if it doesn't exist
 
 -> AC = theta(n)

  OVERALL COMPLEXITY = O(n), where n is the length of the set

************************************************************************
*/

bool Set::search(TElem elem) const {
	//TODO - Implementation
	int currentNode;
	currentNode = this->head;
	if (this->length == 0)
		return false;
	while (currentNode != -1)
	{
		if (this->elems[currentNode] == elem)
		{
			return true;
		}
		currentNode = this->elemsNext[currentNode];
	}
	return false;
}

/* 
 ************************************************************************
 
 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/ 
int Set::size() const {
	//TODO - Implementation
	return this->length;
}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
bool Set::isEmpty() const {
	//TODO - Implementation
	return this->length==0;
}

void Set::intersection(const Set& s)
{
	bool found=true;
	SetIterator it1 = this->iterator();
	it1.first();
	while (it1.valid())
	{
		SetIterator it2 = s.iterator();
		it2.first();
		while (it2.valid())
		{
			if (it2.getCurrent() != it1.getCurrent())
			{
				this->remove(it1.getCurrent());
			}
			it2.next();
		}
		it1.next();
	}

}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
Set::~Set() {
	delete[] this->elems;
}

/*
 ************************************************************************

 BC = WC = AC = theta(1)
 OVERALL COMPLEXITY = theta(1)

 ************************************************************************
*/
SetIterator Set::iterator() const {
	return SetIterator(*this);
}
