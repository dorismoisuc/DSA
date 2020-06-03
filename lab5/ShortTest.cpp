#include "ShortTest.h"
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <assert.h>
#include <vector>
#include<iostream>

void testAll() {
	MultiMap m;
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.size() == 6);

	assert(m.remove(5, 600) == false);
	assert(m.remove(1, 500) == true);

	assert(m.size() == 5);

    vector<TValue> v;
	v=m.search(6);
	assert(v.size()==0);

	v=m.search(1);
	assert(v.size()==1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.getCurrent();
		im.next();
	}
	assert(im.valid() == false);
	im.first();
	assert(im.valid() == true);

	MultiMap m3;
	m3.add(1, 1);
	m3.add(1, 2);
	m3.add(1, 3);
	m3.add(1, 4);
	m3.add(2, 4);
	MultiMapIterator im3 = m3.iterator();
	while (im3.valid())
	{
		//cout << im3.getCurrent().first << " " << im3.getCurrent().second << endl;
		try {
			im3.next();
		}
		catch (std::exception) {}
	}
	int i = 0;
	//cout << endl;
	im3.first();
	TEl removedPair = im3.remove2();
	assert(m3.size() == 4);
	assert(removedPair == TEl(1, 1));
	//cout << "After the first remove"<<endl;
	i = 0;
	im3.first();
	while (im3.valid()&& i<3)
	{
		//cout << im3.getCurrent().first << " " << im3.getCurrent().second << endl;
		i++;
		try
		{
			im3.next();
		}
		catch (std::exception) {}
	}
	TEl removedPair2 = im3.remove2();
	assert(m3.size() == 3);
	assert(removedPair2 == TEl(2, 4));

	cout << "TEST EXTRA OPERATION" << endl;
	MultiMap m4;
	m4.add(1, 2);
	m4.add(5, 3);
	m4.add(7, 2);
	m4.add(3, 2);
	m4.add(12, 2);
	assert(m4.getKeyRange() == 11 );


}
