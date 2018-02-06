#pragma once
#ifndef PCB_Table_H
#define PCB_Table_H

#include <vector>
using namespace std;
#include "PCB.h"


class PCB_Table {
private:
	vector<PCB*> table;
public:
	PCB_Table();

	PCB* findProcess(long ID);


	void listByID();
	void listByState();
	void listByPriority();
};

#endif // !PCB_Table_H
