#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

// // -> BC = WC = AC = theta(n) where n is the size
// OVERALL COMPLEXITY = theta(n)
SMIterator::SMIterator(const SortedMap& m) : map(m) {
	BSTNode* node = map.root;
	this->stack = new BSTNode * [map.length + 2];
	this->top = -1;
	while (node != NULL)
	{
		this->stack[++this->top] = node;
		node = node->left;
	}
	if (this->top < 0)
		this->currentElement = NULL;
	else
		this->currentElement = this->stack[this->top];
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)

void SMIterator::first() {
	if (this->top == -1)
	{
		this->currentElement = NULL;
	}
	else
		this->currentElement = this->stack[top];
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
void SMIterator::next() {
	if (!this->valid())
		throw exception();
	
	BSTNode* node = this->stack[this->top--];
	if (node->right != NULL)
	{
		node = node->right;
		while (node != NULL)
		{
			this->stack[++this->top] = node;
			node = node->left;
		}
	}
	if (this->top < 0)
	{
		this->currentElement = NULL;
	}
	else
		this->currentElement = this->stack[this->top];
	
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
bool SMIterator::valid() const {
	if (this->currentElement == NULL)
		return false;
	return true;
}

// -> BC = WC = AC = theta(1)
// OVERALL COMPLEXITY = theta(1)
TElem SMIterator::getCurrent() const {
	if (!this->valid())
		throw exception();
	return this->currentElement->info;
}


