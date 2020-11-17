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
    std::string choixCarte;
    bool deckEstComplet = false;
    int compteurDeCartesChoisies(0);

    for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
        std::cout << "Carte " << i << " : \n";
        toutesLesCartes.getCarte()[i]->afficher();
    }

    ///Choix du joueur

    while (!deckEstComplet) {
        choix = 0;
        do {
            std::cout << "Quelle carte voulez vous voir ?" << std::endl;
            std::cin >> choix;
        } while (choix < 0 && choix > NOMBRE_CARTES_DECK);

        ///Probleme dans la classe collection constituée de créatures et pas de cartes

        toutesLesCartes.getCarte()[choix]->afficher();

        do {
            std::cout << "Voulez vous garder cette carte ?" << std::endl;
            std::cin >> choixCarte;
            std::cin.ignore();
        }while (choixCarte!="OUI" && choixCarte!="NON");


        if (choixCarte == "OUI") {
            compteurDeCartesChoisies++;
            setDeck(toutesLesCartes.getCarte()[choix]);
        } else{
            std::cout << "Choisissez une autre carte." << std::endl;
        }

        if (compteurDeCartesChoisies == 5) {
            deckEstComplet = true;
        }


    }
    //afficherDeck();
}



void Deck::setDeck(Carte* nouvelleCarte) {
    m_deck.push_back(nouvelleCarte);
}

std::vector<Carte *> Deck::getDeck() const{
    return m_deck;
}

void Deck::afficherDeck() const{
    for (int i=0; i<NOMBRE_CARTES_DECK; i++){
        std::cout << "Carte numero " << i+1 << std::endl;
        getDeck()[i]->afficher();
    }
}




