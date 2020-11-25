//
// Created by charles on 25/11/2020.
//

#include "Allegro.h"

void erreur(const char* titre, const char* txt)
{
    ALLEGRO_DISPLAY *d;
    d = al_is_system_installed() ? al_get_current_display() : nullptr;
    al_show_native_message_box(d, titre, txt, nullptr, nullptr, 0);
    exit(EXIT_FAILURE);
}


ALLEGRO_FONT* chargementPolice(const std::string& nomImage,int size)
{
    ALLEGRO_FONT* police;
    police = al_load_ttf_font(nomImage.c_str(),size,0);
    if (!police)
    {
        erreur("Chargement Font TTF",nomImage.c_str());
    }
    return police;
}


ALLEGRO_BITMAP* chargement(const std::string& nomImage)
{
    ALLEGRO_BITMAP *bmp;
    bmp = al_load_bitmap(nomImage.c_str());
    if (!bmp)
    {
        erreur("Chargement bitmap",nomImage.c_str());
    }
    return bmp;
}


std::map<std::string,ALLEGRO_BITMAP*> chargementBitmaps()
{
    std::map<std::string,ALLEGRO_BITMAP*> mymap;


    mymap["fondMenu"] = chargement("..\\Bitmaps\\Fonds\\fondMenuPrincipal.bmp");
    mymap["fondMenuJouer"] = chargement("..\\Bitmaps\\Fonds\\fondMenuPrincipalJouer.bmp");
    mymap["fondMenuRegles"] = chargement("..\\Bitmaps\\Fonds\\fondMenuPrincipalRegles.bmp");
    mymap["fondMenuQuitter"] = chargement("..\\Bitmaps\\Fonds\\fondMenuPrincipalQuitter.bmp");
    mymap["fondRegles"] = chargement("..\\Bitmaps\\Fonds\\fondRegles.bmp");
    mymap["fondReglesRouge"] = chargement("..\\Bitmaps\\Fonds\\fondRegles1.bmp");
    mymap["fondCreaJoueur1"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur1.bmp");
    mymap["fondCreaJoueur2"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur2.bmp");
    mymap["fondCreaJoueur2Nouveau"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur2Nouveau.bmp");
    mymap["fondCreaJoueur2Existant"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur2Existant.bmp");
    mymap["fondCreaJoueur1Nouveau"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur1Nouveau.bmp");
    mymap["fondCreaJoueur1Existant"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur1Existant.bmp");
    mymap["fondCreaJoueur1Nom"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur1Nom.bmp");
    mymap["fondCreaJoueur2Nom"] = chargement("..\\Bitmaps\\Fonds\\fondCreaJoueur2Nom.bmp");
    mymap["fondCollectionCreatures"] = chargement("..\\Bitmaps\\Fonds\\fondCollectionCreatures.bmp");
    mymap["fondCollectionEnergies"] = chargement("..\\Bitmaps\\Fonds\\fondCollectionEnergies.bmp");
    mymap["templateCarteCreature"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteCreature.bmp");
    mymap["templateCarteEnergie"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteEnergie.bmp");
    mymap["fondChakra"] = chargement("..\\Bitmaps\\Templates\\fondChakra.bmp");
    mymap["fondNen"] = chargement("..\\Bitmaps\\Templates\\fondNen.bmp");
    mymap["fondKi"] = chargement("..\\Bitmaps\\Templates\\fondKi.bmp");
    mymap["fondHaki"] = chargement("..\\Bitmaps\\Templates\\fondHaki.bmp");
    mymap["fondJeu"] = chargement("..\\Bitmaps\\Fonds\\fondJeu.bmp");

    mymap["Chopper"] = chargement("..\\Bitmaps\\Cartes Creatures\\chopper.bmp");
    mymap["Usopp"] = chargement("..\\Bitmaps\\Cartes Creatures\\usopp.bmp");
    mymap["Sanji"] = chargement("..\\Bitmaps\\Cartes Creatures\\sanji.bmp");
    mymap["Roronoa zoro"] = chargement("..\\Bitmaps\\Cartes Creatures\\zorro.bmp");
    mymap["Monkey D Luffy"] = chargement("..\\Bitmaps\\Cartes Creatures\\luffy.bmp");
    mymap["Goku"] = chargement("..\\Bitmaps\\Cartes Creatures\\goku.bmp");
    mymap["Vegeta"] = chargement("..\\Bitmaps\\Cartes Creatures\\vegeta.bmp");
    mymap["Krilin"] = chargement("..\\Bitmaps\\Cartes Creatures\\krillin.bmp");
    mymap["Freezer"] = chargement("..\\Bitmaps\\Cartes Creatures\\freezer.bmp");
    mymap["Piccolo"] = chargement("..\\Bitmaps\\Cartes Creatures\\piccolo.bmp");
    mymap["Uzumaki Naruto"] = chargement("..\\Bitmaps\\Cartes Creatures\\naruto.bmp");
    mymap["Uchiwa Sasuke"] = chargement("..\\Bitmaps\\Cartes Creatures\\sasuke.bmp");
    mymap["Pain"] = chargement("..\\Bitmaps\\Cartes Creatures\\pain.bmp");
    mymap["Nara Shikamaru"] = chargement("..\\Bitmaps\\Cartes Creatures\\shikamaru.bmp");
    mymap["Haruno Sakura"] = chargement("..\\Bitmaps\\Cartes Creatures\\sakura.bmp");
    mymap["Gon Freecss"] = chargement("..\\Bitmaps\\Cartes Creatures\\gon.bmp");
    mymap["Kirua Zoldik"] = chargement("..\\Bitmaps\\Cartes Creatures\\kirua.bmp");
    mymap["Hisoka Morow"] = chargement("..\\Bitmaps\\Cartes Creatures\\hisoka.bmp");
    mymap["Kurapika"] = chargement("..\\Bitmaps\\Cartes Creatures\\kurapika.bmp");
    mymap["Isaac Netero"] = chargement("..\\Bitmaps\\Cartes Creatures\\netero.bmp");


    return mymap;
}


void destructionBitmaps(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    al_destroy_bitmap(mymap["fondMenu"]);
    al_destroy_bitmap(mymap["fondMenuJouer"]);
    al_destroy_bitmap(mymap["fondMenuRegles"]);
    al_destroy_bitmap(mymap["fondMenuQuitter"]);
    al_destroy_bitmap(mymap["fondRegles"]);
    al_destroy_bitmap(mymap["fondReglesRouge"]);
    al_destroy_bitmap(mymap["fondCreaJoueur1"]);
    al_destroy_bitmap(mymap["fondCreaJoueur2"]);
    al_destroy_bitmap(mymap["fondCreaJoueur1Nouveau"]);
    al_destroy_bitmap(mymap["fondCreaJoueur2Nouveau"]);
    al_destroy_bitmap(mymap["fondCreaJoueur1Existant"]);
    al_destroy_bitmap(mymap["fondCreaJoueur2Existant"]);
    al_destroy_bitmap(mymap["fondCreaJoueur1Nom"]);
    al_destroy_bitmap(mymap["fondCreaJoueur2Nom"]);
    al_destroy_bitmap(mymap["fondCollectionCreatures"]);
    al_destroy_bitmap(mymap["fondCollectionEnergies"]);
    al_destroy_bitmap(mymap["templateCarteCreature"]);
    al_destroy_bitmap(mymap["templateCarteEnergie"]);
    al_destroy_bitmap(mymap["fondChakra"]);
    al_destroy_bitmap(mymap["fondNen"]);
    al_destroy_bitmap(mymap["fondKi"]);
    al_destroy_bitmap(mymap["fondHaki"]);
    al_destroy_bitmap(mymap["fondJeu"]);

    al_destroy_bitmap(mymap["Chopper"]);
    al_destroy_bitmap(mymap["Usopp"]);
    al_destroy_bitmap(mymap["Sanji"]);
    al_destroy_bitmap(mymap["Roronoa zoro"]);
    al_destroy_bitmap(mymap["Monkey D Luffy"]);
    al_destroy_bitmap(mymap["Goku"]);
    al_destroy_bitmap(mymap["Vegeta"]);
    al_destroy_bitmap(mymap["Krilin"]);
    al_destroy_bitmap(mymap["Freezer"]);
    al_destroy_bitmap(mymap["Piccolo"]);
    al_destroy_bitmap(mymap["Uzumaki Naruto"]);
    al_destroy_bitmap(mymap["Uchiwa Sasuke"]);
    al_destroy_bitmap(mymap["Pain"]);
    al_destroy_bitmap(mymap["Nara Shikamaru"]);
    al_destroy_bitmap(mymap["Haruno Sakura"]);
    al_destroy_bitmap(mymap["Gon Freecss"]);
    al_destroy_bitmap(mymap["Kirua Zoldik"]);
    al_destroy_bitmap(mymap["Hisoka Morow"]);
    al_destroy_bitmap(mymap["Kurapika"]);
    al_destroy_bitmap(mymap["Isaac Netero"]);
}

void regles(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    int menu(0);
    ALLEGRO_MOUSE_STATE mouse;

    do
    {
        al_draw_bitmap(mapBitmap["fondRegles"],0,0,0);

        al_get_mouse_state(&mouse);

        ///RETOUR
        if (mouse.x >= 556 && mouse.x <= 556+168 && mouse.y >= 585 && mouse.y <= 585+66)
        {
            al_draw_bitmap(mapBitmap["fondReglesRouge"],0,0,0);

            if (mouse.buttons & 1)
            {
                menu = 1;
            }
        }
        al_flip_display();

    }while (menu != 1);
}


void iniTabCollectionCreature(int miseEnPage[4][5][3])
{
    int EspaceDefense = 160;
    int EspaceInterDefenses = 80;
    int Xinitial = 83;
    int Yinitial = 145;

    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            miseEnPage[j][i][0] = Xinitial;
            Xinitial = miseEnPage[j][i][0] + EspaceDefense + EspaceInterDefenses;

            miseEnPage[j][i][1] = Yinitial;
        }
        Yinitial = Yinitial + 130;
        Xinitial = 80;
    }
}


void iniTabCollectionEnergie(int miseEnPage[3][4][3])
{
    int EspaceDefense = 160;
    int EspaceInterDefenses = 80;
    int Xinitial = 200;
    int Yinitial = 165+20;

    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            miseEnPage[j][i][0] = Xinitial;
            Xinitial = miseEnPage[j][i][0] + EspaceDefense + EspaceInterDefenses;

            miseEnPage[j][i][1] = Yinitial;
        }
        Yinitial = Yinitial + 130;
        Xinitial = 200;
    }
}


std::string iniNom(ALLEGRO_BITMAP* fond)
{
    ALLEGRO_FONT* agencyFB = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",55);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;

    if (!queue)
        erreur("Initialisation","queue");

    al_register_event_source(queue,al_get_keyboard_event_source());


    std::string nom;
    int cpt(0);
    char ascii;

    al_draw_bitmap(fond,0,0,0);
    al_flip_display();
    do
    {
        al_wait_for_event(queue,&event);

        if(event.type == ALLEGRO_EVENT_KEY_CHAR)
        {
            ///ESPACE
            if (event.keyboard.keycode == 75)
            {
                ascii = 32;
            }
                ///BACKSPACE
            else if (event.keyboard.keycode == 63 && nom.size() > 0)
            {
                ascii = 8;
                nom.pop_back();
            }
                ///LETTRES
            else if (event.keyboard.keycode >= 1 && event.keyboard.keycode <= 26)
            {
                ascii = event.keyboard.keycode + 64;
            }
            else
            {
                ascii = 0;
            }
            cpt = 1;
        }

        if ((ascii >= 65 && ascii <= 90) || (ascii == 32))
        {
            if (cpt == 1)
            {
                nom = nom + ascii;
            }
            cpt = 0;
        }

        al_draw_bitmap(fond,0,0,0);
        al_draw_text(agencyFB,colorText,562,295,0,nom.c_str());
        al_flip_display();

    }while (event.keyboard.keycode != ALLEGRO_KEY_ENTER);

    return nom;
}