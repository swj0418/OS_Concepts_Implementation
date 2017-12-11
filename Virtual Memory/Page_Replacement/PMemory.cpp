#include <iostream>
using namespace std;

class PMemory {
private:
	static PMemory* instance;
	int framecount = 100;
	int frameused = 0;
	int frameleft = framecount - frameused;
	int *map;
	int *usedmap;
	int *leftmap;

	PMemory::PMemory() { }
	PMemory::PMemory(int size) { }

public:
	void resetMemory() {
		map = new int[framecount];
		for (int i = 0; i < framecount; i++) {
			map[i] = 0;
		}
	}

	void putPage(int& at) {
		map[at] = 1;
		frameused++;
		frameleft--;
	}

	void rmvPage(int & at) {
		map[at] = 0;
		frameused--;
		frameleft++;
	}

	void printMemoryStatus() {
		cout << "Physical Memory Status || " << "Frame Count : " << framecount << " Frame Left : " << frameleft << " Frame Used : " << frameused << endl;
	}

	void setMemorySize(int setsize) {
		framecount = setsize;
	}

	int getMemorySize() {
		return framecount;
	}
	int getUsedSize() {
		return frameused;
	}
	int getLeftSize() {
		return frameleft;
	}
	int* getMemoryMap() {
		return map;
	}

	static PMemory* getinstance() {
		if (!instance) {
			instance = new PMemory();
		}
		return instance;
	}
	static void createInstance() {
		instance = 0;
	}
};
