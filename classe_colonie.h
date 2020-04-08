#pragma once

double const RAYON_TERRE(6371.009);
double const Pi(3.1415926535);

class position{
public:
	position(double r, double longitude, double latitude)
	:r(r), longitude(longitude), latitude(latitude)
	{}

private:
	double r, longitude, latitude; // en radiants
	
public:
	double get_longitude()const{ return longitude;}
	double get_latitude()const{ return latitude;}
	double get_r()const{ return r;}
};

class colonie{
public:
	colonie(std::string nom, double superficie, double x, double y, double z)
	: nom(nom), superficie(superficie), x(x), y(y), z(z)
	{}
	
	colonie(std::string nom, double superficie, double longitude, double latitude);	
	
	colonie(std::string nom = "")
	: nom(nom), superficie(0), x(0), y(0), z(0)
	{}
	
private:
	std::string nom;
	double superficie; 	// en km²
	double x, y, z;		// en km? 
	
public:
	double get_x()const{ return x; }
	double get_y()const{ return y; }
	double get_z()const{ return z; }
	position get_coordonees_spheriques()const;	
	double get_latitude()const;
	double get_longitude()const;
	double get_s()const{return superficie;}
	std::string get_nom()const{ return nom;}	
	colonie moyenne (colonie const& autre)const; // moyenne : soi et autre
	
};

// fonctions 

colonie moyenne_liste(std::vector<colonie> const& liste);

std::ostream& operator<<(std::ostream& sortie, position const& objet);
std::ostream& operator<<(std::ostream& sortie, colonie const& objet);
