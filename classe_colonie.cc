#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "classe_colonie.h"

using namespace std;

//methodes de position

//methodes de colonie
colonie::colonie(std::string nom, double superficie, double longitude, double latitude)
:nom(nom), superficie(superficie)
{
	latitude  *= Pi/180;
	longitude *= Pi/180;
	x = RAYON_TERRE * cos(latitude) * cos(longitude);
	y = RAYON_TERRE * cos(latitude) * sin(longitude);
	z = RAYON_TERRE * sin(latitude);
}


position colonie::get_coordonees_spheriques()const{
	double r, longitude, latitude;
	
	r = sqrt((x*x) + (y*y) + (z*z));
	latitude  = asin(z/r);
	longitude = atan2( y, x );
	
	position p(r, longitude, latitude);
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
double s, xs, ys, zs;
s = superficie + autre.get_s();
xs = (x*superficie + autre.get_x()*autre.get_s())/s;
ys = (y*superficie + autre.get_y()*autre.get_s())/s;
zs = (z*superficie + autre.get_z()*autre.get_s())/s;

colonie sortie(nom, s, xs, ys, zs);
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
	
	sortie 	<< "longitude : " << p.get_longitude()*180/Pi << " , "
			<< "latitude : " << p.get_latitude()*180/Pi << " , "
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
