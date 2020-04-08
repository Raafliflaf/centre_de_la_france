#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> TEXTE_INFORMATION;
void initialise_info(){
	TEXTE_INFORMATION.push_back("Ce programme est concu pour calculer le barycentre d'un ensemble  de territoires definis par leur position et leur surface.");
	TEXTE_INFORMATION.push_back("La convention utilisée pour entrer manuellement un territoire est :");
	TEXTE_INFORMATION.push_back("{nom, latitude(en degres (decimaux)), longitude(en degres), superficie(en km2)}");
	TEXTE_INFORMATION.push_back("La convention utilisee pour ecrire un fichier contenant des territoires est :");
	TEXTE_INFORMATION.push_back("Pour les angles decimaux :");
	TEXTE_INFORMATION.push_back("#");
	TEXTE_INFORMATION.push_back("nom");
	TEXTE_INFORMATION.push_back("superficie");
	TEXTE_INFORMATION.push_back("longitude");
	TEXTE_INFORMATION.push_back("latitude");
	TEXTE_INFORMATION.push_back("");
	TEXTE_INFORMATION.push_back("Paur les angles sextadecimaux : ");
	TEXTE_INFORMATION.push_back("$");
	TEXTE_INFORMATION.push_back("nom");
	TEXTE_INFORMATION.push_back("superficie");
	TEXTE_INFORMATION.push_back("longitude : degres sur 3 chiffres, minutes sur 2 chiffres, secondes sur 2 chiffres");
	TEXTE_INFORMATION.push_back("latitude idem");
	TEXTE_INFORMATION.push_back("");

}


ostream& operator<<(ostream& sortie, std::vector<std::string> const& texte){
	sortie << endl;
	for(auto ligne : texte){
		sortie << ligne << endl;
	}
	return sortie;
}


