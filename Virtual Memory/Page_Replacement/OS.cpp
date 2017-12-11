#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>

#include "Process.h"
#include "Diskcontroller.h"
#include "Pager.h"
#include "PMemory.h"
#include "VMemory.h"
#include "PageTable.h"

using namespace std;
class OS {
public:
	OS() {

	}
};
VMemory* VMemory::vmem = 0;
PMemory* PMemory::instance = 0;
Pager* Pager::pager = 0;

int main() {
	cout << PMemory::getinstance()->getMemorySize() << endl;
	PMemory::getinstance()->resetMemory();
	int *map = PMemory::getinstance()->getMemoryMap();
	Pager pager; pager.getPager();

	Process P1;
	P1.setProcessSize(100);
	P1.setProcessID(1210);

	Process P2;
	P2.setProcessID(2111);
	P2.setProcessSize(149809);

	cout << "Process ID : " << P1.getProcessID() << " Process Size : " << P1.getProcessSize() << endl;
	cout << "Process ID : " << P2.getProcessID() << " Process Size : " << P2.getProcessSize() << endl;


	for (int i = 0; i < PMemory::getinstance()->getMemorySize(); i++) {
		cout << map[i] << "\t";
		if (i % 10 == 9) {
			cout << endl;
		}
	}

	pager.giveProcessPMemory(&P1);
	cout << "Process " << P1.getProcessID() << " Page Count : " << P1.getPageCount() << endl;

	for (int i = 0; i < PMemory::getinstance()->getMemorySize(); i++) {
		cout << map[i] << "\t";
		if (i % 10 == 9) {
			cout << endl;
		}
	}
	
	PMemory* pPM = PMemory::getinstance();
	pPM->printMemoryStatus();

	pager.giveProcessPMemory(&P2);
	for (int i = 0; i < PMemory::getinstance()->getMemorySize(); i++) {
		cout << map[i] << "\t";
		if (i % 10 == 9) {
			cout << endl;
		}
	}
	pPM->printMemoryStatus();

	PageTable pt;
	cout << pager.getPagesize() << endl;

	pager.createPageTable(&P1);
	P1.getPageTable().showTable();
}