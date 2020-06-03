#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TEl;
#define NULL_TVALUE -111111
typedef std::pair<TKey, std::vector<TValue>> TElem;
#define NULL_TELEM pair<int,int>(-111111, -111111)
#define NULL_TKEY -111111
#define DELETED -111110
class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation

	TElem* hashTable;
	int mmSize;
	int mmCapacity;

	void resize();

public:
	//constructor
	MultiMap();

	int hash(int k, int i) { return (firstHash(k) + i * secondHash(k)) % this->mmCapacity; }

	int firstHash(int k) { return abs(k) % this->mmCapacity; }

	int secondHash(int k) { return 1 + (abs(k) % (this->mmCapacity - 1)); }

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) ;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() ;

	//returns the difference between the maximum and the minimum key (assume integer keys)
	//if the MultiMap is empty the range is -1
	int getKeyRange();
	//descturctor
	~MultiMap();


};

