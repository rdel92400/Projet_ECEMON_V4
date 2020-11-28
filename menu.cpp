
#include <random>

#include "menu.h"


void menu(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    int menu(0);

    ALLEGRO_MOUSE_STATE mouse;

    do
    {
        al_draw_bitmap(mapBitmap["fondMenu"],0,0,0);

        al_get_mouse_state(&mouse);

        ///JOUER
        if (mouse.x >= 125 && mouse.x <= 125+273 && mouse.y >= 391-80 && mouse.y <= 391+122-80)
        {
            al_draw_bitmap(mapBitmap["fondMenuJouer"],0,0,0);

            if (mouse.buttons & 1)
            {
                partie(mapBitmap);
            }
        }

        ///REGLES
        if (mouse.x >= 125+308+53 && mouse.x <= 125+2*308+53 && mouse.y >= 391-80 && mouse.y <= 391+122-80)
        {
            al_draw_bitmap(mapBitmap["fondMenuRegles"],0,0,0);

            if (mouse.buttons & 1)
            {
                regles(mapBitmap);
            }
        }

        ///BOUTIQUE
        if (mouse.x >= 125+308+53 && mouse.x <= 125+2*308+53 && mouse.y >= 391-80+149 && mouse.y <= 391+122-80+149)
        {
            al_draw_bitmap(mapBitmap["fondMenuBoutique"],0,0,0);

            if (mouse.buttons & 1)
            {
                boutique(mapBitmap);
            }
        }

        ///QUITTER
        if (mouse.x >= 125+2*308+2*53+308-273 && mouse.x <= 125+3*308+2*53 && mouse.y >= 391-80 && mouse.y <= 391+122-80)
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
    bool J1Protec(true);
    bool J2Protec(true);
    int fin(0);
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


        ///TOUR DE J1 PHASE DE PIOCHE
        premierTourJ1 = false;

        if (!J1.getPioche().empty()){
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
                                J1.ajouterCarteBack(J1.getCreature());
                                J1.setCarteCreature(J1.getPioche().front());
                                J1.supprimerCarteFront();
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
                premierTourJ1 = true;
            }
            if (premierTourJ1 == false){
                if (J1.getPioche().front()->get_EstUtilise() == NECRO){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        J1.afficherCimetiere();
                        std::cout << "Quelle carte voulez vous récuperer ? : ";
                        std::cin >> choix;
                        J1.ajouterCarteBack(J1.getCimetiere()[choix]);
                        J1.supprimerCarteCim(choix);
                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    } else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == SUPER_ENERGIE){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        std::cout << "Vous récupérer de l'énergie\n";
                        J1.setEnergie("H", 2);
                        J1.setEnergie("K", 2);
                        J1.setEnergie("C", 2);
                        J1.setEnergie("N", 2);

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == BOULE_DE_FEU){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix == 1){
                        ///Pas de blindage mais il faudra en rajouter un pour pas que le joueur sacrifier trop de point de vie

                        std::cout << "Vous sacrifier des points de vie pour attaquer l'adversair.\nChoisissez le nombre de point de vie à sacrifier : ";
                        std::cin >> choix;
                        J1.setPDV(J1.getPDV()-choix);
                        J2.setPDV(J2.getPDV()-choix*1.5);

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == VISION_ULTIME){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        std::cout << "Affichage de la pioche\n";
                        J1.afficherPioche();

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == MAIN_MAGIQUE){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();

                        J1.afficherPioche();
                        std::cout << "Choisissez la carte à mettre au dessus du paquet : ";
                        std::cin >> choix;
                        J1.ajouterCarteFront(J1.getPioche()[choix]);
                        J1.supprimerCartePioche(choix);
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == PROTECTION){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if(choix==1){
                        J1Protec = false;
                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J1.remiseSouspaquet();
                    }
                }
            }

        }


        ///PHASE COMBAT J1:
        if (J2Protec){
            std::cout << "\n\nBATTLE PHASE \n\n";
            if (J1.getCreature() == nullptr){
                std::cout << "Pas de carte creature" << std::endl;
            }else{
                J1.getCreature()->afficher();
                std::cout << "Veux tu attaquer ton adversaire ? : ";
                std::cin >> choix;
                if (choix==1){
                    if (J2.getCreature() == nullptr){
                        std::cout << "Votre adversaire n'a pas de carte creature, il perd 50 points de vie." << std::endl;
                        J2.setPDV(J2.getPDV()-50);
                    }
                    if (J2.getCreature() != nullptr){
                        std::cout << "Carte de l'adversaire" << std::endl;
                        J2.getCreature()->afficher();
                        std::cout << "Quelle attaque voulez vous utiliser ? :";
                        std::cin >> choix;
                        if (choix == 1){
                            if (J1.getCreature()->getAttaque()[0].getEnergieLV() <= J1.getEnergie()[J1.getCreature()->getAttaque()[0].getEnergie()]){
                                J1.getCreature()->attaquer(J2.getCreature(), 0);
                                J1.setEnergie(J1.getCreature()->getAttaque()[0].getEnergie(), -J1.getCreature()->getAttaque()[0].getEnergieLV());

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
                                J1.setEnergie(J1.getCreature()->getAttaque()[1].getEnergie(), -J1.getCreature()->getAttaque()[1].getEnergieLV());
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
        }else{
            std::cout << "Le joueur est protégé grace a la carte spéciale protection, vous pourrez l'attaquer au prochain tour" << std::endl;
            J2Protec = true;
        }



        ///TOUR de J2 PHASE DE PIOCHE
        premierTourJ2 = false;
        if (!J2.getPioche().empty()){
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
                                J2.ajouterCarteBack(J2.getCreature());
                                J2.setCarteCreature(J2.getPioche().front());
                                J2.supprimerCarteFront();
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
                premierTourJ2 = true;
            }

            if (premierTourJ2 == false){
                if (J2.getPioche().front()->get_EstUtilise() == NECRO){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        J2.afficherCimetiere();
                        std::cout << "Quelle carte voulez vous récuperer ? : ";
                        std::cin >> choix;
                        J2.ajouterCarteBack(J2.getCimetiere()[choix]);
                        J2.supprimerCarteCim(choix);
                        J2.ajouterCarteSpe(J2.getPioche().front());
                        J2.supprimerCarteFront();
                    } else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
                if (J2.getPioche().front()->get_EstUtilise() == SUPER_ENERGIE){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        std::cout << "Vous récupérer de l'énergie\n";
                        J2.setEnergie("H", 2);
                        J2.setEnergie("K", 2);
                        J2.setEnergie("C", 2);
                        J2.setEnergie("N", 2);

                        J2.ajouterCarteSpe(J1.getPioche().front());
                        J2.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
                if (J2.getPioche().front()->get_EstUtilise() == BOULE_DE_FEU){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix == 1){
                        ///Pas de blindage mais il faudra en rajouter un pour pas que le joueur sacrifier trop de point de vie

                        std::cout << "Vous sacrifier des points de vie pour attaquer l'adversair.\nChoisissez le nombre de point de vie à sacrifier : ";
                        std::cin >> choix;
                        J2.setPDV(J2.getPDV()-choix);
                        J1.setPDV(J1.getPDV()-choix*1.5);

                        J2.ajouterCarteSpe(J2.getPioche().front());
                        J2.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
                if (J2.getPioche().front()->get_EstUtilise() == VISION_ULTIME){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        std::cout << "Affichage de la pioche\n";
                        J2.afficherPioche();

                        J2.ajouterCarteSpe(J2.getPioche().front());
                        J2.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
                if (J2.getPioche().front()->get_EstUtilise() == MAIN_MAGIQUE){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if (choix==1){
                        J2.ajouterCarteSpe(J2.getPioche().front());
                        J2.supprimerCarteFront();

                        J2.afficherPioche();
                        std::cout << "Choisissez la carte à mettre au dessus du paquet : ";
                        std::cin >> choix;
                        J2.ajouterCarteFront(J2.getPioche()[choix]);
                        J2.supprimerCartePioche(choix);
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
                if (J2.getPioche().front()->get_EstUtilise() == PROTECTION){
                    std::cout << "Voulez vous jouez cette carte ? : ";
                    std::cin >> choix;
                    if(choix==1){
                        J2Protec = false;
                        J2.ajouterCarteSpe(J2.getPioche().front());
                        J2.supprimerCarteFront();
                    }else{
                        std::cout << "Carte remise sous le paquet" << std::endl;
                        J2.remiseSouspaquet();
                    }
                }
            }
        }


        ///PHASE COMBAT J2 :
        if (J1Protec){
            std::cout << "\n\nBATTLE PHASE \n\n";
            if (J2.getCreature() == nullptr){
                std::cout << "Pas de carte creature" << std::endl;
            }else {
                J2.getCreature()->afficher();
                std::cout << "Veux tu attaquer ton adversaire ? : ";
                std::cin >> choix;
                if (choix == 1) {
                    if (J1.getCreature() == nullptr) {
                        std::cout << "Votre adversaire n'a pas de carte creature, il perd 50 points de vie." << std::endl;
                        J1.setPDV(J1.getPDV() - 50);
                    }
                    if (J1.getCreature() != nullptr) {
                        std::cout << "Quelle attaque voulez vous utiliser ? :";
                        std::cin >> choix;
                        if (choix == 1) {
                            if (J2.getCreature()->getAttaque()[0].getEnergieLV() <=
                                J2.getEnergie()[J2.getCreature()->getAttaque()[0].getEnergie()]) {
                                J2.getCreature()->attaquer(J1.getCreature(), 0);
                                J2.setEnergie(J2.getCreature()->getAttaque()[0].getEnergie(),
                                              -J2.getCreature()->getAttaque()[0].getEnergieLV());

                                if (J1.getCreature()->getPV() <= 0) {
                                    J1.ajouterCimetiere(J1.getCreature());
                                    J1.setCarteCreature(nullptr);
                                }
                            } else {
                                std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                            }
                        }
                        if (choix == 2) {
                            if (J2.getCreature()->getAttaque()[1].getEnergieLV() <=
                                J2.getEnergie()[J2.getCreature()->getAttaque()[1].getEnergie()]) {
                                J2.getCreature()->attaquer(J1.getCreature(), 1);
                                J2.setEnergie(J2.getCreature()->getAttaque()[1].getEnergie(),
                                              -J2.getCreature()->getAttaque()[1].getEnergieLV());
                            } else {
                                std::cout << "Pas assez d'énergie pour attaquer" << std::endl;
                            }
                        }
                    }
                }
                if (choix==2){
                    std::cout << "Au tour du joueur suivant de jouer" << std::endl;
                }
            }
        }else{
            std::cout << "Le joueur est protégé grace a la carte spéciale protection, vous pourrez l'attaquer au prochain tour" << std::endl;
            J1Protec = true;
        }




        if (J1.getPioche().empty() && J1.getCreature()== nullptr){
            std::cout << "J1 ne peux plus se battre, la partie est fini";
            fin=1;
        }
        if (J2.getPioche().empty() && J2.getCreature()== nullptr){
            std::cout << "J2 ne peux plus se battre, la partie est fini";
            fin=1;
        }

    }while (J1.getPDV()>0 && J2.getPDV()>0 && fin==0);

    if (J1.getPDV() > J2.getPDV()){
        std::cout << "Bravo J1 à gagner !!!\n";
    }else{
        std::cout << "Bravo J2 à gagner !!!\n";
    }


}

