#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> TEXTE_INFORMATION;
void initialise_info(){
	TEXTE_INFORMATION.push_back("Ce programme est concu pour calculer le barycentre d'un ensemble  de territoires définis par leur position et leur surface.");
	TEXTE_INFORMATION.push_back("La convention utilisée pour entrer manuellement un territoire est :");
	TEXTE_INFORMATION.push_back("{nom, latitude(en degrés), longitude(en degres), superficie(en km2)}");
	TEXTE_INFORMATION.push_back("La conventionutilisée pour ecrire un fichier contenant des territoires est :");
	TEXTE_INFORMATION.push_back("#");
	TEXTE_INFORMATION.push_back("nom");
	TEXTE_INFORMATION.push_back("superficie");
	TEXTE_INFORMATION.push_back("longitude");
	TEXTE_INFORMATION.push_back("latitude");
	TEXTE_INFORMATION.push_back("");
}


ostream& operator<<(ostream& sortie, std::vector<std::string> const& texte){
	sortie << endl;
	for(auto ligne : texte){
		sortie << ligne << endl;
	}
	return sortie;
}


