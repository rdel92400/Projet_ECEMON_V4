//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_COLLECTIONS_H
#define PROJET_ECEMON_V4_COLLECTIONS_H

#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Energie.h"


class Collections {
public:
    Collections();

    ~Collections();

    void chargerCollectionEntiere();
    //void chargementCreatures(); (chargement avec fichier non fonctionnel)

    void setCreature(Creature creatureRecue);

    std::vector<Creature> getCreature();

protected:
    std::vector<Creature> m_collectionCreatures;
    std::vector<Energie> m_collectionEnergies;
};


#endif //PROJET_ECEMON_V4_COLLECTIONS_H
