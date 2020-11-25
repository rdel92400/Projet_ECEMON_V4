//
// Created by charles on 25/11/2020.
//

#ifndef PROJET_ECEMON_V4_ALLEGRO_H
#define PROJET_ECEMON_V4_ALLEGRO_H

#endif //PROJET_ECEMON_V4_ALLEGRO_H

#include "Principal.h"

void iniTabCollectionCreature(int miseEnPage[4][5][3]);
void iniTabCollectionEnergie(int miseEnPage[3][4][3]);

void erreur(const char* titre, const char* txt);
ALLEGRO_BITMAP* chargement(const std::string& nomImage);
ALLEGRO_FONT* chargementPolice(const std::string& nomImage,int size);
std::map<std::string,ALLEGRO_BITMAP*> chargementBitmaps();
void destructionBitmaps(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void regles(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);

std::string iniNom(ALLEGRO_BITMAP* fond);