#include "MultiMapIterator.h"
#include "MultiMap.h"

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(mmCapacity)
// OVERALL COMPLEXITY is O(mmCapacity)
MultiMapIterator::MultiMapIterator( MultiMap& m): m(m) {
	//TODO - Implementation
	this->first();
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
TEl MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	TEl current;
	current.first = this->m.hashTable[this->indexKey].first;
	current.second = this->m.hashTable[this->indexKey].second[indexValue];
	return current;
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if (this->indexKey == -1 || this->indexKey == this->m.mmCapacity)
		return false;
	return true;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	int indexK = this->indexKey;
	int indexV = this->indexValue + 1;

	if (indexV < this->m.hashTable[indexK].second.size())
	{
		this->indexValue++;
		return;
	}
	else
	{
		indexK++;
		while (indexK < this->m.mmCapacity)
		{
			if (this->m.hashTable[indexK].first != NULL_TKEY && this->m.hashTable[indexK].first != DELETED)
			{
				this->indexKey = indexK;
				this->indexValue = 0;
				return;
			}
			indexK++;
		}
	}
	this->indexKey=this->m.mmCapacity;
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is O(mmCapacity)
void MultiMapIterator::first() {
	//TODO - Implementation
	int i = 0;
	while (i<this->m.mmCapacity)
	{
		if (this->m.hashTable[i].first!=NULL_TKEY && this->m.hashTable[i].first!=DELETED)
		{
			this->indexKey = i;
			this->indexValue = 0;
			return;
		}
		i++;
	}
}

TEl MultiMapIterator::remove2()
{
	if (!valid())
		throw std::exception();
	TEl removedPair = getCurrent();
	m.remove(removedPair.first, removedPair.second);
	//this->next();
	return removedPair;

}

