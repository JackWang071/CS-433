#pragma once
#ifndef PCB_H
#define PCB_H

#include <iostream>
using namespace std;

//Five possible states for process
enum State { NEW, READY, RUNNING, WAITING, TERMINATED };

//Process Control Block class
class PCB {
protected:
	long ID;		//process ID
	State state;	//current state, starts as NEW and ends as TERMINATED
	int priority;	//priority for execution
	long counter;	//address of next instruction

	// may also have other attributes, such as CPU Registers, Memory-management information, I/O status information, etc. 
	// For purposes of simplicity, these other attributes will not be accounted for here

public:
	static PCB newProcess(long id, int p, long c);

	PCB();
	PCB(long id, int prior, long count);

	long getID();
	void setID(long id);
	int getPriority();
	void setPriority(int p);
	long getCounter();
	void setCounter(long count);

	bool confirmReady();
	void endProcess();

	State getState();
	bool setState(State s);
};

#endif // !PCB_H
