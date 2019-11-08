/*
 * Simulation.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include "Simulation.h"
#include "Processus.h"
#include <vector>
using namespace std;

Simulation& Simulation::simulation() {
	static Simulation sim;
	return sim;
}

Simulation::Simulation():tick(0) {
}

void Simulation::initialise(vector<Processus*> liste, unsigned int tick_in) {
	list_processus = liste;
	tick = tick_in;
}

Simulation::~Simulation() {

}
