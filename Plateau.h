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
    Plateau(std::string nom, Deck deckJ);
    ~Plateau();
    ///Set et Get
    std::string getNom();
    int getPDV();
    Deck getDeck();
    Carte GetCarteEJ();
    std::vector<Carte> getCarte();
    std::map<std::string, int> getEnergie();
    void setEnergie(std::string type, int lv);
    void setPDV(int pdv);
    void setCarteEJ(Carte EJ);

    void initEnergie();
    void melangerDeck();


    void piocherEnJeu();
    void piocher();
    void Partie();

protected:
    std::string m_nomJoueur;
    int m_pointDeVie;
    Carte m_carteEnjeu;
    Deck m_deckJoueur;
    std::map<std::string, int> m_energieJ;
    std::vector <Carte> m_carte;
    std::vector <Carte> m_speciales;
    std::vector <Carte> m_creatures;
    std::vector <Carte> m_cimetiere;

};


#endif //PROJET_ECEMON_V4_PLATEAU_H
