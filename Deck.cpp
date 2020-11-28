//
// Created by Romain on 04/11/2020.
//

#include "Deck.h"
#include "Allegro.h"
#include "Joueur.h"



Deck::Deck() {

}

Deck::~Deck() {

}


void Deck::iniDeck(Collections maCollection, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, Joueur joueur)
{
    Carte carteChoisie;
    int choix;
    std::string choixCarte;
    bool deckComplet = false;
    int compteurDeCartesChoisies(0);


    int x(0), y(0);
    int cpt(0);
    int page(0);
    int autorisation = 0;
    int tabCreature[4][5][3] = {0};
    int tabEnergie[4][4][3] = {0};
    int tabSpeciales[2][3][3] = {0};
    std::vector<int> tabCartePrise;
    std::vector<int> tabXCreaturePrise;
    std::vector<int> tabYCreaturePrise;
    std::vector<int> tabXEnergiePrise;
    std::vector<int> tabYEnergiePrise;
    std::vector<int> tabXSpecialePrise;
    std::vector<int> tabYSpecialePrise;
    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;
    std::string argentJoueur;
    std::string argentCarte;

    ALLEGRO_FONT* agencyFB30 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB33 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",33);
    ALLEGRO_FONT* agencyFB35 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_FONT* agencyFB70 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",70);
    ALLEGRO_FONT* agencyFB40 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",40);

    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);
    ALLEGRO_COLOR blanc = al_map_rgb(255,255,255);
    ALLEGRO_COLOR noirPresque = al_map_rgb(26,26,26);
    ALLEGRO_COLOR noirPresque2 = al_map_rgb(35,35,35);
    ALLEGRO_COLOR colorText = al_map_rgb(55,55,55);
    ALLEGRO_COLOR grisTransparent = al_map_rgba(55,55,55,220);
    ALLEGRO_COLOR grisClair = al_map_rgb(204,204,204);

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
                    al_draw_text(agencyFB30,colorText,tabCreature[j][i][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[cpt]->getNom().c_str())/2,tabCreature[j][i][1],0,maCollection.getCarte()[cpt]->getNom().c_str());
                    tabCreature[j][i][2] = cpt;
                    cpt++;
                }
            }

            ///AFFICHAGE SELECTION
            al_draw_rectangle(tabCreature[y][x][0]-1,tabCreature[y][x][1]-20,tabCreature[y][x][0]+160-1,tabCreature[y][x][1]+80-20,noirPresque2,7);
            al_draw_text(agencyFB30,rouge,tabCreature[y][x][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[tabCreature[y][x][2]]->getNom().c_str())/2,tabCreature[y][x][1],0,maCollection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());

            ///FLECHE DROITE
            al_draw_text(agencyFB70,blanc,1280-26-21,310,0,">");
            if (event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
            {
                al_draw_text(agencyFB70,rouge,1280-26-21,310,0,">");

                if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
                {
                    page = 1;
                    x = 0;
                    y = 0;
                }
            }

            ///AFFICHAGE CREATURES DEJA PRISES
            for (int i = 0; i < tabXCreaturePrise.size(); i++)
            {
                al_draw_rectangle(tabXCreaturePrise[i],tabYCreaturePrise[i]-20,tabXCreaturePrise[i]+160-1,tabYCreaturePrise[i]+80-20,rouge,7);
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
                    al_draw_text(agencyFB30,colorText,tabEnergie[j][i][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[cpt]->getNom().c_str())/2,tabEnergie[j][i][1],0,maCollection.getCarte()[cpt]->getNom().c_str());
                    tabEnergie[j][i][2] = cpt;
                    cpt++;
                }
            }

            ///AFFICHAGE SELECTION
            al_draw_rectangle(tabEnergie[y][x][0]-1,tabEnergie[y][x][1]-20,tabEnergie[y][x][0]+160-1,tabEnergie[y][x][1]+80-20,noirPresque2,7);
            al_draw_text(agencyFB30,rouge,tabEnergie[y][x][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str())/2,tabEnergie[y][x][1],0,maCollection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());

            ///FLECHE DROITE
            al_draw_text(agencyFB70,blanc,1280-26-21,310,0,">");
            if (event.mouse.x >= 1280-26-21 && event.mouse.x <= 1280-26 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
            {
                al_draw_text(agencyFB70,rouge,1280-26-21,310,0,">");

                if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                {
                    page = 2;
                    x = 0;
                    y = 0;
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
                    x = 0;
                    y = 0;
                }
            }

            ///AFFICHAGE ENERGIES DEJA PRISES
            for (int i = 0; i < tabXEnergiePrise.size(); i++)
            {
                al_draw_rectangle(tabXEnergiePrise[i],tabYEnergiePrise[i]-20,tabXEnergiePrise[i]+160-1,tabYEnergiePrise[i]+80-20,rouge,7);
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
                    al_draw_text(agencyFB30,colorText,tabSpeciales[j][i][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[cpt]->getNom().c_str())/2,tabSpeciales[j][i][1],0,maCollection.getCarte()[cpt]->getNom().c_str());
                    tabSpeciales[j][i][2] = cpt;
                    cpt++;
                }
            }

            ///AFFICHAGE SELECTION
            al_draw_rectangle(tabSpeciales[y][x][0]-1,tabSpeciales[y][x][1]-20,tabSpeciales[y][x][0]+160-1,tabSpeciales[y][x][1]+80-20,noirPresque2,7);
            al_draw_text(agencyFB30,rouge,tabSpeciales[y][x][0] + 80 - al_get_text_width(agencyFB30,maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str())/2,tabSpeciales[y][x][1],0,maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str());


            ///FLECHE GAUCHE
            al_draw_text(agencyFB70,blanc,26,310,0,"<");
            if (event.mouse.x >= 26 && event.mouse.x <= 26+21 && event.mouse.y >= 335 && event.mouse.y <= 338+33)
            {
                al_draw_text(agencyFB70,rouge,26,310,0,"<");

                if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
                {
                    page = 1;
                    x = 0;
                    y = 0;
                }
            }


            ///AFFICHAGE CREATURES DEJA PRISES
            for (int i = 0; i < tabXSpecialePrise.size(); i++)
            {
                al_draw_rectangle(tabXSpecialePrise[i],tabYSpecialePrise[i]-20,tabXSpecialePrise[i]+160-1,tabYSpecialePrise[i]+80-20,rouge,7);
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
                        autorisation = 0;
                        for (int i = 0; i < tabCartePrise.size(); ++i)
                        {
                            if (tabCreature[y][x][2] == tabCartePrise[i])
                            {
                                autorisation = 1;
                            }
                        }
                        if (autorisation == 0)
                        {
                            setDeck(maCollection.getCarte()[tabCreature[y][x][2]]);
                            tabCartePrise.push_back(tabCreature[y][x][2]);
                            tabXCreaturePrise.push_back(tabCreature[y][x][0]);
                            tabYCreaturePrise.push_back(tabCreature[y][x][1]);
                            compteurDeCartesChoisies++;

                            std::cout << maCollection.getCarte()[tabCreature[y][x][2]]->getNom() << std::endl;
                        }
                        break;
                    case ALLEGRO_KEY_SPACE:
                        pv = std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getPV());
                        degat1 = "Degats : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDegat());
                        degat2 = "Degats : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDegat());
                        argentCarte = std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getPrix());
                        argentJoueur = std::to_string(joueur.getArgent());

                        if (maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "H")
                        {
                            energieRequis1 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Haki";
                            energieRequis2 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Haki";
                        }
                        if (maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "N")
                        {
                            energieRequis1 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Nen";
                            energieRequis2 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Nen";
                        }
                        if (maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "K")
                        {
                            energieRequis1 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Ki";
                            energieRequis2 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Ki";
                        }
                        if (maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergie() == "C")
                        {
                            energieRequis1 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getEnergieLV()) + " Chakra";
                            energieRequis2 = "Requis : " + std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getEnergieLV()) + " Chakra";
                        }

                        al_draw_bitmap(mapBitmap["templateCarteCreature"],0,0,0);

                        al_draw_text(agencyFB35,noirPresque,280,220,0,argentCarte.c_str());
                        al_draw_text(agencyFB35,noirPresque,246,172,0,argentJoueur.c_str());

                        al_draw_text(agencyFB40,noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,maCollection.getCarte()[tabCreature[y][x][2]]->getNom().c_str());
                        al_draw_text(agencyFB35,noirPresque,758 + 27,92,ALLEGRO_ALIGN_CENTER,pv.c_str());

                        al_draw_text(agencyFB30,noirPresque,470,390,0,maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getNom().c_str());
                        al_draw_text(agencyFB30,noirPresque2,470,425,0,maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(0).getDesc().c_str());
                        al_draw_text(agencyFB30,noirPresque,470,465,0,degat1.c_str());
                        al_draw_text(agencyFB30,noirPresque,800,465,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

                        al_draw_text(agencyFB30,noirPresque,470,520,0,maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getNom().c_str());
                        al_draw_text(agencyFB30,noirPresque2,470,555,0,maCollection.getCarte()[tabCreature[y][x][2]]->getAttaque(1).getDesc().c_str());
                        al_draw_text(agencyFB30,noirPresque,470,595,0,degat2.c_str());
                        al_draw_text(agencyFB30,noirPresque,800,595,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());


                        al_draw_bitmap(mapBitmap[maCollection.getCarte()[tabCreature[y][x][2]]->getNom()],460,163,0);
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
                    case ALLEGRO_KEY_DOWN: if(y != 3) y++; break;
                    case ALLEGRO_KEY_LEFT: if(x != 0) x--; break;
                    case ALLEGRO_KEY_ENTER:
                        autorisation = 0;
                        for (int i = 0; i < tabCartePrise.size(); ++i)
                        {
                            if (tabEnergie[y][x][2] == tabCartePrise[i])
                            {
                                autorisation = 1;
                            }
                        }
                        if (autorisation == 0)
                        {
                            setDeck(maCollection.getCarte()[tabEnergie[y][x][2]]);
                            tabCartePrise.push_back(tabEnergie[y][x][2]);
                            tabXEnergiePrise.push_back(tabEnergie[y][x][0]);
                            tabYEnergiePrise.push_back(tabEnergie[y][x][1]);
                            compteurDeCartesChoisies++;

                            std::cout << maCollection.getCarte()[tabEnergie[y][x][2]]->getNom() << std::endl;
                        }
                        break;
                    case ALLEGRO_KEY_SPACE:
                        lvlEnergie = std::to_string(maCollection.getCarte()[tabEnergie[y][x][2]]->getLV());
                        argentCarte = std::to_string(maCollection.getCarte()[tabEnergie[y][x][2]]->getPrix());
                        argentJoueur = std::to_string(joueur.getArgent());

                        al_draw_bitmap(mapBitmap["templateCarteEnergie"],0,0,0);

                        al_draw_text(agencyFB35,noirPresque,280,220,0,argentCarte.c_str());
                        al_draw_text(agencyFB35,noirPresque,246,172,0,argentJoueur.c_str());

                        al_draw_text(agencyFB40,noirPresque,463 + 275/2,88,ALLEGRO_ALIGN_CENTER,maCollection.getCarte()[tabEnergie[y][x][2]]->getNom().c_str());
                        al_draw_text(agencyFB40,noirPresque,778 + 8,88,ALLEGRO_ALIGN_CENTER,lvlEnergie.c_str());

                        if (maCollection.getCarte()[tabEnergie[y][x][2]]->getType() == "H")
                        {
                            al_draw_bitmap(mapBitmap["fondHaki"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,540,ALLEGRO_ALIGN_CENTER,"Energie mentale devastatrice");
                        }
                        if (maCollection.getCarte()[tabEnergie[y][x][2]]->getType() == "K")
                        {
                            al_draw_bitmap(mapBitmap["fondKi"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie vitale pouvant");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"etre deployée");
                        }
                        if (maCollection.getCarte()[tabEnergie[y][x][2]]->getType() == "N")
                        {
                            al_draw_bitmap(mapBitmap["fondNen"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Force d'esprit");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"creant une aura puissante");
                        }
                        if (maCollection.getCarte()[tabEnergie[y][x][2]]->getType() == "C")
                        {
                            al_draw_bitmap(mapBitmap["fondChakra"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"Energie spirituelle");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,560,ALLEGRO_ALIGN_CENTER,"circulant dans le corps");
                        }
                        break;
                }
            }
            ///PAGE CREATURE
            if (page == 2)
            {
                switch (event.keyboard.keycode)
                {
                    case ALLEGRO_KEY_UP: if(y != 0) y--; break;
                    case ALLEGRO_KEY_RIGHT: if(x != 2) x++; break;
                    case ALLEGRO_KEY_DOWN: if(y != 1) y++; break;
                    case ALLEGRO_KEY_LEFT: if(x != 0) x--; break;
                    case ALLEGRO_KEY_ENTER:
                        autorisation = 0;
                        for (int i = 0; i < tabCartePrise.size(); ++i)
                        {
                            if (tabSpeciales[y][x][2] == tabCartePrise[i])
                            {
                                autorisation = 1;
                            }
                        }
                        if (autorisation == 0)
                        {
                            setDeck(maCollection.getCarte()[tabSpeciales[y][x][2]]);
                            tabCartePrise.push_back(tabSpeciales[y][x][2]);
                            tabXSpecialePrise.push_back(tabSpeciales[y][x][0]);
                            tabYSpecialePrise.push_back(tabSpeciales[y][x][1]);
                            compteurDeCartesChoisies++;
                        }
                        break;
                    case ALLEGRO_KEY_SPACE:
                        argentCarte = std::to_string(maCollection.getCarte()[tabCreature[y][x][2]]->getPrix());
                        argentJoueur = std::to_string(joueur.getArgent());

                        al_draw_bitmap(mapBitmap["templateCarteSpeciale"],0,0,0);

                        al_draw_text(agencyFB40,noirPresque,463 + 361/2,88,ALLEGRO_ALIGN_CENTER,maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom().c_str());
                        
                        al_draw_text(agencyFB35,noirPresque,280,220,0,argentCarte.c_str());
                        al_draw_text(agencyFB35,noirPresque,246,172,0,argentJoueur.c_str());

                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Nécromancien")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Réanimation d'une carte");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"du cimetière");
                        }
                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Super énergie")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,440,ALLEGRO_ALIGN_CENTER,"Ajout de deux energies de");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,480,ALLEGRO_ALIGN_CENTER,"de chaque type");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"dans votre main");
                        }
                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Boule de Feu")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Attaque directe sur l'ennemi");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"en échange de points de vie");
                        }
                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Vision Ultime")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"], 460, 163, 0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2, 480,ALLEGRO_ALIGN_CENTER,"Permet de voir sa pioche");
                        }
                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Main magique")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"],460,163,0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,460,ALLEGRO_ALIGN_CENTER,"Choix possible de la");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,500,ALLEGRO_ALIGN_CENTER,"prochaine carte piochée");
                        }
                        if (maCollection.getCarte()[tabSpeciales[y][x][2]]->getNom() == "Protection")
                        {
                            al_draw_bitmap(mapBitmap["fondCarteSpeciale"], 460,163, 0);
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,440,ALLEGRO_ALIGN_CENTER,"Protection contre la");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,480,ALLEGRO_ALIGN_CENTER,"prochaine attaque");
                            al_draw_text(agencyFB35,noirPresque2,460 + 359/2,520,ALLEGRO_ALIGN_CENTER,"de l'ennemi");
                        }
                        break;
                }
            }
        }


        ///DECK COMPLET
        if (compteurDeCartesChoisies == 5)
        {
            deckComplet = true;
        }


        al_flip_display();

    }while (!deckComplet);

    al_destroy_event_queue(queue);
}


void Deck::setDeck(Carte* nouvelleCarte) {
    m_deck.push_back(nouvelleCarte);
}

std::vector<Carte *> Deck::getDeck() const{
    return m_deck;
}

void Deck::afficherDeck() const{
    for (int i=0; i<NOMBRE_CARTES_DECK; i++){
        std::cout << "Carte numero " << i+1 << std::endl;
        getDeck()[i]->afficher();
    }
}




