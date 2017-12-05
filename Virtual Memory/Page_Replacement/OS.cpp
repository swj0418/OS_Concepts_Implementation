#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Disk_Controller.cpp"
#include "Pager.cpp"
#include "PMemory.cpp"
#include "VMemory.cpp"

using namespace std;
class OS {

};

VMemory* VMemory::vmem = 0;
PMemory* PMemory::instance = 0;

int main() {
	PMemory::getinstance()->allocMemory(100);
	cout << PMemory::getinstance()->getMemorySize() << endl;

	int *map = PMemory::getinstance()->getMemoryMap();
	cout << PMemory::getinstance()->getSizeofMap() << endl;


	for (int i = 0; i < sizeof(map); i++) {
		cout << map[i] << "\t";
		if (i % 10 == 9) {
			cout << endl;
		}
	}
}