//
// Created by Romain on 25/11/2020.
//

#include "argent.h"


int achat(Joueur joueurRecu, Carte carteRecue) {
    int nouvelArgent;

    if ((joueurRecu.getArgent() - carteRecue.getPrix()) < 0) {
        ///Return -1 car il n'a pas pu acheter
        return -1;
    } else {
        nouvelArgent = joueurRecu.getArgent() - carteRecue.getPrix();
        joueurRecu.setArgent(nouvelArgent);
        ///Return 1 car il a pu acheter
        return 1;
    }
}

void boutique(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    bool deckComplet = false;
    int compteurDeCartesChoisies(0);

    int x(0), y(0);
    int cpt(0);
    int page(0);
    int autorisation = 0;
    int tabCreature[4][5][3] = {0};
    int tabEnergie[3][4][3] = {0};

    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;
    std::string argentJoueur;
    std::string argentCarte;

    ALLEGRO_FONT* agencyFB30 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB35 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_FONT* agencyFB70 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",70);
    ALLEGRO_FONT* agencyFB40 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",40);

    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);
    ALLEGRO_COLOR blanc = al_map_rgb(255,255,255);
    ALLEGRO_COLOR noirPresque = al_map_rgb(26,26,26);
    ALLEGRO_COLOR noirPresque2 = al_map_rgb(35,35,35);
    ALLEGRO_COLOR colorText = al_map_rgb(55,55,55);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event = {0};
    if (!queue)
    {
        erreur("Initialisation","queue");
    }
    al_register_event_source(queue,al_get_keyboard_event_source());
    al_register_event_source(queue,al_get_mouse_event_source());

    iniTabCollectionCreature(tabCreature);
    iniTabCollectionEnergie(tabEnergie);


    ALLEGRO_MOUSE_STATE mouse;

    Collections collection;
    std::map<int, Joueur> tabJoueur;
    std::map<int, std::string> tabNoms;
    std::string choixNom;
    int yP(230);
    int condition(0);
    int choix(0);
    int numeroJoueur(0);
    std::string nomCarteAchetee;

    collection.chargerCollectionEntiere();
    tabJoueur = chargementJoueurs(collection);


    for (auto &elem : tabJoueur)
    {
        tabNoms[yP] = elem.second.getNom();
        yP = yP + 60;
    }

    do
    {
        choixNom = iniNomChargementJoueur(mapBitmap["fondChargementJoueurOui"],670,597,tabNoms);

        for (auto &elem : tabJoueur)
        {
            if (choixNom == elem.second.getNom())
            {
                numeroJoueur = elem.first;
                condition = 1;
            }
        }

    }while (condition == 0);

    //for (auto &elem : tabJoueur[numeroJoueur].getDeck().getDeck())
    {
        //std::cout << elem->getNom() << std::endl;
    }
    std::cout << tabJoueur[numeroJoueur].getDeck().getDeck()[0]->getNom() << std::endl;

    do
    {
        al_draw_bitmap(mapBitmap["fondBoutique"],0,0,0);
        al_get_mouse_state(&mouse);

        ///ACHETER
        if (mouse.x >= 408 && mouse.x <= 408+464 && mouse.y >= 275 && mouse.y <= 275+107)
        {
            al_draw_bitmap(mapBitmap["fondBoutiqueAcheter"],0,0,0);

            if (mouse.buttons & 1)
            {
                do
                {
                    ///ATTENTES D'EVENEMENTS
                    al_wait_for_event(queue,&event);


                    ///PAGE CREATURES
                    if (page == 0)
                    {
                        al_draw_bitmap(mapBitmap["fondCollectionCreatures"],0,0,0);

                        ///AFFICHAGE NOMS
                        cpt = 0;
                        for(int j = 0; j < 4; j++)
                        {
                            for(int i = 0; i < 5; i++)
                            {
                                al_draw_text(agencyFB30,colorText,tabCreature[j][i][0] + 80 - al_get_text_width(agencyFB30,collection.getCarte()[cpt]->getNom().c_str())/2,tabCreature[j][i][1],0,collection.getCarte()[cpt]->getNom().c_str());
                                tabCreature[j][i][2] = cpt;
                                cpt++;
                            }
                        }

                        ///AFFICHAGE SELECTION
                        al_draw_rectangle(tabCreature[y][x][0]-1,tabCreature[y][x][1]-20,tabCreature[y][x][0]+160-1,tabCreature[y][x][1]+80-20,noirPresque2,7);
                        al_draw_text(agencyFB30,rouge,tabCreature[y][x][0] + 80 - al_get_text_width(agencyFB30,collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str())/2,tabCreature[y][x][1],0,collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());

                        ///FLECHE DROITE
                        if(event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(agencyFB70,rouge,1280-26-21,310,0,">");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                page = 1;
                                x = 0;
                                y = 0;
                            }
                        }
                        else
                        {
                            al_draw_text(agencyFB70,blanc,1280-26-21,310,0,">");
                        }
                    }


                    ///PAGE ENERGIES
                    if (page == 1)
                    {
                        al_draw_bitmap(mapBitmap["fondCollectionEnergies"],0,0,0);

                        ///AFFICHAGE NOMS
                        cpt = 20;
                        for(int j = 0; j < 3; j++)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                al_draw_text(agencyFB30,colorText,tabEnergie[j][i][0] + 80 - al_get_text_width(agencyFB30,collection.getCarte()[cpt]->getNom().c_str())/2,tabEnergie[j][i][1],0,collection.getCarte()[cpt]->getNom().c_str());
                                tabEnergie[j][i][2] = cpt;
                                cpt++;
                            }
                        }

                        ///AFFICHAGE SELECTION
                        al_draw_rectangle(tabEnergie[y][x][0]-1,tabEnergie[y][x][1]-20,tabEnergie[y][x][0]+160-1,tabEnergie[y][x][1]+80-20,noirPresque2,7);
                        al_draw_text(agencyFB30,rouge,tabEnergie[y][x][0] + 80 - al_get_text_width(agencyFB30,collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str())/2,tabEnergie[y][x][1],0,collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());

                        ///FLECHE DROITE
                        al_draw_text(agencyFB70,blanc,1280-26-21,310,0,">");
                        if (event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(agencyFB70,rouge,1280-26-21,310,0,">");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                page = 1;
                            }
                        }

                        ///FLECHE GAUCHE
                        al_draw_text(agencyFB70,blanc,26,310,0,"<");
                        if (event.mouse.x >= 26 && event.mouse.x <= 26+21 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(agencyFB70,rouge,26,310,0,"<");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                page = 0;
                            }
                        }
                    }


                    ///MOUVEMENTS
                    if (event.type == ALLEGRO_EVENT_KEY_CHAR)
                    {
                        ///PAGE CREATURE
                        if (page == 0)
                        {
                            switch (event.keyboard.keycode)
                            {
                                case ALLEGRO_KEY_UP: if(y != 0) y--; break;
                                case ALLEGRO_KEY_RIGHT: if(x != 4) x++; break;
                                case ALLEGRO_KEY_DOWN: if(y != 3) y++; break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--; break;
                                case ALLEGRO_KEY_ENTER:
/*
                        int test = achat(joueur,maCollection.getCarte()[tabCreature[y][x][2]]);
                        if(test<0)

                            ///PAS LE DROIT
                        else
                            ///DROIT
*/
                                    autorisation = 0;
                                    for (auto &elem : tabJoueur[numeroJoueur].getDeck().getDeck())
                                    {
                                        std::cout << collection.getCarte()[tabCreature[y][x][2]]->getNom() << " = " << elem->getNom() << std::endl;
                                        if (collection.getCarte()[tabCreature[y][x][2]]->getNom() == elem->getNom())
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        nomCarteAchetee = collection.getCarte()[tabCreature[y][x][2]]->getNom();
                                        compteurDeCartesChoisies++;
                                    }
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    pv = std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getPV());
                                    degat1 = "Degats : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDegat());
                                    degat2 = "Degats : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDegat());

                                    if (collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "H")
                                    {
                                        energieRequis1 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Haki";
                                        energieRequis2 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Haki";
                                    }
                                    if (collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "N")
                                    {
                                        energieRequis1 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Nen";
                                        energieRequis2 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Nen";
                                    }
                                    if (collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "K")
                                    {
                                        energieRequis1 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Ki";
                                        energieRequis2 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Ki";
                                    }
                                    if (collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "C")
                                    {
                                        energieRequis1 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Chakra";
                                        energieRequis2 = "Requis : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Chakra";
                                    }

                                    al_draw_bitmap(mapBitmap["templateCarteCreature"],0,0,0);

                                    al_draw_text(agencyFB35,noirPresque,758 + 27,92,0,pv.c_str());

                                    al_draw_text(agencyFB40,noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());
                                    al_draw_text(agencyFB35,noirPresque,758 + 27,92,ALLEGRO_ALIGN_CENTER,pv.c_str());

                                    al_draw_text(agencyFB30,noirPresque,470,390,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getNom().c_str());
                                    al_draw_text(agencyFB30,noirPresque2,470,425,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDesc().c_str());
                                    al_draw_text(agencyFB30,noirPresque,470,465,0,degat1.c_str());
                                    al_draw_text(agencyFB30,noirPresque,800,465,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

                                    al_draw_text(agencyFB30,noirPresque,470,520,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getNom().c_str());
                                    al_draw_text(agencyFB30,noirPresque2,470,555,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDesc().c_str());
                                    al_draw_text(agencyFB30,noirPresque,470,595,0,degat2.c_str());
                                    al_draw_text(agencyFB30,noirPresque,800,595,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());


                                    al_draw_bitmap(mapBitmap[collection.getCarte()[tabCreature[y][x][2]]->getNom()],460,163,0);
                                    break;
                            }
                        }
                        ///PAGE ENERGIE
                        if (page == 1)
                        {
                            switch (event.keyboard.keycode)
                            {
                                case ALLEGRO_KEY_UP: if(y != 0) y--; break;
                                case ALLEGRO_KEY_RIGHT: if(x != 3) x++; break;
                                case ALLEGRO_KEY_DOWN: if(y != 2) y++; break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--; break;
                                case ALLEGRO_KEY_ENTER:
                                    autorisation = 0;
                                    for (auto &elem : tabJoueur[numeroJoueur].getDeck().getDeck())
                                    {
                                        if (collection.getCarte()[tabEnergie[y][x][2]]->getNom() == elem->getNom())
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        nomCarteAchetee = collection.getCarte()[tabEnergie[y][x][2]]->getNom();
                                        compteurDeCartesChoisies++;
                                    }
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    lvlEnergie = std::to_string(collection.getCarte()[tabEnergie[y][x][2]]->getLV());

                                    al_draw_bitmap(mapBitmap["templateCarteEnergie"],0,0,0);

                                    al_draw_text(agencyFB40,noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());
                                    al_draw_text(agencyFB40,noirPresque,778 + 8,88,ALLEGRO_ALIGN_CENTER,lvlEnergie.c_str());

                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "H")
                                    {
                                        al_draw_bitmap(mapBitmap["fondHaki"],460,163,0);
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,540,ALLEGRO_ALIGN_CENTER,"Energie mentale devastatrice");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "K")
                                    {
                                        al_draw_bitmap(mapBitmap["fondKi"],460,163,0);
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie vitale pouvant");
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"etre deployée");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "N")
                                    {
                                        al_draw_bitmap(mapBitmap["fondNen"],460,163,0);
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Force d'esprit");
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"creant une aura puissante");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "C")
                                    {
                                        al_draw_bitmap(mapBitmap["fondChakra"],460,163,0);
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie spirituelle");
                                        al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"circulant dans le corps");
                                    }
                                    break;
                            }
                        }
                    }


                    ///DECK COMPLET
                    if (compteurDeCartesChoisies == 1)
                    {
                        deckComplet = true;
                    }

                    al_flip_display();

                }while (!deckComplet);

                al_destroy_event_queue(queue);


                std::cout << nomCarteAchetee << std::endl;


                RemplacedeJoueur(tabJoueur,collection);

                choix = 1;
            }
        }
        ///RETOUR
        if (mouse.x >= 504 && mouse.x <= 504+272 && mouse.y >= 720-9-63 && mouse.y <= 720-9)
        {
            al_draw_bitmap(mapBitmap["fondBoutiqueRetour"],0,0,0);

            if (mouse.buttons & 1)
            {
                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);
}