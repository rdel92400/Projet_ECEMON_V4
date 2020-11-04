//
// Created by Romain on 04/11/2020.
//

#include "Joueur.h"

Joueur::Joueur()
{
    //ctor
}

Joueur::Joueur(std::string nom, int argent) : m_nom(nom), m_argent(argent){
}

Joueur::~Joueur()
{
    //dtor
}
