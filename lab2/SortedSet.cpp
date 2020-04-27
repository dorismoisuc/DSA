#include "SortedSet.h"
#include "SortedSetIterator.h"

// complexity: theta(1)

SortedSet::SortedSet(Relation r) {
	this->relation = r;
	this->head = nullptr;
	this->length = 0;
}

/*
	complexity for the add function

BC -> if the SortedSet is empty: theta(1) 
	  or if the element to be added is less
	  than the value from the head
	  or if the element already exist on the first position

AC -> If the element exists on the last position(or average): theta(size)

WC -> if the element to be added must be on 
	  the last position: theta(size)

OVERALL COMPLEXITY: O(size)

*/
bool SortedSet::add(TComp elem) {

	SLLNode* nodeToAdd = new SLLNode;
	nodeToAdd->value = elem;
	nodeToAdd->next = nullptr;

	// if the SortedSet is empty
	// and it has to be added on the first position
	if (this->head == nullptr)
	{
		this->head = nodeToAdd;
		this->length++; 
		return true; 
	}
	
	else
	{
		// first we check if the element 
		// already exists on the first position
		// if it does, it returns false and
		// is not added
		if (this->head->value == elem)
		{
			return false;
		} 

		// if the element to be added 
		// is less than the value from the head node
		// it is added on the head's position
		if (this->relation(elem, this->head->value) == true)
		{
			nodeToAdd->next = this->head;
			this->head = nodeToAdd;
			this->length++;
			return true;
		}
		else // if it is greater, we search its place
		{
			SLLNode* currentNode;
			currentNode = this->head;

			// we parse each node until we find 
			// the node that respects the relation
			// and also if the element already exists  

			while (currentNode->next != nullptr && this->relation(currentNode->next->value, elem) == true)
			{
				if (currentNode->value == elem)
				{
					return false;
				}
				currentNode = currentNode->next;
			}

			// even in the last node to be parsed 

			if (currentNode->value == elem)
			{
				return false;
			}
			nodeToAdd->next = currentNode->next;
			currentNode->next = nodeToAdd;
			this->length++;
			return true;
		}
	}
	return false;
}

/*
		complexity for remove

search - BC -> theta(1)
	   - WC = AC = theta(size) 
	   - overall: O(size)
BC -> theta(1) if the element is on the first position
WC -> if the element exists on the last position: theta(size) + theta(size)
												 = theta(2*size) = theta (size)

OVERALL complexity: O(size)


*/
bool SortedSet::remove(TComp elem) {
	
	if (search(elem) == true)
	{
		if (this->head->value == elem)
		{
			// if the element to be deleted
			// is the head
			SLLNode* nextNode;
			nextNode = this->head->next;
			delete this->head;
			this->head = nextNode;
			this->length--;
			return true;
		}
		else
		{
			SLLNode* currentNode;

			// used for reconnecting nodes
			// after removing one
			SLLNode* previousNode = new SLLNode; 

			currentNode = this->head;
			while (currentNode != nullptr)
			{
				if (currentNode->value == elem)
				{
					previousNode->next = currentNode->next;
					delete currentNode;
					this->length--;
					return true;
				}
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
		
		}
	}
	return false;
}

// complexity for search
// BC -> theta(1); if the element is found
//				   on the first position or
//			       it doesn't exist
// WC -> theta(size); if the element exists
//					  on the last position
// 
// AC -> theta(size)
// OVERALL COMPLEXITY: O(size)
bool SortedSet::search(TComp elem) const {
	if (this->length == 0)
		return false;
	SLLNode* currentNode;
	currentNode = this->head;
	while (currentNode != nullptr)
	{
		if (currentNode->value == elem)
			return true;
		currentNode = currentNode->next;
	}
	return false;
}

// complexity: BC = AC = WC = theta(1)
int SortedSet::size() const {
	//TODO - Implementation
	return this->length;
}


// complexity: BC = AC = WC = theta(1)
bool SortedSet::isEmpty() const {
	//TODO - Implementation
	if (this->length == 0)
		return true;
	return false;
}

// complexity: BC = AC = WC = theta(1)
SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}

// OVERALL COMPLEXITY: O(size)
// size - size of the SortedSet
// BC: theta(1) ; if the SortedSet is empty
// WC: theta(size)
SortedSet::~SortedSet() {
	SLLNode* currentNode;
	while (this->head != nullptr)
	{
		currentNode = this->head;
		this->head = this->head->next;
		delete currentNode;
	}
}


