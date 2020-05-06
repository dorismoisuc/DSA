#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);
	
	
	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);
	
	cout << "@SHORT TESTS PASSED@" << endl << endl;
}

void testIntersection()
{
	cout << "@ TEST INTERSECTION @ "<<endl<<endl;
	Set s;

	assert(s.size() == 0);
	assert(s.isEmpty() == true);

	s.add(1);
	s.add(2);
	s.add(3);

	assert(s.size() == 3);

	Set s2;

	s2.add(1);
	s2.add(2);
	s2.add(4);

	assert(s2.size() == 3);
	assert(s2.isEmpty() == false);

	s.intersection(s2);

	//cout <<"SIZE "<< s.size()<<endl;
	s.testeaza();

	//cout << "SIZE PLEASE WORK" << s.size() << endl;
	assert(s.size() == 2);


}



