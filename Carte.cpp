//
// Created by Romain on 04/11/2020.
//

#include "Carte.h"


Carte::Carte() : m_nom("Non nomme"), m_description("Pas de description"), m_EstUtilise(false) {

}

Carte::Carte(std::string nom, std::string description, bool estUtilise) :
        m_nom(nom), m_description(description), m_EstUtilise(estUtilise) {
}

Carte::~Carte() {

}

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

void Carte::set_EstUtilise(bool util) {
    m_EstUtilise = util;
}

bool Carte::get_EstUtilise() const {
    return m_EstUtilise;
}

void Carte::affichager() {

    std::cout << getNom() << std::endl;

    ///J'ai pas fait plus d'affichage pour pas me faire chier comme on fait allegro (Romain)

}


