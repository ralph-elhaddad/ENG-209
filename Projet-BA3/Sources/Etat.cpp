/*
 * Etat.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include "Etat.h"
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;

Etat::Etat(int id_in, XMLElement* p_etat):
					Processus(id_in),
					val_before(get_elem_dbl(p_etat, "val_before")),
					val_now(0), val_phen(0), val_control(0),
					i_control(get_elem_dbl(p_etat, "i_control")),
					i_phen(get_elem_dbl(p_etat, "i_phen"))
{
}

Etat::~Etat() {
	// TODO Auto-generated destructor stub
}
