CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall

all:calcul_du_centre_de_la_france
calcul_du_centre_de_la_france:calcul_du_centre_de_la_france.o classe_colonie.o gestion_donnees.o libgcc_s_dw2-1.dll

calcul_du_centre_de_la_france.o: calcul_du_centre_de_la_france.cc \
 classe_colonie.h gestion_donees.h
classe_colonie.o: classe_colonie.cc classe_colonie.h
fonction_moyenne.o: fonction_moyenne.cc classe_colonie.h
gestion_donnees.o: gestion_donnees.cc gestion_donees.h classe_colonie.h
