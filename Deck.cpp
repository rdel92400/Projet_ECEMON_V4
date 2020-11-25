//
// Created by Romain on 04/11/2020.
//

#include "Deck.h"
#include "Allegro.h"

Deck::Deck() {

}

Deck::~Deck() {

}
/*
void Deck::iniDeck(Collections toutesLesCartes) {

    Carte carteChoisie;
    int choix;
    std::string choixCarte;
    bool deckEstComplet = false;
    int compteurDeCartesChoisies(0);

    for (int i = 0; i < NOMBRE_CARTE_COLLEC; i++) {
        std::cout << "Carte " << i << " : \n";
        toutesLesCartes.getCarte()[i]->afficher();
    }

    ///Choix du joueur

    while (!deckEstComplet) {
        choix = 0;
        do {
            std::cout << "Quelle carte voulez vous voir ?" << std::endl;
            std::cin >> choix;
        } while (choix < 0 && choix > NOMBRE_CARTE_COLLEC);

        ///Probleme dans la classe collection constituée de créatures et pas de cartes

        toutesLesCartes.getCarte()[choix]->afficher();

        do {
            std::cout << "Voulez vous garder cette carte ?" << std::endl;
            std::cin >> choixCarte;
            std::cin.ignore();
        }while (choixCarte!="OUI" && choixCarte!="NON");


        if (choixCarte == "OUI") {
            compteurDeCartesChoisies++;
            setDeck(toutesLesCartes.getCarte()[choix]);
        } else{
            std::cout << "Choisissez une autre carte." << std::endl;
        }

        if (compteurDeCartesChoisies == NOMBRE_CARTES_DECK) {
            deckEstComplet = true;
        }


    }
    //afficherDeck();
}
*/

void Deck::iniDeck(Collections maCollection, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
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
    int tabEnergie[3][4][3] = {0};
    std::vector<int> tabCartePrise;
    std::vector<int> tabXCreaturePrise;
    std::vector<int> tabYCreaturePrise;
    std::vector<int> tabXEnergiePrise;
    std::vector<int> tabYEnergiePrise;
    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;

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
            for(int j = 0; j < 3; j++)
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

            ///AFFICHAGE ENERGIES DEJA PRISES
            for (int i = 0; i < tabXEnergiePrise.size(); i++)
            {
                al_draw_rectangle(tabXEnergiePrise[i],tabYEnergiePrise[i]-20,tabXEnergiePrise[i]+160-1,tabYEnergiePrise[i]+80-20,rouge,7);
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
                    case ALLEGRO_KEY_DOWN: if(y != 2) y++; break;
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

                        al_draw_bitmap(mapBitmap["templateCarteEnergie"],0,0,0);

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




