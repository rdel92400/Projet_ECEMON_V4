//
// Created by Romain on 04/11/2020.
//

#ifndef PROJET_ECEMON_V4_CARTE_H
#define PROJET_ECEMON_V4_CARTE_H

#include "Principal.h"
#include "Attaque.h"

class Carte {
public:
    Carte();
    Carte(std::string nom, std::string description,int estUtilise);
    ~Carte();

    ///Set et get

    std::string getNom() const;
    std::string getDesc() const;
    int get_EstUtilise() const;
    void setNom(std::string nom);
    void setDesc(std::string desc);
    void set_EstUtilise(int util);


    virtual int getPV() const;
    virtual void setPV(int PV);
    virtual void setCreature(std::string nom,std::string desc,int utilisation,Attaque attaque1,Attaque attaque2);
    virtual void recevoirDegat(Attaque &attaque);
    virtual void afficher();
    virtual void attaquer(Carte *cible, int i);
    virtual void setEnergie(std::string nom,std::string desc,int utilisation);
    virtual int getLV() const;
    virtual std::string getType();

protected:
    std::string m_nom;
    std::string m_description;
    int m_EstUtilise;
};

#endif //PROJET_ECEMON_V4_CARTE_H
