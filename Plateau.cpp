//
// Created by Romain on 04/11/2020.
//

#include "Plateau.h"

Plateau::Plateau()
{
    //ctor
}

Plateau::~Plateau()
{
    //dtor
}


void Plateau::piocherEnJeu() {

}

void Plateau::piocher() {

}

void Plateau::Partie() {

}

Plateau::Plateau(std::string nom, Deck deckJ) : m_nomJoueur(nom), m_pointDeVie(1000), m_deckJoueur(deckJ){

}

std::string Plateau::getNom() {
    return m_nomJoueur;
}

int Plateau::getPDV() {
    return m_pointDeVie;
}

Deck Plateau::getDeck() {
    return m_deckJoueur;
}

Carte Plateau::GetCarteEJ() {
    return m_carteEnjeu;
}

void Plateau::setPDV(int pdv) {
    m_pointDeVie = pdv;
}

void Plateau::setCarteEJ(Carte EJ) {
    m_carteEnjeu = EJ;
}

std::map<std::string, int> Plateau::getEnergie() {
    return m_energieJ;
}



std::vector<Carte> Plateau::getCarte() {
    return m_carte;
}

void Plateau::setEnergie(std::string type, int lv) {
    getEnergie()[type] = lv;
}

void Plateau::initEnergie() {
    getEnergie()["K"]=0;
    getEnergie()["H"]=0;
    getEnergie()["C"]=0;
    getEnergie()["N"]=0;
}
