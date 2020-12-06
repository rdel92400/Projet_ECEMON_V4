
#include <random>

#include "menu.h"


void menu(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, std::map<std::string,ALLEGRO_FONT*> myMapPolice, std::map<std::string,ALLEGRO_SAMPLE*> mapSample)
{
    int menu(0);

    ALLEGRO_MOUSE_STATE mouse;

    al_play_sample(mapSample["menu"],1,0,1,ALLEGRO_PLAYMODE_LOOP, nullptr);

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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                partie(mapBitmap,myMapPolice,mapSample);
            }
        }

        ///REGLES
        if (mouse.x >= 125+308+53 && mouse.x <= 125+2*308+53 && mouse.y >= 391-80 && mouse.y <= 391+122-80)
        {
            al_draw_bitmap(mapBitmap["fondMenuRegles"],0,0,0);

            if (mouse.buttons & 1)
            {
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                regles(mapBitmap,mapSample);
            }
        }

        ///BOUTIQUE
        if (mouse.x >= 125+308+53 && mouse.x <= 125+2*308+53 && mouse.y >= 391-80+149 && mouse.y <= 391+122-80+149)
        {
            al_draw_bitmap(mapBitmap["fondMenuBoutique"],0,0,0);

            if (mouse.buttons & 1)
            {
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                boutique(mapBitmap,myMapPolice,mapSample);
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

void partie(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, std::map<std::string,ALLEGRO_FONT*> myMapPolice, std::map<std::string,ALLEGRO_SAMPLE*> mapSample)
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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);

                Joueur1.iniJoueurArgent(3000);

                nom1 = iniNom(mapBitmap["fondCreaJoueur1Nom"],myMapPolice);

                deckDeTest1.iniDeck(collection,mapBitmap,Joueur1,mapSample);
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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);

                Joueur1 = chargementJoueur1(collection,mapBitmap,myMapPolice);

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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);

                Joueur2.iniJoueurArgent(3000);

                nom2 = iniNom(mapBitmap["fondCreaJoueur2Nom"],myMapPolice);

                deckDeTest2.iniDeck(collection,mapBitmap,Joueur2,mapSample);
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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);

                Joueur2 = chargementJoueur2(collection,mapBitmap,Joueur1.getNom(),myMapPolice);
                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);


    ///JEU
    al_stop_samples();
    al_play_sample(mapSample["combat"],0.5,0,1,ALLEGRO_PLAYMODE_LOOP, nullptr);

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

    std::cout << "\n\n\n\nDEBUT PARTIE \n\n";

    do
    {
        std::cout << "pioche J1 : \n";
        J1.afficherPioche();
        std::cout << "Cimetiere J1 : \n";
        J1.afficherCimetiere();
        std::cout << "pioche J2 : \n";
        J2.afficherPioche();
        std::cout << "Cimetiere J2 : \n";
        J2.afficherCimetiere();


        ///TOUR DE J1 PHASE DE PIOCHE
        al_draw_bitmap(mapBitmap["fondPartiePioche"],0,0,0);
        affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
        affichageCarteActive(J1,mapBitmap,myMapPolice);
        affichageCarteEnjeu(J1,myMapPolice);

        premierTourJ1 = false;
        if (!J1.getPioche().empty())
        {
            actionPioche(J1,mapBitmap,myMapPolice);

            if (J1.getPioche().front()->get_EstUtilise() == ENERGIE)
            {
                choix = choixPioche1(mapBitmap,myMapPolice);

                if (choix == 1)
                {
                    J1.setEnergie(J1.getPioche().front()->getType(), J1.getPioche().front()->getLV());
                    J1.ajouterCimetiere(J1.getPioche().front());
                    J1.supprimerCarteFront();

                    affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
                    affichageCarteAjoutee(mapBitmap,myMapPolice);
                }
                if (choix == 2)
                {
                    J1.remiseSouspaquet();

                    affichageRemiseSousPioche(mapBitmap,myMapPolice);
                }
                premierTourJ1 = true;
            }

            if (premierTourJ1 == false)
            {
                if (J1.getPioche().front()->get_EstUtilise() == CREATURE)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix == 1)
                    {
                        if (J1.getCreature() == nullptr)
                        {
                            J1.setCarteCreature(J1.getPioche().front());
                            J1.supprimerCarteFront();

                            affichageCarteActive(J1,mapBitmap,myMapPolice);
                            affichageCarteAjoutee(mapBitmap,myMapPolice);
                        }
                        else
                        {
                            choix = choixPioche2(mapBitmap,myMapPolice);

                            if (choix == 1)
                            {
                                J1.ajouterCarteBack(J1.getCreature());
                                J1.setCarteCreature(J1.getPioche().front());
                                J1.supprimerCarteFront();

                                affichageCarteActive(J1,mapBitmap,myMapPolice);
                                affichageCarteAjoutee(mapBitmap,myMapPolice);
                            }
                            if(choix ==2)
                            {
                                J1.remiseSouspaquet();

                                affichageRemiseSousPioche(mapBitmap,myMapPolice);
                            }
                        }
                    }
                    if(choix == 2)
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                    premierTourJ1 = true;
                }
            }
            if (premierTourJ1 == false)
            {
                if (J1.getPioche().front()->get_EstUtilise() == NECRO)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix==1)
                    {
                        choix = affichageNecro(J1,mapBitmap,myMapPolice);

                        J1.ajouterCarteBack(J1.getCimetiere()[choix]);
                        J1.supprimerCarteCim(choix);

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == SUPER_ENERGIE)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix==1)
                    {
                        J1.setEnergie("H", 2);
                        J1.setEnergie("K", 2);
                        J1.setEnergie("C", 2);
                        J1.setEnergie("N", 2);

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();

                        affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
                        affichageSuperEnergie(mapBitmap,myMapPolice);
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == BOULE_DE_FEU)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix == 1)
                    {
                        choix = affichageBouleDeFeu(J2,mapBitmap,myMapPolice);

                        J1.setPDV(J1.getPDV() - choix);
                        J2.setPDV(J2.getPDV() - choix*1.5);

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == VISION_ULTIME)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix==1)
                    {
                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();

                        affichageVisionUltime(J1,mapBitmap,myMapPolice);
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == MAIN_MAGIQUE)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix==1)
                    {
                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();

                        choix = affichageMainMagique(J1,mapBitmap,myMapPolice);

                        J1.ajouterCarteFront(J1.getPioche()[choix]);
                        J1.supprimerCartePioche(choix + 1);
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
                if (J1.getPioche().front()->get_EstUtilise() == PROTECTION)
                {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if(choix==1)
                    {
                        J1Protec = false;

                        J1.ajouterCarteSpe(J1.getPioche().front());
                        J1.supprimerCarteFront();

                        affichageProtection(mapBitmap,myMapPolice);
                    }
                    else
                    {
                        J1.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                }
            }
        }


        ///PHASE COMBAT J1:
        al_draw_bitmap(mapBitmap["fondPartieAttaque"],0,0,0);
        affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
        affichageCarteActive(J1,mapBitmap,myMapPolice);
        affichageCarteActiveEnnemie(J2,mapBitmap,myMapPolice);
        affichageCarteEnjeu(J1,myMapPolice);

        if (J2Protec)
        {
            if (J1.getCreature() == nullptr)
            {
                affichagePasDeCarteActive(mapBitmap,myMapPolice);
            }
            else
            {
                choix = choixSiAttaque(mapBitmap,myMapPolice);

                if (choix == 1)
                {
                    if (J2.getCreature() == nullptr)
                    {
                        J2.setPDV(J2.getPDV()-50);

                        affichagePasDeCarteActiveEnnemie(mapBitmap,myMapPolice);
                    }
                    if (J2.getCreature() != nullptr)
                    {
                        choix = choixAttaque(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            if (J1.getCreature()->getAttaque()[0].getEnergieLV() <= J1.getEnergie()[J1.getCreature()->getAttaque()[0].getEnergie()])
                            {
                                J1.getCreature()->attaquer(J2.getCreature(), 0);
                                J1.setEnergie(J1.getCreature()->getAttaque()[0].getEnergie(), -J1.getCreature()->getAttaque()[0].getEnergieLV());

                                if (J2.getCreature()->getPV() <= 0)
                                {
                                    J2.ajouterCimetiere(J2.getCreature());
                                    J2.setCarteCreature(nullptr);
                                }

                                affichageCarteActiveEnnemie(J2,mapBitmap,myMapPolice);
                                affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
                                affichageAttaqueReussie(mapBitmap,myMapPolice);
                            }
                            else
                            {
                                affichagePasAssezEnergie(mapBitmap,myMapPolice);
                            }
                        }
                        if(choix ==2)
                        {
                            if (J1.getCreature()->getAttaque()[1].getEnergieLV() <= J1.getEnergie()[J1.getCreature()->getAttaque()[1].getEnergie()])
                            {
                                J1.getCreature()->attaquer(J2.getCreature(), 1);
                                J1.setEnergie(J1.getCreature()->getAttaque()[1].getEnergie(), -J1.getCreature()->getAttaque()[1].getEnergieLV());

                                if (J2.getCreature()->getPV() <= 0)
                                {
                                    J2.ajouterCimetiere(J2.getCreature());
                                    J2.setCarteCreature(nullptr);
                                }

                                affichageCarteActiveEnnemie(J2,mapBitmap,myMapPolice);
                                affichageNomPvEnergie(J1,mapBitmap,myMapPolice);
                                affichageAttaqueReussie(mapBitmap,myMapPolice);
                            }
                            else
                            {
                                affichagePasAssezEnergie(mapBitmap,myMapPolice);
                            }
                        }
                    }
                }
                if (choix==2)
                {
                    affichageJoueurSuivant(mapBitmap,myMapPolice);
                }
            }
        }
        else
        {
            affichageJoueurProtege(mapBitmap,myMapPolice);

            J2Protec = true;
        }


        if (J2.getPDV() > 0)
        {
            ///TOUR de J2 PHASE DE PIOCHE
            al_draw_bitmap(mapBitmap["fondPartiePioche"], 0, 0, 0);
            affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
            affichageCarteActive(J2, mapBitmap,myMapPolice);
            affichageCarteEnjeu(J2,myMapPolice);

            premierTourJ2 = false;
            if (!J2.getPioche().empty()) {
                actionPioche(J2, mapBitmap,myMapPolice);

                if (J2.getPioche().front()->get_EstUtilise() == ENERGIE) {
                    choix = choixPioche1(mapBitmap,myMapPolice);

                    if (choix == 1) {
                        J2.setEnergie(J2.getPioche().front()->getType(), J2.getPioche().front()->getLV());
                        J2.ajouterCimetiere(J2.getPioche().front());
                        J2.supprimerCarteFront();

                        affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
                        affichageCarteAjoutee(mapBitmap,myMapPolice);
                    }
                    if (choix == 2) {
                        J2.remiseSouspaquet();

                        affichageRemiseSousPioche(mapBitmap,myMapPolice);
                    }
                    premierTourJ2 = true;
                }

                if (premierTourJ2 == false) {
                    if (J2.getPioche().front()->get_EstUtilise() == CREATURE) {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1) {
                            if (J2.getCreature() == nullptr) {
                                J2.setCarteCreature(J2.getPioche().front());
                                J2.supprimerCarteFront();

                                affichageCarteActive(J2, mapBitmap,myMapPolice);
                                affichageCarteAjoutee(mapBitmap,myMapPolice);
                            } else {
                                choix = choixPioche2(mapBitmap,myMapPolice);

                                if (choix == 1) {
                                    J2.ajouterCarteBack(J2.getCreature());
                                    J2.setCarteCreature(J2.getPioche().front());
                                    J2.supprimerCarteFront();

                                    affichageCarteActive(J2, mapBitmap,myMapPolice);
                                    affichageCarteAjoutee(mapBitmap,myMapPolice);
                                }
                                if (choix == 2) {
                                    J2.remiseSouspaquet();

                                    affichageRemiseSousPioche(mapBitmap,myMapPolice);
                                }
                            }
                        }
                        if (choix == 2) {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                        premierTourJ2 = true;
                    }
                }

                if (premierTourJ2 == false)
                {
                    if (J2.getPioche().front()->get_EstUtilise() == NECRO)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            J2.afficherCimetiere();

                            choix = affichageNecro(J2,mapBitmap,myMapPolice);

                            J2.ajouterCarteBack(J2.getCimetiere()[choix]);
                            J2.supprimerCarteCim(choix);

                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();
                        }
                        else
                        {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                    if (J2.getPioche().front()->get_EstUtilise() == SUPER_ENERGIE)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            J2.setEnergie("H", 2);
                            J2.setEnergie("K", 2);
                            J2.setEnergie("C", 2);
                            J2.setEnergie("N", 2);

                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();

                            affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
                            affichageSuperEnergie(mapBitmap,myMapPolice);
                        }
                        else
                            {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                    if (J2.getPioche().front()->get_EstUtilise() == BOULE_DE_FEU)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            choix = affichageBouleDeFeu(J1, mapBitmap,myMapPolice);

                            J2.setPDV(J2.getPDV() - choix);
                            J1.setPDV(J1.getPDV() - choix * 1.5);

                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();
                        }
                        else
                        {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                    if (J2.getPioche().front()->get_EstUtilise() == VISION_ULTIME)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();

                            affichageVisionUltime(J2, mapBitmap,myMapPolice);
                        }
                        else
                        {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                    if (J2.getPioche().front()->get_EstUtilise() == MAIN_MAGIQUE)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();

                            choix = affichageMainMagique(J2,mapBitmap,myMapPolice);

                            J2.ajouterCarteFront(J2.getPioche()[choix]);
                            J2.supprimerCartePioche(choix + 1);
                        }
                        else
                        {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                    if (J2.getPioche().front()->get_EstUtilise() == PROTECTION)
                    {
                        choix = choixPioche1(mapBitmap,myMapPolice);

                        if (choix == 1)
                        {
                            J2Protec = false;

                            J2.ajouterCarteSpe(J2.getPioche().front());
                            J2.supprimerCarteFront();

                            affichageProtection(mapBitmap,myMapPolice);
                        }
                        else
                            {
                            J2.remiseSouspaquet();

                            affichageRemiseSousPioche(mapBitmap,myMapPolice);
                        }
                    }
                }
            }


            ///PHASE COMBAT J2 :
            al_draw_bitmap(mapBitmap["fondPartieAttaque"], 0, 0, 0);
            affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
            affichageCarteActive(J2, mapBitmap,myMapPolice);
            affichageCarteActiveEnnemie(J1, mapBitmap,myMapPolice);
            affichageCarteEnjeu(J2,myMapPolice);

            if (J1Protec) {
                if (J2.getCreature() == nullptr) {
                    affichagePasDeCarteActive(mapBitmap,myMapPolice);
                } else {
                    choix = choixSiAttaque(mapBitmap,myMapPolice);

                    if (choix == 1) {
                        if (J1.getCreature() == nullptr) {
                            J1.setPDV(J1.getPDV() - 50);

                            affichagePasDeCarteActiveEnnemie(mapBitmap,myMapPolice);
                        }
                        if (J1.getCreature() != nullptr) {
                            choix = choixAttaque(mapBitmap,myMapPolice);

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

                                    affichageCarteActiveEnnemie(J1, mapBitmap,myMapPolice);
                                    affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
                                    affichageAttaqueReussie(mapBitmap,myMapPolice);
                                } else {
                                    affichagePasAssezEnergie(mapBitmap,myMapPolice);
                                }
                            }
                            if (choix == 2) {
                                if (J2.getCreature()->getAttaque()[1].getEnergieLV() <=
                                    J2.getEnergie()[J2.getCreature()->getAttaque()[1].getEnergie()]) {
                                    J2.getCreature()->attaquer(J1.getCreature(), 1);
                                    J2.setEnergie(J2.getCreature()->getAttaque()[1].getEnergie(),
                                                  -J2.getCreature()->getAttaque()[1].getEnergieLV());

                                    if (J1.getCreature()->getPV() <= 0) {
                                        J1.ajouterCimetiere(J1.getCreature());
                                        J1.setCarteCreature(nullptr);
                                    }

                                    affichageCarteActiveEnnemie(J1, mapBitmap,myMapPolice);
                                    affichageNomPvEnergie(J2, mapBitmap,myMapPolice);
                                    affichageAttaqueReussie(mapBitmap,myMapPolice);
                                } else {
                                    affichagePasAssezEnergie(mapBitmap,myMapPolice);
                                }
                            }
                        }
                    }
                    if (choix == 2) {
                        affichageJoueurSuivant(mapBitmap,myMapPolice);
                    }
                }
            } else {
                affichageJoueurProtege(mapBitmap,myMapPolice);

                J1Protec = true;
            }


            if (J1.getPioche().empty() && J1.getCreature() == nullptr) {
                std::cout << "J1 ne peux plus se battre, la partie est fini";
                fin = 1;
            }
            if (J2.getPioche().empty() && J2.getCreature() == nullptr) {
                std::cout << "J2 ne peux plus se battre, la partie est fini";
                fin = 1;
            }

        }

    }while (J1.getPDV() > 0 && J2.getPDV() > 0 && fin == 0);



    if (J1.getPDV() > J2.getPDV())
    {
        ///VICTOIRE J1
        affichageVictoire(J1,J2,mapBitmap,myMapPolice);
    }
    else
    {
        ///VICTOIRE J2
        affichageVictoire(J2,J1,mapBitmap,myMapPolice);
    }
}
