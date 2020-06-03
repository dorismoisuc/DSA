#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

// -> BC = WC = AC = theta(mmCapacity)
// OVERALL COMPLEXITY -> theta(mmCapacity)
void MultiMap::resize()
{
	std::vector<TEl> values;

	// stock the elems that were already in the hashtable
	for (int i=0;i<this->mmCapacity;i++)
		for (auto elem : this->hashTable[i].second)
		{
			TEl current(this->hashTable[i].first, elem);
			values.push_back(current);
		}

	this->hashTable = new TElem[this->mmCapacity * 2];
	this->mmCapacity *= 2;
	this->mmSize = 0;

	for (int i = 0; i < this->mmCapacity; i++)
		this->hashTable[i].first = NULL_TKEY;

	for (auto elem : values)
		this->add(elem.first, elem.second);

}
// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
MultiMap::MultiMap() {
	// TO DO REPRESENTATION

	this->mmCapacity = 100;
	this->mmSize = 0;
	this->hashTable = new TElem[this->mmCapacity];

	for (int i = 0; i < this->mmCapacity; i++)
		this->hashTable[i].first = NULL_TKEY;

}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(m)
// OVERALL COMPLEXITY is O(mmCapacity)
void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	int i = 0;
	int position = this->hash(c, i);

	while (i < this->mmCapacity && (this->hashTable[position].first != NULL_TKEY && this->hashTable[position].first != DELETED))
	{
		if (this->hashTable[position].first == c)
		{
			this->hashTable[position].second.push_back(v);
			this->mmSize++;
			return;
		}
		i++;
		position = this->hash(c, i);
	}

	if (i == this->mmCapacity)
	{
		this->resize();
		this->add(c, v);
	}
	else
	{
		this->hashTable[position].first = c;
		this->hashTable[position].second.push_back(v);
		this->mmSize++;
	}
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(m)
// OVERALL COMPLEXITY is O(mmCapacity)
bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	int i = 0;
	int position = this->hash(c, i);

	while (i < this->mmCapacity && this->hashTable[position].first != NULL_TKEY)
	{
		if (this->hashTable[position].first == c)
		{
			for (int j=0;j<this->hashTable[position].second.size();j++)
				if (this->hashTable[position].second[j] == v)
				{
					this->hashTable[position].second.erase(this->hashTable[position].second.begin() + j);
					this->mmSize--;

					if (this->hashTable[position].second.size() == 0)
						this->hashTable[position].first = DELETED;
					return true;
			}
			return false;
		}
		i++;
		position = this->hash(c, i);
	}
	return false;

}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(m)
// OVERALL COMPLEXITY is O(mmCapacity)
vector<TValue> MultiMap::search(TKey c)  {
	//TODO - Implementation
	int i = 0;
	int position = this->hash(c, i);
	
	while (i < this->mmCapacity && this->hashTable[position].first != NULL_TKEY)
	{
		if (this->hashTable[position].first == c)
			return this->hashTable[position].second;
		i++;
		position = this->hash(c, i);

	}
	std::vector<TValue> empty;
	return empty;

}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
int MultiMap::size() const {
	//TODO - Implementation
	return this->mmSize;
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
bool MultiMap::isEmpty() const {
	//TODO - Implementation
	return this->mmSize == 0;
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
MultiMapIterator MultiMap::iterator()  {
	return MultiMapIterator(*this);
}

int MultiMap::getKeyRange() 
{
	MultiMapIterator it = this->iterator();
	TKey minKey = 100, maxKey = 0;
	
	while (it.valid())
	{
		if (it.getCurrent().first > maxKey)
			maxKey = it.getCurrent().first;
		if (it.getCurrent().first < minKey)
			minKey = it.getCurrent().first;
		it.next();
	}
	return maxKey - minKey;
}

// -> BC = theta(1)
// -> AC = theta(1)
// -> WC = theta(1)
// OVERALL COMPLEXITY is theta(1)
MultiMap::~MultiMap() {
	//TODO - Implementation
	delete[] this->hashTable;
}

