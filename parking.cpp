#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicule{
	protected:
		string plaque;
		size_t n_place; //N° dans la liste du parking
		bool parking; //vrai s'il est dans le parking
		
	public:
		Vehicule(string plaque_in): plaque(plaque_in), n_place(0), parking(false) {}
		void parking_in(size_t place); //Rentre dans le parking donc parking=true
		void parking_out();//met parking=false et n_place=0

};

class Camion : public Vehicule {
	private:
		double charge_utile;
	public:
	Camion(string plaque_in, double charge_utile_in): 
		Vehicule(plaque_in), charge_utile(charge_utile_in) {}
};

class Voiture : public Vehicule{
	private:
	public:
		Voiture(string plaque_in): Vehicule(plaque_in) {}
};


class Parking{
	private:
		size_t nb_place_max;
		size_t nb_place_prise;
		vector<Vehicule*> liste;//pointeurs??
		int nb_voiture;
		int nb_camion;
		bool etat_plein; //true si le parking est plein
	public:
		Parking(size_t max): nb_place_max(max), nb_place_prise(0), 
				nb_voiture(0), nb_camion(0), etat_plein(false) {
					for(size_t i(0); i < nb_place_max; ++i) {
						liste.push_back(nullptr);
					}
				}//parking vide avec max places

		~Parking(){}//doit détruire toutes les places et mettre tous les vehicules à parking false
		void check_in(Vehicule* entree);//rentre le vehicule si possible dans le parking
		void check_out(Vehicule* sortie);//sort le vehicule
		void etat();
};

void Parking::check_in(Vehicule* entree){
	etat();
	if (!etat_plein){//s'il reste au moins une place
		//déterminer si c'est un camion(<10T) ou une voiture
		bool vehicule_in(false);
		size_t i(0);
		do {
			if (liste[i] == nullptr){
				liste[i] = entree;
				vehicule_in = true;
			}
			++i;
		}while(!vehicule_in);

	}
}

void Parking::check_out(Vehicule* sortie){
	bool out(false);
	for(size_t i(0); i < nb_place_max; ++i){
		if (liste[i] == sortie){
			liste[i] = nullptr;
			out = true;
		}
	}
	if (out) cout << "Le vehicule est sorti" << endl;
}


void Parking::etat(){
	size_t j(0);
	for(size_t i(0); i<nb_place_max; ++i){
		if (liste[i] == nullptr) ++j;
	}
	nb_place_prise = j;
	if (nb_place_prise == nb_place_max){
		etat_plein = true;
		cout << "Le parking est plein" << endl;
	}
	else{
		etat_plein = false;
		cout << "Il reste encore " << nb_place_max - nb_place_prise 
				<< " places dans le parking" << endl;
	}
	cout << "Il y a " << nb_voiture << " voitures dans le parking et "
		<< nb_camion << " camions dans le parking" << endl;
}

int main() {
	
	return 0;
}
