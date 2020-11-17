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
#include "Principal.h"



class Collections {
public:
    Collections();

    ~Collections();

    void chargerCollectionEntiere();
    //void chargementCreatures(); (chargement avec fichier non fonctionnel)

    void setCreature(Creature creatureRecue);
    std::vector<Creature> getCreature();

    void setCarte(Carte *carteRecue);
    std::vector<Carte*> getCarte();

protected:
    std::vector<Carte*> m_collectionCarte;
};


#endif //PROJET_ECEMON_V4_COLLECTIONS_H
