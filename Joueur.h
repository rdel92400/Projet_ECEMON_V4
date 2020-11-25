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
    void iniJoueur(std::string nom, Deck deckJoueur);
    void iniJoueurArgent(int argent);
    ///Set et get
    void setArgent(int argent);
    void setDeck(Deck nouveauDeck);
    void setNom(std::string nom);
    int getArgent();
    Deck getDeck();
    std::string getNom();

protected:
    std::string m_nom;
    int m_argent;
    Deck m_deck;

};

#endif //PROJET_ECEMON_V4_JOUEUR_H
