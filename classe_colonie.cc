#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "classe_colonie.h"

using namespace std;

//methodes de position

//methodes de colonie
colonie::colonie(std::string nom, double superficie, double latitude, double longitude)
:nom(nom), superficie(superficie)
{
	longitude  *= Pi/180;		//on suppose que l'entree est en degres donc on convertit en radiants
	latitude *= Pi/180;
	x = RAYON_TERRE * cos(latitude) * cos(longitude);
	y = RAYON_TERRE * cos(latitude) * sin(longitude);
	z = RAYON_TERRE * sin(latitude);
}


position colonie::get_coordonees_spheriques()const{
	double r, latitude, longitude;
	
	r = sqrt((x*x) + (y*y) + (z*z));
	latitude  = asin(z/r)*180/Pi;		// retourne des angles en degrés
	longitude = atan2( y, x )*180/Pi;	// peut etre faux
	
	position p(r, latitude, longitude);
	return p;
}

double colonie::get_latitude()const{
	position p(get_coordonees_spheriques());
	return p.get_latitude();
}
double colonie::get_longitude()const{
	position p(get_coordonees_spheriques());
	return p.get_longitude();
}

colonie colonie::moyenne(colonie const& autre)const{
// moyenne : soi et autre
double s_, x_, y_, z_;
s_ = superficie + autre.get_s();
x_ = (x*superficie + autre.get_x()*autre.get_s())/s_;
y_ = (y*superficie + autre.get_y()*autre.get_s())/s_;
z_ = (z*superficie + autre.get_z()*autre.get_s())/s_;

colonie sortie(nom, s_, x_, y_, z_);
return sortie;
} 


// fonctions 

colonie moyenne_liste(std::vector<colonie> const& liste){
	colonie barycentre("barycentre");
	for(auto c : liste){
		barycentre = barycentre.moyenne(c);
	}
	return barycentre;
}


std::ostream& operator<<(std::ostream& sortie, position const& p){
	double d;
	if(abs(RAYON_TERRE - p.get_r()) < 1){ d = 0;}
	else{d = RAYON_TERRE - p.get_r(); }
	
	sortie 	<< "latitude : " << p.get_latitude() << " , "
			<< "longitude : " << p.get_longitude() << " , "
			<< "profondeur : "<< d;
	return sortie;
}

std::ostream& operator<<(std::ostream& sortie, colonie const& c){
	position p(c.get_coordonees_spheriques());	
	sortie << c.get_nom() << std::endl
		//	<< c.get_x() << c.get_y << c.get_z;
	<< p << std::endl; 
	return sortie;
}

std::ostream& operator<<(std::ostream& sortie, std::vector<colonie> const& liste){
	for(auto c : liste){
		sortie << c << endl;
	}
	return sortie;
}

