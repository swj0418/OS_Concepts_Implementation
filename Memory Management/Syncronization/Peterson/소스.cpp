#include <iostream>
using namespace std;

class job_1 {
public:
	job_1() {

	}
	~job_1() {

	}
	void task() {
		cout << "job_1 executing" << endl;
	}
};

class job_2 {
public:
	job_2() {

	}
	~job_2() {

	}
	void task() {
		cout << "job_2 executing" << endl;
	}

};

void main() {
	int turn;
	int i = 0;
	int j = 1;
	job_1 j1;
	job_2 j2;
	bool flag[2];
	for (int i = 0; i < 2; i++) {
		flag[i] = false;
	}

	do {
		flag[i] = true;
		turn = j;
		while (flag[j] && turn == j);

		j1.task();

		flag[i] = false;

	} while (true);

}