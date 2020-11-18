#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Energie.h"


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
    std::string nom, type;
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
    J1.initEnergie();
    J2.initEnergie();

    for (auto &elem : J1.getEnergie()){
        std::cout << elem.first << "  " << elem.second << std::endl;
    }

    do {
        std::cout << "PV J1 : " << J1.getPDV() << "\nPV J2 : " << J2.getPDV() << std::endl;
        std::cout << "\n\nCarte J1 : " << std::endl;
        J1.getDeck().getDeck()[i]->afficher();
        std::cout << "Carte J2 : " << std::endl;
        J2.getDeck().getDeck()[j]->afficher();

        ///J1 pioche une carte Energie
        if (J1.getDeck().getDeck()[i]->get_EstUtilise() == ENERGIE){
            do {
                J1.getDeck().getDeck()[i]->afficher();
                J1.setEnergie(J1.getDeck().getDeck()[i]->getType(), J1.getDeck().getDeck()[i]->getLV());
                i++;
            }while (J1.getDeck().getDeck()[i+1]->get_EstUtilise() == ENERGIE);
        }
        ///J2 pioche une carte Energie
        if (J2.getDeck().getDeck()[j]->get_EstUtilise() == ENERGIE){
            do {
                J2.getDeck().getDeck()[j]->afficher();
                J2.setEnergie(J2.getDeck().getDeck()[j]->getType(), J2.getDeck().getDeck()[j]->getLV());
                j++;
            }while (J2.getDeck().getDeck()[j+1]->get_EstUtilise() == ENERGIE);
        }

        ///J1 pioche une carte Créature
        if (J1.getDeck().getDeck()[i]->get_EstUtilise() == CREATURE){
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
        }
        ///J2 pioche une carte Créature
        if (J2.getDeck().getDeck()[j]->get_EstUtilise() == CREATURE){
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
        }

        std::cout << "\nCarte J1 : " << std::endl;
        J1.getDeck().getDeck()[i]->afficher();
        std::cout << "\nCarte J2 : " << std::endl;
        J2.getDeck().getDeck()[j]->afficher();

        if (J1.getDeck().getDeck()[i]->getPV()<=0) {
            J1.setPDV(J1.getPDV()+J1.getDeck().getDeck()[i]->getPV());
            i++;
        }
        if (J2.getDeck().getDeck()[j]->getPV()<=0) {
            J2.setPDV(J2.getPDV()+J2.getDeck().getDeck()[j]->getPV());
            j++;
        }


    }while (J1.getPDV()>0 && J2.getPDV()>0);


}

