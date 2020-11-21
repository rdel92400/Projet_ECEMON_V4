#include <iostream>
#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"
#include "sauvegarde.h"


int main() {
    ///Ini de la collection
    Collections collection;
    collection.chargerCollectionEntiere();
    //collection.chargementCreatures(); (chargement avec fichiers non fonctionnel)

/*
    ///Test allegro
    ALLEGRO_DISPLAY *display = nullptr;

    if(!al_init()){
        al_show_native_message_box(nullptr, nullptr,nullptr,"Failed to init allegro",nullptr,0);
        return -1;
    }

    display = al_create_display(1920,1080);

    if(!display){
        al_show_native_message_box(nullptr,nullptr,nullptr,"Failed to init allegro",nullptr,0);
        return -1;
    }

    sleep(5);

    al_destroy_display(display);
*/
    ///Fin test allegro


    menu();

    ///Zone de test mettez des trucs pas finaux que on puisse commmenter si besoin
    /*
    //Test de l'ini de joueurs
    Joueur Romain;
    Deck deckDeTest;
    deckDeTest.iniDeck(collection);
    Romain.iniJoueur("Romain",500,deckDeTest);
    ///Fin de la zone de test
    */
    return 0;
}

