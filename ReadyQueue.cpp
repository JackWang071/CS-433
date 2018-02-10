#ifndef ReadyQueue_C
#define ReadyQueue_C

using namespace std;
#include "ReadyQueue.h"

//Default constructor
ReadyQueue::ReadyQueue() {
	currentLevel = 0;
	widthSpanned = 0;
}

//Returns the process with the highest priority. 
PCB* ReadyQueue::removeHighestProc() {
	//Only one running process is allowed at a time.
	runningProcess = Queue.front();
	runningProcess->setState(State::RUNNING);
	return runningProcess;
}

//Inserts a new process into the Queue, with priority determining the process's index position.
void ReadyQueue::insertProc(PCB* p) {
	if (p != NULL && p.getState() == State::READY){
		Queue.push_back(p);
		int location = size() - 1;	//stores p's current location in the Queue
		int parent;
		PCB* temp;	//stores the process to be switched with p, if p's priority is greater

		//While loop places p into the proper level of the Queue.
		while (true) {
			//Determining p's current parent node.
			parent = location / 2;
			if (location % 2 == 0) {
				parent--;
			}
			//If p has a lower or equal priority than its parent, then it is in the correct level.
			if (Queue[parent]->getPriority() >= Queue[location]->getPriority()) {
				break;
			}
			//Switching the positions of p and its parent.
			temp = Queue[parent];
			Queue[parent] = Queue[location];
			Queue[location] = temp;
			location = parent;
		}
	}
}

//Gives the current number of processes in the ReadyQueue.
int ReadyQueue::size() {
	return Queue.size();
}

//Prints the ID, priority, and program counter of every process in the ReadyQueue.
void ReadyQueue::displayQueue() {
	cout << setw(12) << "Process ID" << setw(10) << "State" << setw(10) << "Priority" << setw(12) << "Counter" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < Queue.size(); i++) {
		Queue[i]->print();
	}
}

#endif // !ReadyQueue_C
