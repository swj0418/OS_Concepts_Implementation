#include <stdlib.h>
#include <iostream>

class VMemory 
{
private:
	static VMemory *vmem;
	int memorysize;
	int used;
	int left;
	int *map;

public:
	void setMemorySize(int setsize) {
		memorysize = setsize;
	}

	int getMemorySize() {
		return memorysize;
	}
	int getUsedSize() {
		return used;
	}
	int getLeftSize() {
		return left;
	}
	int* getMemoryMap() {
		return map;
	}

	void allocMemory(int size) {
		this->memorysize = size;
		map = new int[memorysize];
		for (int i = 0; i < memorysize; i++) {
			map[i] = 0;
		}
	}

	static VMemory *getvmem() {
		if (!vmem) {
			vmem = new VMemory();
		}
		return vmem;
	}
};
