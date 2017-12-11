#include <iostream>
#include "PageTable.h"
#include "PageTable.h"
using namespace std;

class Process {
private:
	int PID;
	int sizeinbyte;
	int pagecount;
	PageTable table;

public:
	Process() {}
	Process(const int& ID) {
		this->PID = ID;
	}
	void setPageCount(const int& pagecount) {
		this->pagecount = pagecount;
	}

	void setProcessSize(const int& size) {
		this->sizeinbyte = size;
	}

	void setProcessID(const int& ID) {
		this->PID = ID;
	}

	int getPageCount() {
		return pagecount;
	}

	int getProcessSize() {
		return sizeinbyte;
	}
	int getProcessID() {
		return PID;
	}

	PageTable getPageTable() {
		return table;
	}

};