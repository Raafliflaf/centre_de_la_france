#include <iostream>
#include <vector>
#include <string>
#include "classe_colonie.h"
#include "gestion_donees.h"

using namespace std;

	int main() {
	
	vector<colonie> Liste;
	entrer_colonie(Liste);
	
	colonie barycentre(moyenne_liste(Liste));	
	cout << barycentre;
	
	Liste.push_back(barycentre);
	sauvegarder(Liste, "liste.txt");
	return 0;
	
}
