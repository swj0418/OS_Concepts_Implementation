#include <iostream>
#include <math.h>
#include "PMemory.h"
#include "Process.h"
#include "PageTable.h"
using namespace std;

class Pager {
private:
	static Pager *pager;
	int pagesize = (int)pow(2, 12); //4096

public:
	static Pager *getPager() {
		if (!pager) {
			pager = new Pager();
		}
		return pager;
	}

	int getPagesize() {
		return pagesize;
	}
	/* Page size setting will have to be changed inside the code;
	void setPagesize(const int& pagesize) {
		this->pagesize = pagesize;
	}
	*/
	int calculatePageNeeded(const int& processsize) {
		if (processsize % pagesize == 0) {
			return processsize / pagesize;
		}
		else {
			return (processsize / pagesize) + 1;
		}
	}

	void giveProcessPMemory(Process *p) {
		p->setPageCount( calculatePageNeeded(p->getProcessSize()) );
		int* map = PMemory::getinstance()->getMemoryMap();
		int counter = p->getPageCount();

		//Standard Paging (Without Virtual Memory)
		if (PMemory::getinstance()->getLeftSize() < p->getPageCount()) {
			cout << "Unable to allocate to a physical memory" << endl;
		} else if(PMemory::getinstance()->getLeftSize() >= p->getPageCount()){
			for (int i = 0; i < PMemory::getinstance()->getMemorySize(); i++) {
				if ((map[i] == 0) && (!counter == 0)) {
					PMemory::getinstance()->putPage(i); // 1 Being used.
					counter--;
				} else if(counter == 0) {
					break;
				}
			}
		}
	}

	void createPageTable(Process *p) {
		PageTable table = p->getPageTable();

		int count = p->getProcessSize();
		int deduct = p->getProcessSize();
		while (0 != deduct) {
			int num = count - deduct;
			long power = table.getArchitecture();
			string numstr = "";
			while (!num == 0) {
				//cout << num << " " << power << "      " << pow(2, power) << "           " << numstr << endl;
				if (num < pow(2, power)) {
					numstr.append("0");
					power--;
					//continue;
				}
				else if (num >= pow(2, power)) {
					if (((num / (int)pow(2, power)) == 1)) {
						numstr.append("1");
						num = num - (int)pow(2, power);
						power--;
					}
					else if ((num / (int)pow(2, power)) == 0) {
						numstr.append("0");
						power--;
					}
				}
			}
			//cout << numstr << endl;
			p->getPageTable().setTable(deduct, numstr);
			deduct--;
		}
	}
};