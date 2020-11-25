//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_DECK_H
#define PROJET_ECEMON_V4_DECK_H

#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Collections.h"

class Deck
{
public:
    Deck();
    ~Deck();
    //void iniDeck(Collections toutesLesCartes);
    void iniDeck(Collections maCollection, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);

    ///Set et get
    void setDeck(Carte* nouvelleCarte);
    std::vector<Carte*> getDeck() const;

    void afficherDeck() const;
protected:
    std::vector<Carte*> m_deck;
};

#endif //PROJET_ECEMON_V4_DECK_H
