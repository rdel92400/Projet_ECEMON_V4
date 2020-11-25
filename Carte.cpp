//
// Created by Romain on 04/11/2020.
//

#include "Carte.h"


Carte::Carte() : m_nom("Non nomme"), m_description("Pas de description"), m_EstUtilise(0) {}

Carte::Carte(std::string nom, std::string description, int estUtilise) :
        m_nom(nom), m_description(description), m_EstUtilise(estUtilise) {}

Carte::~Carte() {}

std::string Carte::getNom() const {
    return m_nom;
}

std::string Carte::getDesc() const {
    return m_description;
}

void Carte::setDesc(std::string desc) {
    m_description = desc;
}

void Carte::setNom(std::string nom) {
    m_nom = nom;
}

void Carte::set_EstUtilise(int util) {
    m_EstUtilise = util;
}

int Carte::get_EstUtilise() const {
    return m_EstUtilise;
}

void Carte::afficher()
{
    std::cout << getNom() << std::endl;

    ///J'ai pas fait plus d'affichage pour pas me faire chier comme on fait allegro (Romain)
}

void Carte::setCreature(std::string nom, std::string desc, int utilisation, Attaque attaque1, Attaque attaque2) {

}

void Carte::attaquer(Carte *cible, int i) {

}

void Carte::recevoirDegat(Attaque &attaque) {

}

int Carte::getPV() const {
    return 0;
}

void Carte::setPV(int PV) {

}

void Carte::setEnergie(std::string nom, std::string desc, int utilisation) {

}

int Carte::getLV() const {
    return 0;
}

std::string Carte::getType() {
    return std::__cxx11::string();
}

std::vector<Attaque> Carte::getAttaque() {
    return std::vector<Attaque>();
}

Attaque Carte::getAttaque(int numero) const
{
    Attaque attaque;
    return attaque;
}






