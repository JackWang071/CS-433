#pragma once
#ifndef PCB_Table_H
#define PCB_Table_H

#include <iostream>
#include <vector>
using namespace std;
#include "PCB.h"

class PCB_Table {
private:
	vector<PCB*> table;
public:
	bool newProcess(long id, int priority, long counter);
	PCB* getProcess(long id);
	bool endProcess(long id);

	void listAllProcesses();
};

#endif // !PCB_Table_H
