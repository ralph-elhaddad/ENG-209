/*
 * Etat.h
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#ifndef SOURCES_ETAT_H_
#define SOURCES_ETAT_H_

#include "Processus.h"
#include "xml_utils.h"  // utility functions
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;

class Etat: public Processus {
public:
	Etat(int id_in, XMLElement* p_etat);
	virtual ~Etat();
	void refresh() override;
private:
	double val_before;
	double val_now;
	double val_phen;
	double val_control;
	double i_control;
	double i_phen;
};

#endif /* SOURCES_ETAT_H_ */
