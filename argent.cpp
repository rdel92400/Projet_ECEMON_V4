//
// Created by Romain on 25/11/2020.
//

#include "argent.h"

int achat(Joueur* joueurRecu, Carte* carteRecue)
{
    int nouvelArgent;

    ///PAS ACHAT
    if ((joueurRecu->getArgent() - carteRecue->getPrix()) < 0)
    {
        return -1;
    }
    ///ACHAT
    else
    {
        joueurRecu->setArgent(joueurRecu->getArgent() - carteRecue->getPrix());

        return 1;
    }
}

void boutique(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, std::map<std::string,ALLEGRO_FONT*> myMapPolice, std::map<std::string,ALLEGRO_SAMPLE*> mapSample)
{
    bool deckComplet = false;
    int compteurDeCartesChoisies(0);

    int x(0), y(0);
    int cpt(0);
    int page(0);
    int autorisation = 0;
    int tabCreature[4][5][3] = {0};
    int tabEnergie[4][4][3] = {0};
    int tabSpeciales[2][3][3] = {0};
    int tabDeck[3][5][3] = {0};

    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;
    std::string argentJoueur;
    std::string argentCarte;

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
    iniTabCollectionSpeciale(tabSpeciales);
    iniTabCollectionDeck(tabDeck);

    ALLEGRO_MOUSE_STATE mouse;

    Collections collection;
    std::map<int, Joueur> tabJoueur;
    std::map<int, std::string> tabNoms;
    std::string choixNom;
    int yP(230);
    int condition(0);
    int choix(0);
    int numeroJoueur(0);
    Carte* carteAchetee;
    Carte* carteRemplacee;

    collection.chargerCollectionEntiere();
    tabJoueur = chargementJoueurs(collection);


    for (auto &elem : tabJoueur)
    {
        tabNoms[yP] = elem.second.getNom();
        yP = yP + 60;
    }

    do
    {
        choixNom = iniNomChargementJoueur(mapBitmap["fondChargementJoueurOui"],670,597,tabNoms,myMapPolice);

        for (auto &elem : tabJoueur)
        {
            if (choixNom == elem.second.getNom())
            {
                numeroJoueur = elem.first;
                condition = 1;
            }
        }

    }while (condition == 0);


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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
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
                                al_draw_text(myMapPolice["30"],colorText,tabCreature[j][i][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[cpt]->getNom().c_str())/2,tabCreature[j][i][1],0,collection.getCarte()[cpt]->getNom().c_str());
                                tabCreature[j][i][2] = cpt;
                                cpt++;
                            }
                        }

                        ///AFFICHAGE SELECTION
                        al_draw_rectangle(tabCreature[y][x][0]-1,tabCreature[y][x][1]-20,tabCreature[y][x][0]+160-1,tabCreature[y][x][1]+80-20,noirPresque2,7);
                        al_draw_text(myMapPolice["30"],rouge,tabCreature[y][x][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str())/2,tabCreature[y][x][1],0,collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());

                        ///FLECHE DROITE
                        al_draw_text(myMapPolice["70"],blanc,1280-26-21,310,0,">");
                        if (event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(myMapPolice["70"],rouge,1280-26-21,310,0,">");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                            {
                                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                page = 1;
                                x = 0;
                                y = 0;
                            }
                        }
                    }


                    ///PAGE ENERGIES
                    if (page == 1)
                    {
                        al_draw_bitmap(mapBitmap["fondCollectionEnergies"],0,0,0);

                        ///AFFICHAGE NOMS
                        cpt = 20;
                        for(int j = 0; j < 4; j++)
                        {
                            for(int i = 0; i < 4; i++)
                            {
                                al_draw_text(myMapPolice["30"],colorText,tabEnergie[j][i][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[cpt]->getNom().c_str())/2,tabEnergie[j][i][1],0,collection.getCarte()[cpt]->getNom().c_str());
                                tabEnergie[j][i][2] = cpt;
                                cpt++;
                            }
                        }

                        ///AFFICHAGE SELECTION
                        al_draw_rectangle(tabEnergie[y][x][0]-1,tabEnergie[y][x][1]-20,tabEnergie[y][x][0]+160-1,tabEnergie[y][x][1]+80-20,noirPresque2,7);
                        al_draw_text(myMapPolice["30"],rouge,tabEnergie[y][x][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str())/2,tabEnergie[y][x][1],0,collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());

                        ///FLECHE DROITE
                        al_draw_text(myMapPolice["70"],blanc,1280-26-21,310,0,">");
                        if (event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(myMapPolice["70"],rouge,1280-26-21,310,0,">");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                page = 2;
                                x = 0;
                                y = 0;
                            }
                        }

                        ///FLECHE GAUCHE
                        al_draw_text(myMapPolice["70"],blanc,26,310,0,"<");
                        if (event.mouse.x >= 26 && event.mouse.x <= 26+21 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(myMapPolice["70"],rouge,26,310,0,"<");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                page = 0;
                                x = 0;
                                y = 0;
                            }
                        }
                    }


                    ///PAGE SPECIALES
                    if (page == 2)
                    {
                        al_draw_bitmap(mapBitmap["fondCollectionSpeciales"],0,0,0);

                        ///AFFICHAGE NOMS
                        cpt = 36;
                        for(int j = 0; j < 2; j++)
                        {
                            for(int i = 0; i < 3; i++)
                            {
                                al_draw_text(myMapPolice["30"],colorText,tabSpeciales[j][i][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[cpt]->getNom().c_str())/2,tabSpeciales[j][i][1],0,collection.getCarte()[cpt]->getNom().c_str());
                                tabSpeciales[j][i][2] = cpt;
                                cpt++;
                            }
                        }

                        ///AFFICHAGE SELECTION
                        al_draw_rectangle(tabSpeciales[y][x][0]-1,tabSpeciales[y][x][1]-20,tabSpeciales[y][x][0]+160-1,tabSpeciales[y][x][1]+80-20,noirPresque2,7);
                        al_draw_text(myMapPolice["30"],rouge,tabSpeciales[y][x][0] + 80 - al_get_text_width(myMapPolice["30"],collection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str())/2,tabSpeciales[y][x][1],0,collection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str());

                        ///FLECHE GAUCHE
                        al_draw_text(myMapPolice["70"],blanc,26,310,0,"<");
                        if (event.mouse.x >= 26 && event.mouse.x <= 26+21 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
                        {
                            al_draw_text(myMapPolice["70"],rouge,26,310,0,"<");

                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                            {
                                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                page = 1;
                                x = 0;
                                y = 0;
                            }
                        }
                    }


                    ///MOUVEMENTS
                    if (event.type == ALLEGRO_EVENT_KEY_CHAR)
                    {
                        ///PAGE CREATURE
                        if (page == 0 && event.type == ALLEGRO_EVENT_KEY_CHAR)
                        {
                            switch (event.keyboard.keycode)
                            {
                                case ALLEGRO_KEY_UP: if(y != 0) y--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_RIGHT: if(x != 4) x++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_DOWN: if(y != 3) y++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_ENTER:
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
                                        if (achat(&tabJoueur[numeroJoueur],collection.getCarte()[tabCreature[y][x][2]]) == 1)
                                        {
                                            autorisation = 0;
                                        }
                                        else
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        carteAchetee = collection.getCarte()[tabCreature[y][x][2]];
                                        compteurDeCartesChoisies++;
                                    }
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    pv = std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getPV());
                                    degat1 = "Degats : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDegat());
                                    degat2 = "Degats : " + std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDegat());
                                    argentCarte = std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getPrix());
                                    argentJoueur = std::to_string(tabJoueur[numeroJoueur].getArgent());

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

                                    al_draw_text(myMapPolice["35"],noirPresque,280,220,0,argentCarte.c_str());
                                    al_draw_text(myMapPolice["35"],noirPresque,246,172,0,argentJoueur.c_str());

                                    al_draw_text(myMapPolice["40"],noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,collection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());
                                    al_draw_text(myMapPolice["35"],noirPresque,758 + 27,92,ALLEGRO_ALIGN_CENTER,pv.c_str());

                                    al_draw_text(myMapPolice["30"],noirPresque,470,390,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getNom().c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque2,470,425,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDesc().c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque,470,465,0,degat1.c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque,800,465,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

                                    al_draw_text(myMapPolice["30"],noirPresque,470,520,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getNom().c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque2,470,555,0,collection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDesc().c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque,470,595,0,degat2.c_str());
                                    al_draw_text(myMapPolice["30"],noirPresque,800,595,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());


                                    al_draw_bitmap(mapBitmap[collection.getCarte()[tabCreature[y][x][2]]->getNom()],460,163,0);
                                    break;
                            }
                        }
                        ///PAGE ENERGIE
                        if (page == 1 && event.type == ALLEGRO_EVENT_KEY_CHAR)
                        {
                            switch (event.keyboard.keycode)
                            {
                                case ALLEGRO_KEY_UP: if(y != 0) y--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_RIGHT: if(x != 3) x++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_DOWN: if(y != 3) y++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
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
                                        if (achat(&tabJoueur[numeroJoueur],collection.getCarte()[tabEnergie[y][x][2]]) == 1)
                                        {
                                            autorisation = 0;
                                        }
                                        else
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        carteAchetee = collection.getCarte()[tabEnergie[y][x][2]];
                                        compteurDeCartesChoisies++;
                                    }
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    lvlEnergie = std::to_string(collection.getCarte()[tabEnergie[y][x][2]]->getLV());
                                    argentCarte = std::to_string(collection.getCarte()[tabEnergie[y][x][2]]->getPrix());
                                    argentJoueur = std::to_string(tabJoueur[numeroJoueur].getArgent());

                                    al_draw_bitmap(mapBitmap["templateCarteEnergie"],0,0,0);

                                    al_draw_text(myMapPolice["35"],noirPresque,280,220,0,argentCarte.c_str());
                                    al_draw_text(myMapPolice["35"],noirPresque,246,172,0,argentJoueur.c_str());

                                    al_draw_text(myMapPolice["40"],noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,collection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());
                                    al_draw_text(myMapPolice["40"],noirPresque,778 + 8,88,ALLEGRO_ALIGN_CENTER,lvlEnergie.c_str());

                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "H")
                                    {
                                        al_draw_bitmap(mapBitmap["fondHaki"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,540,ALLEGRO_ALIGN_CENTER,"Energie mentale devastatrice");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "K")
                                    {
                                        al_draw_bitmap(mapBitmap["fondKi"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie vitale pouvant");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"etre deployée");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "N")
                                    {
                                        al_draw_bitmap(mapBitmap["fondNen"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Force d'esprit");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"creant une aura puissante");
                                    }
                                    if (collection.getCarte()[tabEnergie[y][x][2]]->getType() == "C")
                                    {
                                        al_draw_bitmap(mapBitmap["fondChakra"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie spirituelle");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"circulant dans le corps");
                                    }
                                    break;
                            }
                        }
                        ///PAGE SPECIALES
                        if (page == 2 && event.type == ALLEGRO_EVENT_KEY_CHAR)
                        {
                            switch (event.keyboard.keycode)
                            {
                                case ALLEGRO_KEY_UP: if(y != 0) y--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_RIGHT: if(x != 2) x++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_DOWN: if(y != 1) y++;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--;
                                    al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                    break;
                                case ALLEGRO_KEY_ENTER:
                                    autorisation = 0;
                                    for (auto &elem : tabJoueur[numeroJoueur].getDeck().getDeck())
                                    {
                                        if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == elem->getNom())
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        if (achat(&tabJoueur[numeroJoueur],collection.getCarte()[tabSpeciales[y][x][2]]) == 1)
                                        {
                                            autorisation = 0;
                                        }
                                        else
                                        {
                                            autorisation = 1;
                                        }
                                    }
                                    if (autorisation == 0)
                                    {
                                        carteAchetee = collection.getCarte()[tabSpeciales[y][x][2]];
                                        compteurDeCartesChoisies++;
                                    }
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    argentCarte = std::to_string(collection.getCarte()[tabCreature[y][x][2]]->getPrix());
                                    argentJoueur = std::to_string(tabJoueur[numeroJoueur].getArgent());

                                    al_draw_bitmap(mapBitmap["templateCarteSpeciale"],0,0,0);

                                    al_draw_text(myMapPolice["35"],noirPresque,280,220,0,argentCarte.c_str());
                                    al_draw_text(myMapPolice["35"],noirPresque,246,172,0,argentJoueur.c_str());

                                    al_draw_text(myMapPolice["40"],noirPresque,463 + 361/2,88,ALLEGRO_ALIGN_CENTER,collection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str());

                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Nécromancien")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Réanimation d'une carte");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"du cimetière");
                                    }
                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Super énergie")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,440,ALLEGRO_ALIGN_CENTER,"Ajout de deux energies de");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,480,ALLEGRO_ALIGN_CENTER,"de chaque type");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"dans votre main");
                                    }
                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Boule de Feu")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Attaque directe sur l'ennemi");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"en échange de points de vie");
                                    }
                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Vision Ultime")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"], 460, 163, 0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2, 480,ALLEGRO_ALIGN_CENTER,"Permet de voir sa pioche");
                                    }
                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Main magique")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Choix possible de la");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"prochaine carte piochée");
                                    }
                                    if (collection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Protection")
                                    {
                                        al_draw_bitmap(mapBitmap["fondCarteSpeciale"], 460,163, 0);
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,440,ALLEGRO_ALIGN_CENTER,"Protection contre la");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,480,ALLEGRO_ALIGN_CENTER,"prochaine attaque");
                                        al_draw_text(myMapPolice["35"],noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"de l'ennemi");
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


                compteurDeCartesChoisies = 0;
                deckComplet = false;
                x = 0;
                y = 0;


                do
                {
                    ///ATTENTES D'EVENEMENTS
                    al_wait_for_event(queue,&event);

                    al_draw_bitmap(mapBitmap["fondCollectionDeck"],0,0,0);

                    ///AFFICHAGE NOMS
                    cpt = 0;
                    for(int j = 0; j < 3; j++)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            al_draw_text(myMapPolice["30"],colorText,tabDeck[j][i][0] + 80 - al_get_text_width(myMapPolice["30"],tabJoueur[numeroJoueur].getDeck().getDeck()[cpt]->getNom().c_str())/2,tabDeck[j][i][1],0,tabJoueur[numeroJoueur].getDeck().getDeck()[cpt]->getNom().c_str());
                            tabDeck[j][i][2] = cpt;
                            cpt++;
                        }
                    }

                    ///AFFICHAGE SELECTION
                    al_draw_rectangle(tabDeck[y][x][0]-1,tabDeck[y][x][1]-20,tabDeck[y][x][0]+160-1,tabDeck[y][x][1]+80-20,noirPresque2,7);
                    al_draw_text(myMapPolice["30"],rouge,tabDeck[y][x][0] + 80 - al_get_text_width(myMapPolice["30"],tabJoueur[numeroJoueur].getDeck().getDeck()[tabDeck[y][x][2]]->getNom().c_str())/2,tabDeck[y][x][1],0,tabJoueur[numeroJoueur].getDeck().getDeck()[tabDeck[y][x][2]]->getNom().c_str());


                    ///MOUVEMENTS
                    if (event.type == ALLEGRO_EVENT_KEY_CHAR)
                    {
                        switch (event.keyboard.keycode)
                        {
                                case ALLEGRO_KEY_UP: if(y != 0) y--;
                                al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_RIGHT: if(x != 4) x++;
                                al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_DOWN: if(y != 2) y++;
                                al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_LEFT: if(x != 0) x--;
                                al_play_sample(mapSample["click2"],0.5,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);
                                break;
                                case ALLEGRO_KEY_ENTER:
                                    carteRemplacee = tabJoueur[numeroJoueur].getDeck().getDeck()[tabDeck[y][x][2]];
                                    compteurDeCartesChoisies++;
                                    break;
                                case ALLEGRO_KEY_SPACE:
                                    break;
                            }
                    }

                    ///DECK COMPLET
                    if (compteurDeCartesChoisies == 1)
                    {
                        deckComplet = true;
                    }

                    al_flip_display();

                } while (!deckComplet);

                al_destroy_event_queue(queue);

                std::cout << "Carte a rajouter : " << carteAchetee->getNom() << std::endl;
                std::cout << "Carte a enlever  : " << carteRemplacee->getNom() << std::endl;

                achatCarteBoutique(&tabJoueur[numeroJoueur],carteAchetee,carteRemplacee);

                ///SAUVEGARDE
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
                al_play_sample(mapSample["click"],1,0,1,ALLEGRO_PLAYMODE_ONCE, nullptr);

                choix = 1;
            }
        }
        al_flip_display();

    }while (choix != 1);
}

void achatCarteBoutique(Joueur* joueur, Carte* carteARajouter, Carte* carteAEnlever)
{
    Deck nouveauDeck;
    Carte* carteTempo;

    for (int i = 0; i < NOMBRE_CARTES_DECK; i++)
    {
        if (joueur->getDeck().getDeck()[i] == carteAEnlever)
        {
            carteTempo = carteARajouter;
        }
        else
        {
            carteTempo = joueur->getDeck().getDeck()[i];
        }
        nouveauDeck.setDeck(carteTempo);
    }

    joueur->setDeck(nouveauDeck);
}