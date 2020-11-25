
#include <random>

#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Energie.h"
#include "sauvegarde.h"
#include "menu.h"
#include "Allegro.h"

/*
void menu(){
    int menu(0);
    do {
        do {
            std::cout << "Bienvenue dans ECEMON" << std::endl;
            std::cout << "1. Jouer \n2. Regles \n3. Quitter \nQue voulez vous faire : " << std::endl;
            std::cin >> menu;
        }while (menu<1 && menu>3);
        if (menu==1){
            partie();
        }
        if (menu==2){
            std::cout << "voici les regles ......";
        }
    }while (menu!=3);


}
*/

void menu(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    int menu(0);

    ALLEGRO_MOUSE_STATE mouse;

    do
    {
        al_draw_bitmap(mapBitmap["fondMenu"],0,0,0);

        al_get_mouse_state(&mouse);

        ///JOUER
        if (mouse.x >= 125 && mouse.x <= 125+308 && mouse.y >= 391 && mouse.y <= 391+122)
        {
            al_draw_bitmap(mapBitmap["fondMenuJouer"],0,0,0);

            if (mouse.buttons & 1)
            {
                partie(mapBitmap);
            }
        }
        ///REGLES
        if (mouse.x >= 125+308+53 && mouse.x <= 125+2*308+53 && mouse.y >= 391 && mouse.y <= 391+122)
        {
            al_draw_bitmap(mapBitmap["fondMenuRegles"],0,0,0);

            if (mouse.buttons & 1)
            {
                regles(mapBitmap);
            }
        }
        ///REGLES
        if (mouse.x >= 125+2*308+2*53 && mouse.x <= 125+3*308+2*53 && mouse.y >= 391 && mouse.y <= 391+122)
        {
            al_draw_bitmap(mapBitmap["fondMenuQuitter"],0,0,0);

            if (mouse.buttons & 1)
            {
                menu = 1;
            }
        }
        al_flip_display();

    }while (menu != 1);
}

