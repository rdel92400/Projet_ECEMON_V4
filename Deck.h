//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_DECK_H
#define PROJET_ECEMON_V4_DECK_H

#include "Principal.h"
#include "Carte.h"

class Deck
{
public:
    Deck();
    ~Deck();

protected:
    std::vector<Carte> m_deck;
};


#endif //PROJET_ECEMON_V4_DECK_H
