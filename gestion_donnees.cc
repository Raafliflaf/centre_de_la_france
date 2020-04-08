#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>  // double atof(string)

#include "gestion_donees.h"

using namespace std;

bool entrer_colonie(vector<colonie>& liste){
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
	return true;
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


bool extraire(string const& fichier, vector<colonie>& liste){
	ifstream entree(fichier);
	
	if(entree.fail()){
		cerr << "echec de l'ouverture du fichier : " << fichier << endl;
		entree.close();
	
		return false; // retourne une liste vide
	} else {
		string ligne;
		while(not entree.eof()){
			
			string nom;
			double superficie, longitude(0), latitude(0);
			
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
			} else if (ligne[0] == '$'){
				getline(entree, ligne);
				nom = ligne;
				
				getline(entree, ligne);
				superficie = atof(ligne.c_str());
				
				getline(entree, ligne);
				minsec_vers_decimal(ligne, longitude);
				
				getline(entree, ligne);
				minsec_vers_decimal(ligne, latitude);

				colonie c(nom, superficie, longitude, latitude);
				liste.push_back(c);				
				}

		}
		entree.close();
		return true;
	}
}

bool minsec_vers_decimal(string ligne, double& nombre){
	nombre = 0;
	nombre += atoi(ligne.c_str());
		
	// enlever les 4 premiers char de la ligne
	ligne.replace(0, 4, "");
	nombre += atoi(ligne.c_str())/60.0 ;

	// enlever 3 char
	ligne.replace(0, 4, "");
	nombre += atoi(ligne.c_str())/3600.0;
	return true;
}	
























