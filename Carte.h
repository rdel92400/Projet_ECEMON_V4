//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_CARTE_H
#define PROJET_ECEMON_V4_CARTE_H

#include "principal.h"
#include "Attaque.h"

class Carte {
public:
    Carte();
    Carte(std::string nom, std::string description, bool estUtilise);
    ~Carte();

    std::string getNom() const;
    std::string getDesc() const;
    bool get_EstUtilise() const;
    void setNom(std::string nom);
    void setDesc(std::string desc);
    void set_EstUtilise(bool util);

protected:
    std::string m_nom;
    std::string m_description;
    bool m_EstUtilise;
};

#endif //PROJET_ECEMON_V4_CARTE_H
