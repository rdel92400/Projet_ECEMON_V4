#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"
#include "Plateau.h"

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

void partie(){
    Collections collection;
    Joueur Joueur1, Joueur2;
    Deck deckDeTest1, deckDeTest2;
    collection.chargerCollectionEntiere();
    int choix(0), i(0), j(0);
    std::string nom;
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
    Plateau J1(Joueur1.getNom(), Joueur1.getDeck());
    Plateau J2(Joueur2.getNom(), Joueur2.getDeck());


    do {
        std::cout << "Carte J1 : " << std::endl;
        J1.getDeck().getDeck()[i]->afficher();
        std::cout << "Carte J2 : " << std::endl;
        J2.getDeck().getDeck()[j]->afficher();
        do {
            std::cout << "\nQuelle attaque voulez-vous utiliser ? : \n1. Attaque 1\n2. Attaque 2\nChoix : ";
            std::cin >> choix;
        }while (choix<1 && choix>2);
        if (choix==1){
            J1.getDeck().getDeck()[i]->attaquer(J2.getDeck().getDeck()[j], 0);
        }
        if (choix==2){
            J1.getDeck().getDeck()[i]->attaquer(J2.getDeck().getDeck()[j], 1);
        }

        std::cout << "Carte J1 : " << std::endl;
        J1.getDeck().getDeck()[i]->afficher();
        std::cout << "Carte J2 : " << std::endl;
        J2.getDeck().getDeck()[j]->afficher();
        do {
            std::cout << "\nQuelle attaque voulez-vous utiliser ? : \n1. Attaque 1\n2. Attaque 2\nChoix : ";
            std::cin >> choix;
        }while (choix<1 && choix>2);
        if (choix==1){
            J2.getDeck().getDeck()[j]->attaquer(J1.getDeck().getDeck()[i], 0);
        }
        if (choix==2){
            J2.getDeck().getDeck()[j]->attaquer(J1.getDeck().getDeck()[i], 1);
        }
        if (J1.getDeck().getDeck()[i]->getPV()<=0) {
            J1.setPDV(J1.getPDV()+J1.getDeck().getDeck()[i]->getPV());
            i++;
        }
        if (J2.getDeck().getDeck()[j]->getPV()<=0) {
            J2.setPDV(J2.getPDV()+J2.getDeck().getDeck()[j]->getPV());
            j++;
        }

        std::cout << "PV J1 : " << J1.getPDV() << "\nPV J2 : " << J2.getPDV() << std::endl;


    }while (J1.getPDV()>0 && J2.getPDV()>0);


}

