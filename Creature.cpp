#include "Creature.h"

#include "Creature.h"

Creature::Creature()
{

}

Creature::Creature(int Pv) : m_PV(Pv){
}

Creature::~Creature()
{

}

void Creature::AssigneAttaque(Attaque &cible1, Attaque &cible2){
    m_attaque.push_back(cible1);
    m_attaque.push_back(cible2);
}


void Creature::afficher()
{
    std::cout << "Le monstre s'appelle : " << getNom() << std::endl;
    std::cout << "Description : " << getDesc() << std::endl;
    std::cout << "PV : " << m_PV << std::endl;
    std::cout << "Attaque 1 : " << m_attaque[0].getNom() << " Description : " << m_attaque[0].getDesc() << " Degats : " << m_attaque[0].getDegat() << std::endl;
    std::cout << "Attaque 2 : " << m_attaque[1].getNom() << " Description : " << m_attaque[1].getDesc() << " Degats : " << m_attaque[1].getDegat() << std::endl;
    std::cout << "La carte est utilise : " << get_EstUtilise() << std::endl;
}

void Creature::recevoirDegat(Attaque &attaque) {
    setPV(getPV()-attaque.getDegat());
}

int Creature::getPV() const {
    return m_PV;
}

void Creature::setPV(int PV) {
    m_PV = PV;
}

void Creature::setCreature(std::string nom, std::string desc, int utilisation, Attaque attaque1, Attaque attaque2)
{
    setNom(nom);
    setDesc(desc);
    set_EstUtilise(utilisation);
    AssigneAttaque(attaque1, attaque2);
}

void Creature::attaquer(Carte *cible, int i) {
    cible->recevoirDegat(m_attaque[i]);
}
