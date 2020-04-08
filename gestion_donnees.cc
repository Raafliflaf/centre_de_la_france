#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "gestion_donees.h"

using namespace std;

void entrer_colonie(vector<colonie>& liste){
	string nom;
	double longitude, latitude, superficie;
	bool continuer(true);
	int n(0);
	do{
		++n;
		cout << "nouvelle colonie n" << n << endl
		<< "nom (fin pour terminer) : ";
		cin >> nom;
			if(nom == "fin"){
				continuer = false;
				break;
			}
		cout << "longitude : ";
		cin >> longitude;
		cout << "latitude :";
		cin >> latitude;		
		cout << "superficie :";
		cin >>superficie;
		
		liste.push_back(colonie(nom, superficie, longitude, latitude));
	}while(continuer);
	return;
}


bool sauvegarder(std::vector<colonie> const& liste, std::string fichier){
	ofstream sortie(fichier);
	
	if(sortie.fail()){
		cerr << "echec de la creation du fichier : " << fichier << endl;
		return false;
		
	} else {
		sortie << '#' << endl;
		for(auto c : liste){
			// ajout d'un element c de la liste
			sortie << c.get_nom() << endl;
			sortie << c.get_s() << endl;
			sortie << c.get_longitude() << endl;
			sortie << c.get_latitude() << endl;
			sortie << '#' << endl; // séparateur
		}
		sortie.close();
		return true;
	}
}

std::vector<colonie> extraire(std::string const& fichier);
























