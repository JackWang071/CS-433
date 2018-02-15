#ifndef PCB_C
#define PCB_C

using namespace std;
#include "PCB.h"

//Default constructor
PCB::PCB() {
	state = State::NEW;
	ID = -1;
	priority = -1;
	counter = -1;
}

//Constructs a PCB with the given parameters for ID, priority, and program counter.
PCB::PCB(long id, int prior, long count) {
	state = State::NEW;
	ID = id;
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

//Checks that ID, priority, and counter are not default values.
bool PCB::canBeReady() {
	return ID >= 0 && priority >= 0 && counter >= 0;
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
			if (canBeReady()) {
				state = State::READY;
				return true;
			}
			return false;
		}
		//Option to terminate a process.
		else if (s == State::TERMINATED) {
			priority = -1;
		}
		state = s;
		return true;
	}
	return false;
}

//Returns the process state in string form.
string PCB::printState() {
	string str_state;
	//Switch sets the value of str_s depending on the State that s represents.
	switch (state) {
	case State::NEW: str_state = "NEW"; break;
	case State::READY: str_state = "READY"; break;
	case State::RUNNING: str_state = "RUNNING"; break;
	case State::WAITING: str_state = "WAITING"; break;
	case State::TERMINATED: str_state = "TERMINATED"; break;
	}
	return str_state;
}

//Prints the process's ID, current state, priority, and next instruction address.
void PCB::print() {
	cout << setw(12) << ID << setw(12) << printState() << setw(12) << priority << setw(12) << counter << endl;
}
#endif // !PCB_C
