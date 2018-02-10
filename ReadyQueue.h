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

	int currentLevel;	//the current number of vertical levels in the heap
	int widthSpanned;	//the number of leaves occupied by processes

public:
	ReadyQueue();
	PCB* removeHighestProc();
	void insertProc(PCB* p);
	int size();
	void displayQueue();
};

#endif // !ReadyQueue_H
