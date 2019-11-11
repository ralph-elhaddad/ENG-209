/*
 * Phenomene.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_PHENOMENE_H_
#define SOURCES_PHENOMENE_H_

#include "Processus.h"
#include "Etat.h"
#include "xml_utils.h"  // utility functions
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;
using namespace std;



class Phenomene: public Processus {
public:
	Phenomene(int id_in, Etat* etat_in, XMLElement* p_phen);
	virtual ~Phenomene();
	void refresh() override;
private:
	Etat* etat;
	double sup;
	double inf;
	double val;
};

#endif /* SOURCES_PHENOMENE_H_ */
