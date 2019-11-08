/*
 * Simulation.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_SIMULATION_H_
#define SOURCES_SIMULATION_H_
#include "Processus.h"
#include <vector>
using namespace std;

class Simulation {
public:
	static Simulation& simulation();
	void initialise(vector<Processus*> liste, unsigned int tick_in);

private:
	Simulation();
	virtual ~Simulation();
	vector<Processus*> list_processus;
	unsigned int tick;
	Simulation& operator=(const Simulation&);
};

#endif /* SOURCES_SIMULATION_H_ */
