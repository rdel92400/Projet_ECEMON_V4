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




void Plateau::piocher() {
    std::cout << "Pioche : ";
    m_pioche.front()->afficher();
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

Carte* Plateau::GetCarteEJ() {
    return m_carteEnjeu;
}

void Plateau::setPDV(int pdv) {
    m_pointDeVie = pdv;
}

void Plateau::setCarteEJ() {
    m_pioche.front()->afficher();
    m_carteEnjeu = m_pioche.front();
    m_pioche.pop_front();
}

std::map<std::string, int> Plateau::getEnergie() {
    return m_energieJ;
}



std::deque<Carte*> Plateau::getPioche() {
    return m_pioche;
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
        temp = m_pioche[index];
        m_pioche[index] = m_pioche[nb2-1];
        m_pioche[NOMBRE_CARTES_DECK - i - 1] = temp;
        nb2--;
    }
}

void Plateau::initPioche() {
    for (int i=0; i<NOMBRE_CARTES_DECK; i++){
        m_pioche.push_back(getDeck().getDeck()[i]);
    }
}

void Plateau::afficherPioche() {
    int i=0;
    for (const auto& elem : getPioche()){
        std::cout << "Carte " << i << " :\n";
        elem->afficher();
        i++;
    }
}



std::vector<Carte *> Plateau::getCimetiere() {
    return m_cimetiere;
}

void Plateau::ajouterCimetiere(Carte* mort) {
    m_cimetiere.push_back(mort);
}

void Plateau::supprimerCarteFront() {
    m_pioche.pop_front();
}

void Plateau::supprimerCarteBack() {
    m_pioche.pop_back();
}

void Plateau::remiseSouspaquet() {
    m_pioche.push_back(m_pioche.front());
    m_pioche.pop_front();
}

Carte *Plateau::getCreature() {
    return m_creatures;
}

void Plateau::setCarteCreature(Carte* crea) {
    m_creatures = nullptr;
    m_creatures = crea;
}

void Plateau::initCarteCrea() {
    m_creatures = nullptr;
}

void Plateau::afficherCarteCrea() {
    if (m_creatures == nullptr){
        std::cout << " La carte est nulle" << std::endl;
    }else{
        m_creatures->afficher();
    }
}

void Plateau::afficherCimetiere() {
    int i=0;
    for(const auto& elem : m_cimetiere){
        std::cout << "Carte " << i << " : \n";
        elem->afficher();
        i++;
    }

}

void Plateau::ajouterCarteBack(Carte* ajout) {
    m_pioche.push_back(ajout);
}

void Plateau::supprimerCarteCim(int i) {
    m_cimetiere.erase(m_cimetiere.begin() +i-1);
}

void Plateau::ajouterCarteSpe(Carte* j) {
    m_speciales.push_back(j);
}

void Plateau::ajouterCarteFront(Carte* j) {
    m_pioche.push_front(j);
}

void Plateau::supprimerCartePioche(int i) {
    m_pioche.erase(m_pioche.begin() +i-1);
}


