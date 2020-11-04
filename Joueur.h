//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_JOUEUR_H
#define PROJET_ECEMON_V4_JOUEUR_H

#include "Principal.h"
#include "Deck.h"

class Joueur
{
public:
    Joueur();
    Joueur(std::string nom, int argent);
    ~Joueur();

protected:
    std::string m_nom;
    int m_argent;
    Deck m_deck;

};


#endif //PROJET_ECEMON_V4_JOUEUR_H
