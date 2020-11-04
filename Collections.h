//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_COLLECTIONS_H
#define PROJET_ECEMON_V4_COLLECTIONS_H
#include "Principal.h"
#include "Carte.h"

class Collections
{
public:
    Collections();
    ~Collections();
    void chargement();

protected:
    std::vector<Carte> m_collection;
};


#endif //PROJET_ECEMON_V4_COLLECTIONS_H
