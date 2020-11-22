#ifndef PROJET_ECEMON_V4_CREATURE_H
#define PROJET_ECEMON_V4_CREATURE_H

#include "Principal.h"
#include "Attaque.h"
#include "Carte.h"

class Creature : public Carte {
public:
    Creature();
    Creature(int Pv);
    ~Creature();
    int getPV() const;
    std::vector<Attaque> getAttaque();
    void setPV(int PV);
    void afficher();
    void AssigneAttaque(Attaque &cible1, Attaque &cible2);
    void recevoirDegat(Attaque &attaque);
    void setCreature(std::string nom,std::string desc,int utilisation,Attaque attaque1,Attaque attaque2);
    void attaquer(Carte *cible, int i);
protected:
    int m_PV;
    std::vector <Attaque> m_attaque;
};

#endif //PROJET_ECEMON_V4_CREATURE_H