void partie(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    Collections collection;
    Joueur Joueur1, Joueur2;
    Deck deckDeTest1, deckDeTest2;

    int choix(0), i(0), j(0);
    std::string type;
    std::string nom1;
    std::string nom2;

    ALLEGRO_MOUSE_STATE mouse;

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
    {
        erreur("Initialisation","queue");
    }
    al_register_event_source(queue,al_get_keyboard_event_source());


    collection.chargerCollectionEntiere();



    ///INI JOUEUR 1
    do
    {
        al_draw_bitmap(mapBitmap["fondCreaJoueur1"],0,0,0);
        al_get_mouse_state(&mouse);

        ///NOUVEAU JOUEUR
        if (mouse.x >= 408 && mouse.x <= 408+464 && mouse.y >= 275 && mouse.y <= 275+107)
        {
            al_draw_bitmap(mapBitmap["fondCreaJoueur1Nouveau"],0,0,0);

            if (mouse.buttons & 1)
            {
                nom1 = iniNom(mapBitmap["fondCreaJoueur1Nom"]);
                deckDeTest1.iniDeck(collection,mapBitmap);

                Joueur1.iniJoueur(nom1,500,deckDeTest1);

                sauvegardeJoueur(Joueur1,collection);

                choix = 1;
            }
        }
        ///JOUEUR EXISTANT
        if (mouse.x >= 408 && mouse.x <= 408+464 && mouse.y >= 275+107+42 && mouse.y <= 275+2*107+42)
        {
            al_draw_bitmap(mapBitmap["fondCreaJoueur1Existant"],0,0,0);

            if (mouse.buttons & 1)
            {
                std::cout << "Pas encore disponible" << std::endl;
                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);



    ///INI JOUEUR 2
    do
    {
        choix = 0;
        al_draw_bitmap(mapBitmap["fondCreaJoueur2"],0,0,0);
        al_get_mouse_state(&mouse);

        ///NOUVEAU JOUEUR
        if (mouse.x >= 408 && mouse.x <= 408+464 && mouse.y >= 275 && mouse.y <= 275+107)
        {
            al_draw_bitmap(mapBitmap["fondCreaJoueur2Nouveau"],0,0,0);

            if (mouse.buttons & 1)
            {
                nom2 = iniNom(mapBitmap["fondCreaJoueur2Nom"]);
                deckDeTest2.iniDeck(collection,mapBitmap);

                Joueur2.iniJoueur(nom2,500,deckDeTest2);

                sauvegardeJoueur(Joueur2,collection);

                choix = 1;
            }
        }
        ///JOUEUR EXISTANT
        if (mouse.x >= 408 && mouse.x <= 408+464 && mouse.y >= 275+107+42 && mouse.y <= 275+2*107+42)
        {
            al_draw_bitmap(mapBitmap["fondCreaJoueur2Existant"],0,0,0);

            if (mouse.buttons & 1)
            {
                std::cout << "Pas encore disponible" << std::endl;
                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);

    /*
    do {
        std::cout << "Choisissez le premier joueur. \n1. Creer un nouveau joueur\n2. Prendre un joueur existant\nQue voulez vous faire : ";
        std::cin >> choix;
    }while (choix<1 && choix>2);
    if (choix == 1){
        std::cout << "Choisissez le nom du nouveau joueur : ";
        std::cin >> nom;
        std::cin.ignore();
        std::cout << "Creer votre deck :" << std::endl;
        deckDeTest1.iniDeck(collection);
        Joueur1.iniJoueur(nom, 500, deckDeTest1);
    }
    if (choix==2){
        std::cout << "Pas encore disponible" << std::endl;
    }
    do {
        std::cout << "Choisissez le deuxieme joueur. \n1. Creer un nouveau joueur\n2. Prendre un joueur existant\nQue voulez vous faire : ";
        std::cin >> choix;
    }while (choix<1 && choix>2);
    if (choix == 1){
        std::cout << "Choisissez le nom du nouveau joueur : ";
        std::cin >> nom;
        std::cin.ignore();
        std::cout << "Creer votre deck :" << std::endl;
        deckDeTest2.iniDeck(collection);
        Joueur2.iniJoueur(nom, 500, deckDeTest2);
    }
    if (choix==2){
        std::cout << "Pas encore disponible" << std::endl;
    }
    */

    Plateau J1(Joueur1.getNom(), Joueur1.getDeck());
    Plateau J2(Joueur2.getNom(), Joueur2.getDeck());
    J1.initEnergie();
    J2.initEnergie();

    for (const auto& elem : J1.getDeck().getDeck()){
        std::cout << elem->getNom() << std::endl;
    }

    J1.melangerDeck();

    for (const auto& elem : J1.getDeck().getDeck()){
        std::cout << elem->getNom() << std::endl;
    }

    //std::shuffle ( J2.getDeck().getDeck().begin(), J2.getDeck().getDeck().end() , std::mt19937(std::random_device()()));


    do {
        std::cout << "PV J1 : " << J1.getPDV() << "\nPV J2 : " << J2.getPDV() << std::endl;
        std::cout << "Energie J1 : \n";
        for (auto &elem : J1.getEnergie()){
            std::cout << elem.first << " : " << elem.second << std::endl;
        }
        std::cout << "Energie J2 :\n";
        for (auto &elem : J2.getEnergie()){
            std::cout << elem.first << " : " << elem.second << std::endl;
        }

        ///J1 pioche une carte Energie
        if (J1.getDeck().getDeck()[i]->get_EstUtilise() == ENERGIE){
            std::cout << "Carte J1 : \n";
            do {
                J1.getDeck().getDeck()[i]->afficher();
                J1.setEnergie(J1.getDeck().getDeck()[i]->getType(), J1.getDeck().getDeck()[i]->getLV());
                i++;
            }while (J1.getDeck().getDeck()[i]->get_EstUtilise() == ENERGIE);
        }

        ///J2 pioche une carte Energie
        if (J2.getDeck().getDeck()[j]->get_EstUtilise() == ENERGIE){
            std::cout << "Carte J2 : \n";
            do {
                J2.getDeck().getDeck()[j]->afficher();
                J2.setEnergie(J2.getDeck().getDeck()[j]->getType(), J2.getDeck().getDeck()[j]->getLV());
                j++;
            }while (J2.getDeck().getDeck()[j]->get_EstUtilise() == ENERGIE);
        }

        ///J1 pioche une carte Créature
        if (J1.getDeck().getDeck()[i]->get_EstUtilise() == CREATURE) {
            std::cout << "\n\nCarte J1 : " << std::endl;
            J1.getDeck().getDeck()[i]->afficher();
            do {
                std::cout << "\nQuelle attaque voulez-vous utiliser ? : \n1. Attaque 1\n2. Attaque 2\nChoix : ";
                std::cin >> choix;
            } while (choix < 1 && choix > 2);

            if (choix == 1) {

                if (J1.getDeck().getDeck()[i]->getAttaque()[0].getEnergieLV() <=
                    J1.getEnergie()[J1.getDeck().getDeck()[i]->getAttaque()[0].getEnergie()]) {
                    J1.getDeck().getDeck()[i]->attaquer(J2.getDeck().getDeck()[j], 0);
                    J1.setEnergie(J1.getDeck().getDeck()[i]->getAttaque()[0].getEnergie(), -(J1.getDeck().getDeck()[i]->getAttaque()[0].getEnergieLV()));
                } else {
                    std::cout << "Pas assez d'énergie pour attaquer ou alors vous n'avez pas la bonne combinaison\n";
                }
            }
            if (choix == 2) {

                if (J1.getDeck().getDeck()[i]->getAttaque()[1].getEnergieLV() <=
                    J1.getEnergie()[J1.getDeck().getDeck()[i]->getAttaque()[1].getEnergie()]) {
                    J1.getDeck().getDeck()[i]->attaquer(J2.getDeck().getDeck()[j], 1);
                    J1.setEnergie(J1.getDeck().getDeck()[i]->getAttaque()[1].getEnergie(), -(J1.getDeck().getDeck()[i]->getAttaque()[1].getEnergieLV()));
                } else {
                    std::cout << "Pas assez d'énergie pour attaquer ou alors vous n'avez pas la bonne combinaison\n";
                }
            }
        }
        ///J2 pioche une carte Créature
        if (J2.getDeck().getDeck()[j]->get_EstUtilise() == CREATURE){
            std::cout << "Carte J2 : " << std::endl;
            J2.getDeck().getDeck()[j]->afficher();
            do {
                std::cout << "\nQuelle attaque voulez-vous utiliser ? : \n1. Attaque 1\n2. Attaque 2\nChoix : ";
                std::cin >> choix;
            }while (choix<1 && choix>2);

            if (choix==1){

                if (J2.getDeck().getDeck()[j]->getAttaque()[0].getEnergieLV() <=
                    J2.getEnergie()[J2.getDeck().getDeck()[j]->getAttaque()[0].getEnergie()]) {
                    J2.getDeck().getDeck()[j]->attaquer(J1.getDeck().getDeck()[i], 0);
                    J2.setEnergie(J2.getDeck().getDeck()[j]->getAttaque()[0].getEnergie(), -(J2.getDeck().getDeck()[j]->getAttaque()[0].getEnergieLV()));
                } else {
                    std::cout << "Pas assez d'énergie pour attaquer ou alors vous n'avez pas la bonne combinaison\n";
                }
            }
            if (choix==2){
                if (J2.getDeck().getDeck()[j]->getAttaque()[1].getEnergieLV() <=
                    J2.getEnergie()[J2.getDeck().getDeck()[j]->getAttaque()[1].getEnergie()]) {
                    J2.getDeck().getDeck()[j]->attaquer(J1.getDeck().getDeck()[i], 1);
                    J2.setEnergie(J2.getDeck().getDeck()[j]->getAttaque()[1].getEnergie(), -(J2.getDeck().getDeck()[j]->getAttaque()[1].getEnergieLV()));
                } else {
                    std::cout << "Pas assez d'énergie pour attaquer ou alors vous n'avez pas la bonne combinaison\n";
                }
                J2.getDeck().getDeck()[j]->attaquer(J1.getDeck().getDeck()[i], 1);
            }
        }



        std::cout << "\nCarte J1 : " << std::endl;
        J1.getDeck().getDeck()[i]->afficher();
        std::cout << "\nCarte J2 : " << std::endl;
        J2.getDeck().getDeck()[j]->afficher();

        ///Si une carte créature meurt
        if (J1.getDeck().getDeck()[i]->get_EstUtilise() == CREATURE){
            if (J1.getDeck().getDeck()[i]->getPV()<=0) {
                J1.setPDV(J1.getPDV()+J1.getDeck().getDeck()[i]->getPV());
                i++;
                if (J1.getDeck().getDeck()[i]->getPV()<=0){
                    J1.getDeck().getDeck()[i]->setPV(1000); /// En attendant mais il faut trouver un moyen de mettre les bons HP
                }
            }
        }

        if (J2.getDeck().getDeck()[j]->get_EstUtilise() == CREATURE){
            if (J2.getDeck().getDeck()[j]->getPV()<=0) {
                J2.setPDV(J2.getPDV()+J2.getDeck().getDeck()[j]->getPV());
                j++;
                if (J2.getDeck().getDeck()[j]->getPV()<=0){
                    J2.getDeck().getDeck()[j]->setPV(1000); /// En attendant mais il faut trouver un moyen de mettre les bons HP
                }
            }
        }
    }while (J1.getPDV()>0 && J2.getPDV()>0);

    if (J1.getPDV()>0){
        std::cout << "Bravo J1 à gagner !!!\n";
    }else{
        std::cout << "Bravo J2 à gagner !!!\n";
    }

}

