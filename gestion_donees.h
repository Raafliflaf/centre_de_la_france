#pragma once
#include <vector>
#include <string>
#include "classe_colonie.h"

void entrer_colonie(std::vector<colonie>& liste);

bool sauvegarder(std::vector<colonie> const& liste, std::string fichier);

std::vector<colonie> extraire(std::string const& fichier);
