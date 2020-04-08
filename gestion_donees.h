#pragma once
#include <vector>
#include <string>
#include "classe_colonie.h"

bool entrer_colonie(std::vector<colonie>& liste);

bool sauvegarder(std::vector<colonie> const& liste, std::string fichier);

bool minsec_vers_decimal(std::string ligne, double& nombre);

bool extraire(std::string const& fichier, std::vector<colonie>& liste);
