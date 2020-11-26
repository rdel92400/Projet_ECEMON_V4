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
    int getPrix();
    void setPrix(int prix);
    virtual std::vector<Attaque> getAttaque();
    virtual Attaque getAttaque(int numero) const;
    virtual int getPV() const;
    virtual void setPV(int PV);
    virtual void setCreature(std::string nom,std::string desc,int utilisation,Attaque attaque1,Attaque attaque2, int prix);
    virtual void recevoirDegat(Attaque &attaque);
    virtual void afficher();
    virtual void attaquer(Carte *cible, int i);
    virtual void setEnergie(std::string nom,std::string desc,int utilisation, int prix);
    virtual int getLV() const;
    virtual std::string getType();
    virtual void setSpecial(std::string nom,std::string desc,int utilisation, int prix);


protected:
    std::string m_nom;
    std::string m_description;
    int m_EstUtilise;
    int m_prix;
};

#endif //PROJET_ECEMON_V4_CARTE_H
