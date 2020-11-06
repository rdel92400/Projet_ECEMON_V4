//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_COLLECTIONS_H
#define PROJET_ECEMON_V4_COLLECTIONS_H

#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"


class Collections {
public:
    Collections();

    ~Collections();

    void chargerCollectionEntiere();

    void setCreature(Creature creatureRecue);

    std::vector <Creature> getCreature();

protected:
    std::vector<Creature> m_collection;
};


#endif //PROJET_ECEMON_V4_COLLECTIONS_H
