#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;


// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
SortedMap::SortedMap(Relation r) {
	
	this->relation = r;
	this->length = 0;
	this->root = NULL;

}

// BC = theta(1), we add on the root position
// AC = WC = theta(n) 
// OVERALL COMPLEXITY = O(n) 
TValue SortedMap::add(TKey k, TValue v) {
	
	BSTNode* node = new BSTNode;
	BSTNode* parent = new BSTNode;
	node = this->root;
	// if the root is empty, then we add a root 
	// we initialize the root
	if (node == NULL)
	{
		this->root = this->initNode(TElem{ k,v });
		length++;
		return NULL_TVALUE;
	}
	// we search for the node in the tree
	while (node != NULL && node->info.first != k)
	{
		parent = node;
		// if the relation is true 
		if (relation(k,node->info.first))
			node = node->left;
		// if it's not 
		else
			node = node->right;
	}
	// if we didn't find the node(the key) we add it and return null
	if (node == NULL)
	{
		node = initNode(TElem{ k, v });
		// if the relation is true
		if (relation(k, parent->info.first))
		{
			parent->left = node;
		}
		// if it's not
		else
		{
			parent->right = node;
		}
		this->length++;
		return NULL_TVALUE;
		
	}
	// else if we already have the node(the key)
	// we replace the value(the key has) with the new one and return the old one 
	else if(node->info.first == k)
	{
		TValue oldValue = node->info.second;
		node->info.second = v;
		return oldValue;
	}
}

// BC = theta(1), the element is found on the root's position
// AC = WC = theta(n)
// OVERALL COMPLEXITY = O(n)
TValue SortedMap::search(TKey k) const {
	
	BSTNode* currentNode = this->root;
	bool found = false;
	while(currentNode != NULL && !found)
	{
		if (currentNode->info.first == k)
			found = true;
		// if the relation is not satisified
		else if (!this->relation(k, currentNode->info.first))
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	if (found)
		return currentNode->info.second;
	else
		return NULL_TVALUE;
}



// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
int SortedMap::size() const {
	return this->length;
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
bool SortedMap::isEmpty() const {
	return this->length == 0;
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

// we get the maximum node on the left side
// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
BSTNode* SortedMap::maximum(BSTNode* node)
{
	BSTNode* currentNode = node;
	BSTNode* maximumNode = node;
	while (currentNode->right != NULL)
	{
		maximumNode = currentNode;
		currentNode = currentNode->right;
	}
	return maximumNode;
}

// OVERALL COMPLEXITY = O(n)
TValue SortedMap::remove(TKey k) {
	TValue deletedValue = NULL_TVALUE;

	this->root = this->recurrentRemove(this->root, k, deletedValue);
	
	// if the value to be deleted is different from NULL
	// we decrease the length
	// and return the deleted value
	if (deletedValue != NULL_TVALUE)
		this->length--;
	
	// or we return NULL
	return deletedValue;
}

// OVERALL COMPLEXITY = O(n)
BSTNode* SortedMap::recurrentRemove(BSTNode* node, TKey k, TValue& deletedValue)
{
	// if we don't have a root we return NULL  
	if (node == NULL) { return node; }
	
	else if (node->info.first == k)
	{
		// we put the node's value
		deletedValue = node->info.second;

		// if the current node doesn't have kids
		if (node->left == NULL && node->right == NULL)
			return NULL;

		else if (node->left == NULL)
			return node->right;
		else if (node->right == NULL)
			return node->left;
		
		// if it has both kids 
		else {
			// we initialize another value 
			TValue anotherValue = NULL_TVALUE;

			// we get the maximum value on the left side
			BSTNode* maxNode = this->maximum(node->left);

			// we put its details in the current node
			node->info.first = maxNode->info.first;
			node->info.second = maxNode->info.second;

			// delete the maximum
			node->left = this->recurrentRemove(node->left, maxNode->info.first, anotherValue);
		}
	}
	
	// it searches on the right 
	else if (this->relation(node->info.first, k))
	{
		node->right = this->recurrentRemove(node->right, k, deletedValue);
	}
	// or in the left
	else
	{
		node->left = this->recurrentRemove(node->left, k, deletedValue);
	}
	// we return the node to be deleted
	return node;
}

int SortedMap::getKeyRange() const
{
	int min, max;
	BSTNode* node = this->root;
	if (this->isEmpty())
		return -1;
	else
	{
		while (node->left != NULL)
			node = node->left;
		min = node->info.first;
		node = this->root;
		while (node->right != NULL)
			node = node->right;
		max = node->info.first;
	}
	return max - min;
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
BSTNode* SortedMap::initNode(TElem element)
{
	BSTNode* node = new BSTNode;
	node->info = element;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
SortedMap::~SortedMap() {

}