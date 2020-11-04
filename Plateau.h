//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_PLATEAU_H
#define PROJET_ECEMON_V4_PLATEAU_H

#include "Principal.h"
#include "Carte.h"
#include "Deck.h"

class Plateau
{
public:
    Plateau();
    ~Plateau();
    void Joueur(std::string nom);
    void piocherEnJeu();
    void piocher();
    void Partie();

protected:
    std::string m_nomJoueur;
    int m_pointDeVie;
    Carte m_carteEnjeu;
    Deck m_deckJoueur;
    std::vector <Carte> m_energies;
    std::vector <Carte> m_speciales;
    std::vector <Carte> m_creatures;
    std::vector <Carte> m_cimetiere;

};


#endif //PROJET_ECEMON_V4_PLATEAU_H
