//
// Created by Romain on 25/11/2020.
//

#ifndef PROJET_ECEMON_V4_ARGENT_H
#define PROJET_ECEMON_V4_ARGENT_H

#include "Principal.h"
#include "Joueur.h"
#include "Allegro.h"
#include "sauvegarde.h"

void victoireArgent (Joueur joueurRecu);
int achat(Joueur* joueurRecu,Carte* carteRecue);
void boutique(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);
void achatCarteBoutique(Joueur* joueur, Carte* carteARajouter, Carte* carteAEnlever);


#endif //PROJET_ECEMON_V4_ARGENT_H
