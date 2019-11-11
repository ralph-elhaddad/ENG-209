/*
 * Parseur.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: pcoo6
 */

#include <iostream>
#include "tinyxml2/tinyxml2.h"
#include "Parseur.h"
#include "Etat.h"
#include "Controleur.h"
#include "Phenomene.h"
#include "Processus.h"
#include "Serveur.h"
#include <vector>
using namespace std;
using namespace tinyxml2;
using namespace tinyxml2_utils;


Parseur::Parseur(const std::string xml_file_in): xml_file_name(xml_file_in), tick(0) {
	cout << 1 << endl;
this->xml_parser();
}

void Parseur::xml_parser() {

   // load XML file and create DOM
	cout << 2 << endl;
   XMLDocument dom;  // DOM
   dom.LoadFile(xml_file_name.c_str());
   cout << 3 << endl;
   // check if load was successful

   if (dom.ErrorID()) {
	   cout << 4 << endl;
      throw string("Incorrect XML file '" + xml_file_name + "'\n" + dom.ErrorStr());
      cout << 5 << endl;
   }
   else cout << "XML file '" << xml_file_name << "' and DOM OK." << endl;


   // Visit all zone elements and create every objects

   XMLElement* p_root = dom.RootElement();

   cout << "Landscape" << endl;
   for (auto p_elem = p_root->FirstChildElement("zone"); p_elem;
             p_elem = p_elem->NextSiblingElement("zone")) {

      int id(get_elem_dbl(p_elem, "id"));
      XMLElement* p_phen(get_elem(p_elem, "phenomene")); //! Try and Catch ??
	  XMLElement* p_etat(get_elem(p_elem, "etat"));
	  XMLElement* p_control(get_elem(p_elem, "controleur"));
	  Etat* etat = new Etat(id, p_etat);
	  Serveur serv = Serveur::serveur();
	  Controleur* controleur = new Controleur(id, etat, p_control, &serv);
	  Phenomene* phenomene = new Phenomene(id, etat, p_phen);
	  list_processus.push_back(phenomene);
	  list_processus.push_back(controleur);
	  list_processus.push_back(etat);
   }
   XMLElement* p_serv(p_root->FirstChildElement("serveur"));
   tick = get_elem_dbl(p_serv, "nb_tick");
}
vector <Processus*> Parseur::get_vecteur(){
	return list_processus;
}
unsigned int Parseur::get_tick(){
	return tick;
}

Parseur::~Parseur() {
}
