#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

class Process {
public:
	int pro_id;
	int pro_size;

	int pro_bottom;
	int pro_top;

	Process() {};
	Process(int size, int id) {
		this->pro_size = size;
		this->pro_id = id;

		//cout << "Process Created " << pro_id << endl;
	}
	~Process() {
	}

	void memloc(int bottom, int top) {
		this->pro_bottom = bottom;
		this->pro_top = top;
	}
};

class Memory {
public:
	int m_size = 1000;
	int M[1000]; // memory size 100 for now.
	bool checker = false;

	Memory() {
		cout << "Memory Created" << endl;
	}

	void append(int process_size, Process& p) {
		checker = false;

		for (int i = 0; i < 1000; i++) {
			int tmpsize = 0; // To check memory sector availability
			if (checker == false) {
				for (int k = i; k < i + process_size; k++) {
					if (M[k] == 1) {
						checker = false;
						break;
					}
					else if(M[k] == 0){
						tmpsize++;
					}

					if (tmpsize == process_size) {
						p.pro_bottom = i;
						p.pro_top = i + p.pro_size - 1;
						checker = true;
						continue;
					}
					else if (1000 - i < p.pro_size) {
						cout << "================================CANNOT WRITE " << p.pro_id << " ===============================" << endl;
						return;
					}
				}
			}
			if (checker == true && i == p.pro_top + 1) {
				cout << "Writing complete" << endl; break;
			}
			else if (checker == true && i <= p.pro_top) {
				M[i] = 1;
			}
		}
	}

	void pop(int process_size, int top, int bottom) {
		for (int i = bottom; i <= top; i++) {
			M[i] = 0;
		}
	}

	void print_memory_status() {
		for (int i = 0; i < 10; i++) {
			for (int k = i * 100; k < (i * 100) + 100; k++) {
				cout << M[k] << " ";
			}
			cout << endl;
		}
	}
};

void main() {
	//Memory declaration
	Memory M;
	Memory* ptr_M;
	ptr_M = &M;

	//Initialize the memory. Size 100. 0 == empty 1 == true.
	for (int i = 0; i < 1000; i++) {
		ptr_M->M[i] = 0;
	}
	//Printing the initial memory status
	ptr_M->print_memory_status();

	//Process Array and itration number
	Process p[1000];
	int process_itr = 0;

	//Random number variables declaration
	int randsize_1;
	int randsize_2;
	int randsize_3;

	int round = -1; // To count how many rounds undertaken

	bool control = false;
	do {
		round++;

		srand(time(NULL));
		randsize_1 = rand() % 80 + 1;
		srand(time(NULL) + 1);
		randsize_2 = rand() % 80 + 1;
		srand(time(NULL) + 2);
		randsize_3 = rand() % 80 + 1;

		//Creating Processes
		p[process_itr] = Process(randsize_1, process_itr);
		ptr_M->append(randsize_1, p[process_itr]);
		process_itr++;
		p[process_itr] = Process(randsize_2, process_itr);
		ptr_M->append(randsize_2, p[process_itr]);
		process_itr++;
		p[process_itr] = Process(randsize_3, process_itr);
		ptr_M->append(randsize_3, p[process_itr]);
		process_itr++;
		
		//Random number for removing random processes
		srand(time(NULL) + 5);
		int rand_rmv = rand() % 3 + 1;
		srand(time(NULL) + 10);
		int rand_rmv_2 = rand() % 3 + 1;

		cout << "Before removing process " << p[process_itr - rand_rmv].pro_id << " and " << p[process_itr - rand_rmv_2].pro_id << " " << endl;
		ptr_M->print_memory_status();

		//Checking Memory Usage
		cout << "Process ID : " << p[process_itr - 3].pro_id << " Process Size : " << p[process_itr - 3].pro_size << " Bottom : " << p[process_itr - 3].pro_bottom << 
			" Top : " << p[process_itr - 3].pro_top << endl;
		cout << "Process ID : " << p[process_itr - 2].pro_id << " Process Size : " << p[process_itr - 2].pro_size << " Bottom : " << p[process_itr - 2].pro_bottom <<
			" Top : " << p[process_itr - 2].pro_top << endl;
		cout << "Process ID : " << p[process_itr - 1].pro_id << " Process Size : " << p[process_itr - 1].pro_size << " Bottom : " << p[process_itr - 1].pro_bottom <<
			" Top : " << p[process_itr - 1].pro_top << endl;

		//Appending Processes to a memory
		ptr_M->pop(p[process_itr - rand_rmv].pro_size, p[process_itr - rand_rmv].pro_top, p[process_itr - rand_rmv].pro_bottom);
		ptr_M->pop(p[process_itr - rand_rmv_2].pro_size, p[process_itr - rand_rmv_2].pro_top, p[process_itr - rand_rmv_2].pro_bottom);


		cout << "After removing processes" << endl;
		ptr_M->print_memory_status();


		cout << "Continue?   "; cin >> control; // 0 -> continue     1 -> quit
	} while (control == false);
}