#ifndef PCB_Table_C
#define PCB_Table_C

using namespace std;
#include "PCB_Table.h"

//Default constructor
PCB_Table::PCB_Table() {}

//Starts a new process with the given parameters.
bool PCB_Table::newProcess(long id, int priority, long counter) {
	//For loop checks if the PCB table contains another process with the same ID.
	for (int i = 0; i < table.size(); i++) {
		//If there is another process with the same ID, return false.
		if (table[i]->getID() == id) {
			return false;
		}
	}
	table.push_back(new PCB(id, priority, counter));
	return true;
}

//Returns the process with the given ID number.
PCB* PCB_Table::getProcess(long id) {
	//For loop tries to find a process with this ID number.
	for (int i = 0; i < table.size(); i++) {
		//If a process with a matching ID is found:
		if (table[i]->getID() == id) {
			return table[i];
		}
	}
	return NULL;
}

//Ends the process with the given ID number.
bool PCB_Table::endProcess(long id) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i]->getID() == id) {
			table[i]->setState(State::TERMINATED);
			return true;
		}
	}
	return false;
}
#endif // !PCB_Table_C