
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
    bool premierTourJ1(true);
    bool premierTourJ2(true);
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
                Joueur1.iniJoueurArgent(1500);

                nom1 = iniNom(mapBitmap["fondCreaJoueur1Nom"]);

                deckDeTest1.iniDeck(collection,mapBitmap,Joueur1);
                Joueur1.iniJoueur(nom1,deckDeTest1);

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
                Joueur1 = chargementJoueur1(collection,mapBitmap);

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
                Joueur2.iniJoueurArgent(1500);

                nom2 = iniNom(mapBitmap["fondCreaJoueur2Nom"]);

                deckDeTest2.iniDeck(collection,mapBitmap,Joueur2);
                Joueur2.iniJoueur(nom2,deckDeTest2);

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
                Joueur2 = chargementJoueur2(collection,mapBitmap,Joueur1.getNom());

                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);


    Plateau J1(Joueur1.getNom(), Joueur1.getDeck());
    Plateau J2(Joueur2.getNom(), Joueur2.getDeck());
    J1.initEnergie();
    J2.initEnergie();

    std::cout << "\n\nNOUVEAU \n";
    J1.initPioche();
    J2.initPioche();

    for (int i=0; i<2; i++)
    {
        J1.melangerDeck();
        J2.melangerDeck();
    }


    J1.afficherPioche();
    J2.afficherPioche();

    J1.initCarteCrea();
    J2.initCarteCrea();

    std::cout << "\nFIN NEW\n";

    std::cout << "\n\nL'enjeu du Joueur 1 est : ";
    J1.setCarteEJ();

    std::cout << "\nL'enjeu du joueur 2 est ";
    J2.setCarteEJ();

    std::cout << "\n\n\n\n DEBUT PARTIE \n\n";

    do {

        std::cout << "pioche J1 : \n";
        J1.afficherPioche();
        std::cout << "Cimetiere J1 : \n";
        J1.afficherCimetiere();
        std::cout << "pioche J2 : \n";
        J2.afficherPioche();
        std::cout << "Cimetiere J2 : \n";
        J2.afficherCimetiere();


        ///TOUR DE J1
        premierTourJ1 = false;
        J1.piocher();
        std::cout << "PV J1 : " << J1.getPDV() << std::endl;
        std::cout << "\nEnergie J1 : \n";
        for (auto &elem : J1.getEnergie()){
            std::cout << elem.first << " : " << elem.second << std::endl;
        }

        if (J1.getPioche().front()->get_EstUtilise() == ENERGIE){
            std::cout << "Voulez vous jouer cette carte ? : ";
            std::cin >> choix;
            if (choix == 1){
                J1.setEnergie(J1.getPioche().front()->getType(), J1.getPioche().front()->getLV());
                J1.ajouterCimetiere(J1.getPioche().front());
                J1.supprimerCarteFront();
            }
            if (choix == 2){
                std::cout << "Carte remise sous le paquet" << std::endl;
                J1.remiseSouspaquet();
            }
            premierTourJ1 = true;
        }
        if (premierTourJ1 == false){
            if (J1.getPioche().front()->get_EstUtilise() == CREATURE){
                std::cout << "Voulez vous jouer cette carte ? : ";
                std::cin >> choix;
                if (choix == 1){
                    if (J1.getCreature() == nullptr){
                        J1.setCarteCreature(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }else{
                        std::cout << "Voulez vous vriament jouer cette carte ? ";
                        std::cin >> choix;
                        if (choix == 1){
                            J1.getPioche().push_back(J1.getCreature());
                            J1.setCarteCreature(J1.getPioche().front());
                            J1.supprimerCarteFront();

                            std::cout << "Veux tu attaquer ton adversaire ? : ";
                            std::cin >> choix;
                            if (choix==1){
                                if (J2.getCreature() == nullptr){
                                    std::cout << "Votre adversaire n'a pas de carte creature, il perd 50 points de vie." << std::endl;
                                    J2.setPDV(J2.getPDV()-50);
                                }
                                if (J2.getCreature() != nullptr){
                                    std::cout << "Quelle attaque voulez vous utiliser ? :";
                                    std::cin >> choix;
                                    if (choix == 1){
                                        if (J1.getCreature()->getAttaque()[0].getEnergieLV() <= J1.getEnergie()[J1.getCreature()->getAttaque()[0].getEnergie()]){
                                            J1.getCreature()->attaquer(J2.getCreature(), 0);
                                            J1.setEnergie(J1.getCreature()->getAttaque()[0].getEnergie(), J1.getCreature()->getAttaque()[0].getEnergieLV());

                                            if (J2.getCreature()->getPV() <= 0){
                                                J2.ajouterCimetiere(J2.getCreature());
                                                J2.setCarteCreature(nullptr);
                                            }
                                        }else{
                                            std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                                        }
                                    }
                                    if(choix ==2){
                                        if (J1.getCreature()->getAttaque()[1].getEnergieLV() <= J1.getEnergie()[J1.getCreature()->getAttaque()[1].getEnergie()]){
                                            J1.getCreature()->attaquer(J2.getCreature(), 1);
                                            J1.setEnergie(J1.getCreature()->getAttaque()[1].getEnergie(), J1.getCreature()->getAttaque()[1].getEnergieLV());
                                        }else{
                                            std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                                        }
                                    }
                                }
                            }
                            if (choix==2){
                                std::cout << "Au tour du joueur suivant de jouer" << std::endl;
                            }
                        }
                        if(choix ==2){
                            std::cout << "Carte remise sous le paquet" << std::endl;
                            J1.remiseSouspaquet();
                        }
                    }
                }
                if(choix == 2){
                    std::cout << "Carte remise sous le paquet" << std::endl;
                    J1.remiseSouspaquet();
                }

            }
        }

        ///TOUR de J2
        premierTourJ2 = false;
        J2.piocher();
        std::cout << "\nPV J2 : " << J2.getPDV() << std::endl;
        std::cout << "\nEnergie J2 :\n";
        for (auto &elem : J2.getEnergie()){
            std::cout << elem.first << " : " << elem.second << std::endl;
        }

        if (J2.getPioche().front()->get_EstUtilise() == ENERGIE){
            std::cout << "Voulez vous jouer cette carte ? : ";
            std::cin >> choix;
            if (choix == 1){
                J2.setEnergie(J2.getPioche().front()->getType(), J2.getPioche().front()->getLV());
                J2.ajouterCimetiere(J2.getPioche().front());
                J2.supprimerCarteFront();
            }
            if (choix == 2){
                std::cout << "Carte remise sous le paquet" << std::endl;
                J2.remiseSouspaquet();
            }
            premierTourJ2 = true;
        }

        if (premierTourJ2 == false){
            if (J2.getPioche().front()->get_EstUtilise() == CREATURE){
                std::cout << "Voulez vous jouer cette carte ? : ";
                std::cin >> choix;
                if (choix == 1){
                    if (J2.getCreature() == nullptr){
                        J2.setCarteCreature(J2.getPioche().front());
                        J2.supprimerCarteFront();
                    }else{
                        std::cout << "Voulez vous vriament jouer cette carte ? ";
                        std::cin >> choix;
                        if (choix == 1){
                            J2.getPioche().push_back(J2.getCreature());
                            J2.setCarteCreature(J2.getPioche().front());
                            J2.supprimerCarteFront();

                            std::cout << "Veux tu attaquer ton adversaire ? : ";
                            std::cin >> choix;
                            if (choix==1){
                                if (J1.getCreature() == nullptr){
                                    std::cout << "Votre adversaire n'a pas de carte creature, il perd 50 points de vie." << std::endl;
                                    J1.setPDV(J1.getPDV()-50);
                                }
                                if (J1.getCreature() != nullptr){
                                    std::cout << "Quelle attaque voulez vous utiliser ? :";
                                    std::cin >> choix;
                                    if (choix == 1){
                                        if (J2.getCreature()->getAttaque()[0].getEnergieLV() <= J2.getEnergie()[J2.getCreature()->getAttaque()[0].getEnergie()]){
                                            J2.getCreature()->attaquer(J1.getCreature(), 0);
                                            J2.setEnergie(J2.getCreature()->getAttaque()[0].getEnergie(), J2.getCreature()->getAttaque()[0].getEnergieLV());

                                            if (J1.getCreature()->getPV() <= 0){
                                                J1.ajouterCimetiere(J1.getCreature());
                                                J1.setCarteCreature(nullptr);
                                            }
                                        }else{
                                            std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                                        }
                                    }
                                    if(choix ==2){
                                        if (J2.getCreature()->getAttaque()[1].getEnergieLV() <= J2.getEnergie()[J2.getCreature()->getAttaque()[1].getEnergie()]){
                                            J2.getCreature()->attaquer(J1.getCreature(), 1);
                                            J2.setEnergie(J2.getCreature()->getAttaque()[1].getEnergie(), J2.getCreature()->getAttaque()[1].getEnergieLV());
                                        }else{
                                            std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                                        }
                                    }
                                }
                            }
                            if (choix==2){
                                std::cout << "Au tour du joueur suivant de jouer" << std::endl;
                            }
                        }
                        if(choix ==2){
                            std::cout << "Carte remise sous le paquet" << std::endl;
                            J2.remiseSouspaquet();
                        }
                    }
                }
                if(choix == 2){
                    std::cout << "Carte remise sous le paquet" << std::endl;
                    J2.remiseSouspaquet();


                }

            }
        }


        /*
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
         */
    }while (J1.getPDV()>0 && J2.getPDV()>0);

    if (J1.getPDV()>0){
        std::cout << "Bravo J1 à gagner !!!\n";
    }else{
        std::cout << "Bravo J2 à gagner !!!\n";
    }

}

