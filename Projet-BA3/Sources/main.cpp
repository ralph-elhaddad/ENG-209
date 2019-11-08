/*
 * main.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */
#include "Parseur.h"
#include "Simulation.h"
using namespace std;

int main() {
	Parseur parseur("fichier.xml");
	Simulation& sim = Simulation::simulation();
	sim.initialise(parseur.get_vecteur(), parseur.get_tick());
	return 0;
}


