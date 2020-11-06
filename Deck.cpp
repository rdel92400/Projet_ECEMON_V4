//
// Created by Romain on 04/11/2020.
//

#include "Deck.h"

Deck::Deck() {

}

Deck::~Deck() {

}

void Deck::iniDeck(Collections toutesLesCartes) {

    Carte carteChoisie;
    int choix;
    int choixCarte;
    bool deckEstComplet = false;
    int compteurDeCartesChoisies;

    for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
        toutesLesCartes.getCreature()[i].afficher();
    }

    ///Choix du joueur

    while (!deckEstComplet) {
        choix = NOMBRE_CARTES_DECK + 1;
        if (compteurDeCartesChoisies == NOMBRE_CARTES_DECK) {
            deckEstComplet = true;
        }

        do {
            std::cout << "Quelle carte voulez vous voir ?" << std::endl;
            std::cin >> choix;
        } while (choix > NOMBRE_CARTES_DECK);

        ///Probleme dans la classe collection constituée de créatures et pas de cartes

        toutesLesCartes.getCreature()[choix].afficher();

        std::cout << "Voulez vous garder cette carte ?" << std::endl;
        std::cin >> choixCarte;

        if (choixCarte == 1) {
            compteurDeCartesChoisies++;
        }

        ///Impossible d'ajouter une carte puisque la collection est constituée de créatures et pas de cartes
        //setDeck(toutesLesCartes.)
    }

}

void Deck::setDeck(Carte nouvelleCarte) {
    m_deck.push_back(nouvelleCarte);
}


