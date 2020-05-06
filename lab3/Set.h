#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111
#define initialCap 10000
typedef int TElem;
class SetIterator;
#include <iostream>
using namespace std;

class Set {
	//DO NOT CHANGE THIS PART
	friend class SetIterator;

    private:
        TElem* elems;
        int* elemsNext;
        int head;
        int firstEmpty;
        int capacity;
        int length;


    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        //return an iterator for the set
        SetIterator iterator() const;

    

       //keeps only the elements which appear in s as well
       void intersection(const Set& s);


        // destructor
        ~Set();

        void testeaza() {
            int current = head;
            if (length == 0)
            {
                cout << "NU EXISTA ELEMENTE"<<endl;
            }
            while (current != -1)
            {
                cout << "Elemente: " << elems[current] << " " << "Next: " << elemsNext[current] << " " << endl;
                current = elemsNext[current];
            }
         
        }

};





