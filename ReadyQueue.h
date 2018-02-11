#pragma once
#ifndef ReadyQueue_H
#define ReadyQueue_H

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#include "PCB_Table.h"

class ReadyQueue {
private:
	vector<PCB*> Queue;
	PCB* runningProcess;

public:
	ReadyQueue();
	PCB* removeHighestProc();
	bool insertProc(PCB* p);
	int size();
	void displayQueue();

};

#endif // !ReadyQueue_H