#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;

class PageTable {
private:
	const int tablesize = 100;
	int Architecture = 32;
	int pagenumber = 20;
	int pageoffset = 12;
	string table[100];

public:
	PageTable() {
		for (int i = 0; i < tablesize; i++) {
			table[i] = "00000000000000000000000000000000";
			/*00000000000000000000000000000000*/
		}
	}

	void showTable() {
		for (int i = 0; i < tablesize; i++) {
			cout << table[i] << endl;
		}
	}

	int getPageNumber() {
		return pagenumber;
	}
	int getPageOffset() {
		return pageoffset;
	}
	int getArchitecture() {
		return Architecture;
	}
	void setTable(const int& loc, const string& address) {
		table[loc] = address;
	}
};