#include "Attaque.h"

Attaque::Attaque()
{
    //ctor
}

Attaque::Attaque(std::string nom, std::string energieDem, std::string description, int degats) : m_nom(nom), m_energieDem(energieDem), m_description(description), m_degats(degats) {
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
