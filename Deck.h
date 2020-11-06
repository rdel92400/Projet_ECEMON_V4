//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_DECK_H
#define PROJET_ECEMON_V4_DECK_H

#include "Principal.h"
#include "Carte.h"
#include "Collections.h"

class Deck
{
public:
    Deck();
    ~Deck();
    void iniDeck(Collections toutesLesCartes);

    ///Set et get

    void setDeck(Carte nouvelleCarte);

protected:
    std::vector<Carte> m_deck;
};


#endif //PROJET_ECEMON_V4_DECK_H
