#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>  // double atof(string)

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
		sortie.close();
		return false;
		
	} else {
		for(auto c : liste){
			// ajout d'un element c de la liste
			sortie << '#' << endl; // séparateur
			sortie << c.get_nom() << endl;
			sortie << c.get_s() << endl;
			sortie << c.get_longitude() << endl;
			sortie << c.get_latitude() << endl;
			
		}
		sortie.close();
		return true;
	}
}


	enum {SEPARATEUR, NOM, SUPERFICIE, LONGITUDE, LATITUDE, LONGUEUR_ENUM};
vector<colonie> extraire(string const& fichier){
	ifstream entree(fichier);
	vector<colonie> liste;
	
	if(entree.fail()){
		cerr << "echec de l'ouverture du fichier : " << fichier << endl;
		entree.close();
	
		return liste; // retourne une liste vide
	} else {
		string ligne;
		while(not entree.eof()){
			
			string nom;
			double superficie, longitude, latitude;
			
			getline(entree, ligne);
			if(ligne[0] == '#'){ // tout va bien, sinon on continue a chercher le separateur
				
				getline(entree, ligne);
				nom = ligne;
				
				getline(entree, ligne);
				superficie = atof(ligne.c_str()); // Il faut utiliser la methode c_str() du type string (transformer le string en Cstring) pour que la foncion atof() fonctionne
				
				getline(entree, ligne);
				longitude = atof(ligne.c_str());
				
				getline(entree, ligne);
				latitude = atof(ligne.c_str());
				
				colonie c(nom, superficie, longitude, latitude);
				liste.push_back(c);
			}

		}
		return liste;
	}
}
























