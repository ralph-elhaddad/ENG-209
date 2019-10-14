
#include "Parking.h"
#include <iostream>
constexpr double CHARGE_MAX(10);

namespace Parking {

void Parking::check_in(Vehicule* entree){
	etat();
	if (!etat_plein){//!s'il reste au moins une place
		if(entree->get_camion()){ //!si c'est un camion
			if(entree->get_charge_utile() > CHARGE_MAX){ //!comparer charge utile
				std::cout << "Votre camion est trop lourd pour entrer!"
						    << std::endl;
				return;
			}
			++nb_camion;
			std::cout<<"Le camion ";
		}else {
			++nb_voiture;
			std::cout<<"La voiture ";
		}
		nb_place_prise=nb_camion+nb_voiture;
		bool vehicule_in(false);
		size_t i(0);
		while(!vehicule_in and i<nb_place_max){
			if (place[i] == nullptr){
				place[i] = entree;
				vehicule_in = true;
			}else ++i;
		};
		std::cout<<"de numero de plaque "<<entree->get_plaque()
				   <<" a ete accepte(e) au parking."<<std::endl;
	}
}

void Parking::check_out(Vehicule* sortie){
	if (nb_place_prise==0){
		std::cout<<"Le parking est déjà vide!"<<std::endl;
	}else{
		bool out(false);
			for(size_t i(0); i < nb_place_max; ++i){
				if (place[i] == sortie){
					place[i] = nullptr;
					out = true;
				}
			}
			if (out) {
				std::cout << "Le vehicule de plaque "
					       <<sortie->get_plaque()
					       <<" a ete libere" << std::endl;
				if(sortie->get_camion()) --nb_camion;
				else --nb_voiture;
				nb_place_prise=nb_camion+nb_voiture;
			}else{
				std::cout << "Le vehicule de plaque "
							       <<sortie->get_plaque()
							       <<" n'est pas dans ce parking" << std::endl;
			}
	}
}

void Parking::check_out(size_t i){
	if(i >= nb_place_max){
		std::cout<<"La place " << i << " n'existe pas."<<std::endl;
	}else{
		if(Parking::place[i] != nullptr){
				std::cout << "La place " << i <<" a été libérée du véhicule de plaque "
							       <<Parking::place[i]->get_plaque() << std::endl;
				if(Parking::place[i]->get_camion()) --nb_camion;
				else --nb_voiture;
				nb_place_prise=nb_camion+nb_voiture;
				place[i] = nullptr;
			}else{
				std::cout<<"La place " << i << " est déjà libre"<<std::endl;
			}
	}
}

void Parking::etat(){
	size_t j(0);
	for(size_t i(0); i<nb_place_max; ++i){
		if (!(place[i] == nullptr)) ++j;
		//!std::cout << "nb places prises=" << j<<std::endl;
	}
	nb_place_prise = j;
	if (nb_place_prise == nb_place_max){
		etat_plein = true;
		std::cout << "Le parking est plein!" << std::endl;
	}
	else{
		etat_plein = false;
		std::cout << "Il reste encore " << nb_place_max - nb_place_prise
				<< " place(s) dans le parking" << std::endl;
	}
	std::cout << "Il y a " << nb_voiture << " voiture(s) et "
		<< nb_camion << " camion(s) dans le parking" << std::endl;
}


} /*! namespace Parking */
