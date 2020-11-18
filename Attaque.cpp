#include "Attaque.h"

Attaque::Attaque()
{
    //ctor
}

Attaque::Attaque(std::string nom, std::string energieDem, int energieLV, std::string description, int degats) : m_nom(nom), m_energieDem(energieDem),m_lvEnergie(energieLV), m_description(description), m_degats(degats) {
}

Attaque::~Attaque()
{
    //dtor
}

std::string Attaque::getNom() const{
    return m_nom;
}

std::string Attaque::getDesc() const{
    return m_description;
}

std::string Attaque::getEnergie() const{
    return m_energieDem;
}

int Attaque::getDegat() const{
    return m_degats;
}

void Attaque::attaquer() {

}

void Attaque::setAttaque(std::string _nom, std::string _energieDem,int _energieLV, std::string _description, int _degats)
{
    m_nom = _nom;
    m_degats = _degats;
    m_energieDem = _energieDem;
    m_lvEnergie = _energieLV;
    m_description = _description;
}

int Attaque::getEnergieLV() const {
    return m_lvEnergie;
}
