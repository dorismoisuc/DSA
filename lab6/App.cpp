#include "ExtendedTest.h"
#include "ShortTest.h"
#include <cassert>
#include "SortedMap.h"
#include "SMIterator.h"

#include <iostream>
using namespace std;

bool relatio(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	

	testAll();
	testAllExtended();


	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


