#include <iostream>
using namespace std;

class PMemory {
private:
	static PMemory* instance;
	int memorysize;
	int used;
	int left;
	int *map;
	int sizeofmap;

	PMemory::PMemory() {}
	PMemory::PMemory(int size) { memorysize = size; }

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
	int getSizeofMap() {
		return sizeofmap;
	}

	void allocMemory(int size) {
		this->memorysize = size;
		map = new int[memorysize];
		for (int i = 0; i < memorysize; i++) {
			map[i] = 0;
		}
		sizeofmap = sizeof(map);
	}
	static PMemory* getinstance() {
		if (!instance) {
			instance = new PMemory();
		}
		return instance;
	}
};