#ifndef ReadyQueue_C
#define ReadyQueue_C

using namespace std;
#include "ReadyQueue.h"

//Default constructor
ReadyQueue::ReadyQueue() {
	runningProcess = NULL;
}

//Returns the process with the highest priority. 
PCB* ReadyQueue::removeHighestProc() {
	//Check that the Queue is not empty.
	if (Queue.size() == 0) {
		return NULL;
	}
	//Only one running process is allowed at a time.
	if (runningProcess != NULL) {
		runningProcess->setState(State::WAITING);
	}
	//The Queue is designed so that if multiple processes have equal priority, these processes will be returned in order of insertion.
	runningProcess = Queue.front();
	Queue.erase(Queue.begin());
	runningProcess->setState(State::RUNNING);

	return runningProcess;
}

//Inserts a new process into the Queue, with priority determining the process's index position.
bool ReadyQueue::insertProc(PCB* p) {
	//Check if p is NULL or if p is already in the ReadyQueue or terminated.
	if (p == NULL || p->getState() == State::READY || p->getState() == State::TERMINATED) {
		return false;
	}

	p->setState(State::READY);
	Queue.push_back(p);
	int location = Queue.size() - 1;	//stores p's current location in the Queue
	int parent;	//stores the index of p's parent element
	PCB* temp;	//stores the process to be switched with p, if p's priority is greater

	//While loop places p into the proper level of the Queue, loop continues as long as p is not at the root.
	while (location != 0) {
		//Determining p's current parent node.
		parent = location / 2;
		if (location % 2 == 0) {
			parent--;
		}
		//If p has lower or equal priority compared to its parent, then it is in the correct level.
		if (Queue[parent]->getPriority() <= Queue[location]->getPriority()) {	//Lower priority value means that the process has a higher priority.
			break;
		}
		//Switching the positions of p and its parent.
		temp = Queue[parent];
		Queue[parent] = Queue[location];
		Queue[location] = temp;
		location = parent;
	}
	return true;
}

//Gives the current number of processes in the ReadyQueue.
int ReadyQueue::size() {
	return Queue.size();
}

//Prints the ID, priority, and program counter of every process in the ReadyQueue.
void ReadyQueue::displayQueue() {
	cout << "READY QUEUE" << endl;
	//Prints an error message if no processes are in the ReadyQueue.
	if (Queue.size() == 0) {
		cout << "No processes are in the ReadyQueue." << endl;
	}
	else {
		cout << "\t" << setw(12) << "Process ID" << setw(12) << "State" << setw(12) << "Priority" << setw(12) << "Counter" << endl;
		cout << "=========================================================================" << endl;
		//For loop prints all processes.
		for (int i = 0; i < Queue.size(); i++) {
			cout << i << "\t";
			Queue[i]->print();
		}
	}
}

#endif // !ReadyQueue_C
