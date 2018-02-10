#ifndef PCB_C
#define PCB_C

using namespace std;
#include "PCB.h"

//Automatically gives a new process a unique ID.
long PCB::IDgenerator = 1000;

//Default constructor
PCB::PCB() {
	state = State::NEW;
	IDgenerator++;
	ID = IDgenerator;
	priority = -1;
	counter = -1;
}

//Constructs a PCB with the given parameters for ID, priority, and program counter.
PCB::PCB(long id, int prior, long count) {
	state = State::NEW;
	IDgenerator++;
	ID = IDgenerator;
	priority = prior;
	counter = count;
}

//Setters and getters for ID, priority, and counter.
long PCB::getID() {
	return ID;
}
void PCB::setID(long id) {
	ID = id;
}
int PCB::getPriority() {
	return priority;
}
void PCB::setPriority(int p) {
	priority = p;
}
long PCB::getCounter() {
	return counter;
}
void PCB::setCounter(long count) {
	counter = count;
}

//Kills the current process.
void PCB::terminate() {
	state = State::TERMINATED;
	priority = -1;
}

//Returns the current state
State PCB::getState() {
	return state;
}

//Modifier for the process state.
bool PCB::setState(State s) {
	
	//Check that the process has not already been terminated.
	if (state != State::TERMINATED) {
		//If the state is to be set to READY, check whether ID, counter, and priority all have valid values.
		if (s == State::READY) {
			//Return true if ID, counter, and priority all have valid values.
			if (ID >= 0 && priority >= 0 && counter >= 0) {
				state = State::READY;
				return true;
			}
		}
		else {
			state = s;
			return true;
		}
	}
	return false;
}

//Prints the process's ID, current state, priority, and next instruction address.
void PCB::print() {
	cout << setw(12) << ID << setw(10) << state << setw(10) << priority << setw(12) << counter << endl;
}
#endif // !PCB_C
