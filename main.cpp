#include <iostream>
#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"




int main() {
    ///Ini de la collection
    Collections collection;
    collection.chargerCollectionEntiere();
    //collection.chargementCreatures(); (chargement avec fichiers non fonctionnel)

    ///Zone de test mettez des trucs pas finaux que on puisse commmenter si besoin
    collection.getCreature()[0].afficher();
    //Test de l'ini de joueurs
    Joueur Romain;
    Deck deckDeTest;
    Romain.iniJoueur("Romain",500,deckDeTest);
    ///Fin de la zone de test

    return 0;
}

