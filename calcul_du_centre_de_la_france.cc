#include <iostream>
#include <vector>
#include <string>
#include "classe_colonie.h"
#include "gestion_donees.h"
#include "information.cc"

using namespace std;

enum{FIN, EXTRAIRE, ENTRER, BARYCENTRE, LISTE, ENREGISTRER, AIDE};

bool menu(vector<colonie>& liste){
	string fichier;
	int n(0);
	
	cout << "MENU" << endl;
	cout 	<< "1 	pour extraire des donées d'un fichier texte" << endl
			<< "2 	pour ajouter des territoires à liste de territoires" << endl
			<< "3 	pour afficher le barycentre des territoires de la liste" << endl
			<< "4 	pour afficher la liste" << endl
			<< "5	pour enregistrer la liste dans un fichier texte" << endl
			<< "6 	pour afficher l'information sur le programme" << endl	
			<< "0 	pour sortir du programme" << endl;	
	
	int commande;
	cin >> commande;
	switch(commande){
		case EXTRAIRE:
			n = liste.size();
			cout << endl << "nom du fichier : ";
			cin >> fichier;
			if(extraire(fichier, liste)){
				cout << liste.size() - n << " territoires ont étés extraits du fichier " << fichier << "." << endl;
			}
			return true;
		break;
		
		case ENTRER:
			n = liste.size();
			cout << endl;
			if(entrer_colonie(liste)){
				cout << liste.size() - n << " territoires ont étés ajoutés à la liste." << endl;
			}
			return true;		
		break;
		
		case BARYCENTRE:
			cout << endl << "Le barycentre de la liste est : " << endl
				<< moyenne_liste(liste) << endl;
			return true;		
		break;
		
		case LISTE:
			cout << endl << "Liste des territoires : " << endl
				<< liste << endl;
			return true;
		break;

		case ENREGISTRER:
			cout << endl << "Nom du fichier :";
			cin >> fichier;
			if(sauvegarder(liste, fichier)){
				cout << "La liste à été sauvegardée." << endl;
			}
			return true;
		break;
		
		case AIDE:
			cout << TEXTE_INFORMATION;
			return true;
		break;
		
		case FIN:
			return false;
		break;
		default:
			cout << endl << "Commande invalide." << endl;
			return true;
		break;
	}
	cerr << "c'est pas normal le swich du menu a ete dépassé" << endl;
	return false;
}

int main() {
	initialise_info();
	vector<colonie> liste;
	while(menu(liste)){}	
	return 0;
}
