#include "classe_colonie.h"

colonie moyenne(vector<colonie> const& liste){
	colonie barycentre("barycentre");
	
	for(auto c : liste){
		barycentre.moyenne(c);
	}
	
	return barycentre;
}

