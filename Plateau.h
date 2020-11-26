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
    Carte* GetCarteEJ();

    std::deque<Carte*> getPioche();
    std::vector<Carte*> getCimetiere();
    std::map<std::string, int> getEnergie();
    Carte* getCreature();
    void setCarteCreature(Carte* crea);


    void setEnergie(std::string type, int lv);
    void setPDV(int pdv);
    void setCarteEJ();

    void initEnergie();
    void initPioche();
    void initCarteCrea();
    void afficherPioche();
    void afficherCarteCrea();
    void supprimerCarteFront();
    void supprimerCarteBack();
    void ajouterCimetiere(Carte* mort);
    void supprimerCarteCim(int i);
    void afficherCimetiere();
    void remiseSouspaquet();
    void ajouterCarteSpe(Carte* j);
    void melangerDeck();
    void ajouterCarteBack(Carte* ajout);
    void ajouterCarteFront(Carte* j);
    void supprimerCartePioche(int i);

    void piocher();

protected:
    std::string m_nomJoueur;
    int m_pointDeVie;
    std::map<std::string, int> m_energieJ;
    Deck m_deckJoueur;

    Carte* m_carteEnjeu;
    std::deque<Carte*> m_pioche;
    std::vector <Carte*> m_speciales;
    Carte* m_creatures;
    std::vector <Carte*> m_cimetiere;

};


#endif //PROJET_ECEMON_V4_PLATEAU_H
