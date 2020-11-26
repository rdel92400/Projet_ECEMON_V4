//
// Created by Romain on 21/11/2020.
//

#ifndef PROJET_ECEMON_V4_SAUVEGARDE_H
#define PROJET_ECEMON_V4_SAUVEGARDE_H

#endif //PROJET_ECEMON_V4_SAUVEGARDE_H

#include "principal.h"
#include "Joueur.h"

void sauvegardeJoueur (Joueur joueurRecu,Collections collection);
void RemplacedeJoueur(std::map<int,Joueur> joueursRecus, Collections collection);


Joueur chargementJoueur1(Collections collection, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);
Joueur chargementJoueur2(Collections collection, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, const std::string& nomJoueur1);
std::map<int,Joueur> chargementJoueurs(Collections collection);