#ifndef PCB_C
#define PCB_C

using namespace std;
#include "PCB.h"

//Starts a new process.
PCB PCB::newProcess(long id, int p, long c) {
	return PCB(id, p, c);
}

//Default constructor
PCB::PCB() {
	state = State::NEW;
	ID = -1;
	priority = -1;
	counter = -1;
}

//
PCB::PCB(long id, int prior, long count) {
	state = State::NEW;
	ID = id;
	priority = prior;
	counter = count;
	confirmReady();
}

//Setters and getters for ID, priority, and counter.
long PCB::getID() {
	return ID;
}
void PCB::setID(long id) {
	ID = id;
	confirmReady();
}
int PCB::getPriority() {
	return priority;
}
void PCB::setPriority(int p) {
	priority = p;
	confirmReady();
}
long PCB::getCounter() {
	return counter;
}
void PCB::setCounter(long count) {
	counter = count;
	confirmReady();
}

//Checks whether ID, counter, and priority all have valid values, so that the process can be set to READY.
bool PCB::confirmReady() {
	if (ID >= 0 && priority >= 0 && counter >= 0) {
		setState(State::READY);
		return true;
	}
	return false;
}

//Kills the current process.
void PCB::endProcess() {
	state = State::TERMINATED;
	priority = -1;
}

//Returns the current state
State PCB::getState() {
	return state;
}

//If the current state is not TERMINATED, then change the state to the parameter.
bool PCB::setState(State s) {
	if (state != State::TERMINATED) {
		state = s;
		return true;
	}
	return false;
}
#endif // !PCB_C
