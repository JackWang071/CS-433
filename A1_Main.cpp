#include <iostream>
using namespace std;
#include "PCB_Table.h"
#include "ReadyQueue.h"

//Conducts Test 1.
void test1(PCB_Table table1, ReadyQueue q1) {
	//Step a.
	q1.insertProc(table1.getProcess(5));
	q1.insertProc(table1.getProcess(1));
	q1.insertProc(table1.getProcess(8));
	q1.insertProc(table1.getProcess(11));
	q1.displayQueue();
	cout << endl;

	//Step b.
	q1.removeHighestProc();
	q1.displayQueue();
	cout << endl;

	//Step c.
	q1.removeHighestProc();
	q1.displayQueue();
	cout << endl;

	//Step d.
	q1.insertProc(table1.getProcess(3));
	q1.insertProc(table1.getProcess(7));
	q1.insertProc(table1.getProcess(2));
	q1.insertProc(table1.getProcess(12));
	q1.insertProc(table1.getProcess(9));

	//Step e: While loop empties q1.
	while (q1.size() > 0) {
		q1.removeHighestProc();
		q1.displayQueue();
		cout << endl;
	}
}

//Conducts Test 2.
void test2(PCB_Table table1, ReadyQueue q1) {
	PCB* insert;

	//While loop inserts ten random processes from table1 into q1.
	while (q1.size() < 10) {
		insert = table1.getProcess(rand() % 20 + 1);
		if (insert != NULL) {
			insert->setPriority(rand() % 50 + 1);	//Each process is assigned a new random priority.
			q1.insertProc(insert);
		}
	}

	bool allProcessesInserted = false;
	//Step a: For loop repeats this step 1,000,000 times to test the time efficiency of this implementation.
	for (int i = 0; i < 1000000; i++) {

		cout << i << endl;

		//Step options are randomly selected, each option has a 50% chance of being selected.
		//Option 1: Remove the highest-priority process.
		if (rand() % 2 == 0) {
			q1.removeHighestProc();
			allProcessesInserted = false;
		}
		//Option 2: Insert into q1 a random process from table1.
		else if (!allProcessesInserted) {
			//For loop searches through table1 to find a process that has not already been inserted into q1.
			for (int i = 0; i < 20; i++) {
				insert = table1.getProcess(i);
				if (insert != NULL) {
					insert->setPriority(rand() % 50 + 1);
					q1.insertProc(insert);
					break;
				}
				else if (i == 19) {
					allProcessesInserted = true;
				}
			}

		}
	}

	q1.displayQueue();
}

void main() {
	cout << "Jack Wang - CS 433 - Programming Assignment 1" << "\n" << endl;

	PCB_Table table1;
	ReadyQueue q1;
	//Initializes table1 with twenty processes.
	for (int i = 1; i <= 20; i++) {
		table1.newProcess(i, i, i + 1000);	//Priority value will be the same as process ID.
	}

	test1(table1, q1);

	test2(table1, q1);

	cout << "Program end." << endl;
	cin.get();
}