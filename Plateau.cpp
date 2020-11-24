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


Plateau::Plateau(std::string nom, Deck deckJ) : m_nomJoueur(nom), m_pointDeVie(200), m_deckJoueur(deckJ){

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
    m_energieJ[type]+=lv;
}



void Plateau::initEnergie() {
    m_energieJ["K"]=0;
    m_energieJ["H"]=0;
    m_energieJ["C"]=0;
    m_energieJ["N"]=0;
}

void Plateau::melangerDeck() {
    int nb2 = NOMBRE_CARTES_DECK;
    int index;
    Carte* temp(0);
    for (int i=0; i<NOMBRE_CARTES_DECK; i++){
        index = std::rand()%nb2;
        std::cout << index << std::endl;
        temp = m_deckJoueur.getDeck()[index];
        std::cout << temp->getNom() << std::endl;
        m_deckJoueur.getDeck()[index] = m_deckJoueur.getDeck()[nb2-1];
        m_deckJoueur.getDeck()[NOMBRE_CARTES_DECK - i - 1] = temp;
        nb2--;
    }
}


