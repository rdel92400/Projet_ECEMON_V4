//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_ENERGIE_H
#define PROJET_ECEMON_V4_ENERGIE_H
#include "Principal.h"
#include "Carte.h"

class Energie : public Carte
{
public:
    Energie();
    Energie(int lv, std::string type);
    ~Energie();
    void setEnergie(std::string nom,std::string desc,int utilisation);


protected:
    int m_Lv;
    std::string m_type;

};


#endif //PROJET_ECEMON_V4_ENERGIE_H
