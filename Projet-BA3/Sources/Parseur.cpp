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
#include <vector>
using namespace std;
using namespace tinyxml2;
using namespace tinyxml2_utils;


Parseur::Parseur(const std::string xml_file_in): xml_file_name(xml_file_in), tick(0) {
xml_parser();
}

void Parseur::xml_parser() {

   // load XML file and create DOM

   XMLDocument dom;  // DOM
   dom.LoadFile(xml_file_name.c_str());

   // check if load was successful

   if (dom.ErrorID())
      throw string("Incorrect XML file '" + xml_file_name + "'\n" + dom.ErrorStr());
   else cout << "XML file '" << xml_file_name << "' and DOM OK." << endl;

   // Visit all zone elements and create every objects

   XMLElement* p_root = dom.RootElement();
   cout << "Landscape" << endl;
 /*
   for (auto p_elem = p_root->FirstChildElement("zone"); p_elem;
             p_elem = p_elem->NextSiblingElement("zone")) {

      int id(p_elem->Attribute("id"));
      XMLElement* p_phen(p_elem->FirstChildElement("phenomene"));
	  XMLElement* p_etat(p_elem->FirstChildElement("etat"));
	  XMLElement* p_control(p_elem->FirstChildElement("controleur"));
	  Etat* etat(id, p_etat);
	  Controleur* controleur(id, etat, p_control);
	  Phenomene* phenomene(id, etat, p_phen);
	  list_processus.push_back(phenomene);
	  list_processus.push_back(controleur);
	  list_processus.push_back(etat);
   }
   XMLElement* p_serv(p_root->FirstChildElement("serveur"));
   tick = p_serv->Attribute("nb_tick");*/
}
vector <Processus*> Parseur::get_vecteur(){
	return list_processus;
}
unsigned int Parseur::get_tick(){
	return tick;
}

Parseur::~Parseur() {
}
