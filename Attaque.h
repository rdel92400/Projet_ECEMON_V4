//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_ATTAQUE_H
#define PROJET_ECEMON_V4_ATTAQUE_H


#include "Principal.h"

class Attaque
{
public:
    Attaque();
    Attaque(std::string nom, std::string energieDem, std::string description, int degats);
    ~Attaque();
    void attaquer();
    std::string getNom() const;
    std::string getEnergie() const;
    std::string getDesc() const;
    int getDegat() const;

protected:
    std::string m_nom;
    std::string m_energieDem;
    std::string m_description;
    int m_degats;
};


#endif //PROJET_ECEMON_V4_ATTAQUE_H
