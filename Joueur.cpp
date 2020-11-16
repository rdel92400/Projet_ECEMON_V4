//
// Created by Romain on 04/11/2020.
//

#include "Joueur.h"

Joueur::Joueur() {}

Joueur::Joueur(std::string nom, int argent) : m_nom(nom), m_argent(argent) {}

Joueur::~Joueur() {}

void Joueur::iniJoueur(std::string nom, int argent,Deck deckJoueur) {
    setNom(nom);
    setArgent(argent);
    setDeck(deckJoueur);
}

void Joueur::setArgent(int argent) {
    m_argent = argent;
}

void Joueur::setDeck(Deck nouveauDeck) {
    m_deck = nouveauDeck;
}

void Joueur::setNom(std::string nom) {
    m_nom = nom;
}

int Joueur::getArgent() {
    return m_argent;
}

Deck Joueur::getDeck() {
    return m_deck;
}

std::string Joueur::getNom() {
    return m_nom;
}
