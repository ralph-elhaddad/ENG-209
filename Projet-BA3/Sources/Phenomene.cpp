/*
 * Phenomene.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include "Phenomene.h"
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;
using namespace tinyxml2_utils;
using namespace std;
using namespace std;

Phenomene::Phenomene(int id_in, Etat* etat_in, XMLElement* p_phen):
				Processus(id_in),
				etat(etat_in),
				sup(get_elem_dbl(p_phen, "born_sup")),
				inf(get_elem_dbl(p_phen, "born_inf")),
				val(get_elem_dbl(p_phen, "val_phen"))
				{
	// TODO Auto-generated constructor stub
}

Phenomene::~Phenomene() {
}
