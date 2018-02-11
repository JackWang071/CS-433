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
	PCB_Table();
	bool newProcess(long id, int priority, long counter);
	PCB* getProcess(long id);
	bool endProcess(long id);
};

#endif // !PCB_Table_H