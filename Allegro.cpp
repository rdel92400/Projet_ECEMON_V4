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
    mymap["fondMenuBoutique"] = chargement("..\\Bitmaps\\Fonds\\fondMenuPrincipalBoutique.bmp");
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
    mymap["fondCollectionSpeciales"] = chargement("..\\Bitmaps\\Fonds\\fondCollectionSpeciales.bmp");
    mymap["fondCollectionDeck"] = chargement("..\\Bitmaps\\Fonds\\fondCollectionDeck.bmp");
    mymap["templateCarteCreature"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteCreature.bmp");
    mymap["templateCarteEnergie"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteEnergie.bmp");
    mymap["templateCarteSpeciale"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteSpeciale.bmp");
    mymap["fondChakra"] = chargement("..\\Bitmaps\\Templates\\fondChakra.bmp");
    mymap["fondNen"] = chargement("..\\Bitmaps\\Templates\\fondNen.bmp");
    mymap["fondKi"] = chargement("..\\Bitmaps\\Templates\\fondKi.bmp");
    mymap["fondHaki"] = chargement("..\\Bitmaps\\Templates\\fondHaki.bmp");
    mymap["fondCarteSpeciale"] = chargement("..\\Bitmaps\\Templates\\fondCarteSpeciale.bmp");
    mymap["fondJeu"] = chargement("..\\Bitmaps\\Fonds\\fondJeu.bmp");
    mymap["fondChargementJoueurOui"] = chargement("..\\Bitmaps\\Fonds\\fondChargementJoueurOui.bmp");
    mymap["fondChargementJoueurNon"] = chargement("..\\Bitmaps\\Fonds\\fondChargementJoueurNon.bmp");
    mymap["fondBoutique"] = chargement("..\\Bitmaps\\Fonds\\fondBoutique.bmp");
    mymap["fondBoutiqueAcheter"] = chargement("..\\Bitmaps\\Fonds\\fondBoutiqueAcheter.bmp");
    mymap["fondBoutiqueRetour"] = chargement("..\\Bitmaps\\Fonds\\fondBoutiqueRetour.bmp");
    mymap["fondChargementJoueurOui"] = chargement("..\\Bitmaps\\Fonds\\fondChargementJoueurOui.bmp");
    mymap["fondChargementJoueurNon"] = chargement("..\\Bitmaps\\Fonds\\fondChargementJoueurNon.bmp");
    mymap["fondPartiePioche"] = chargement("..\\Bitmaps\\Fonds\\fondPartiePioche.bmp");
    mymap["fondPartieAttaque"] = chargement("..\\Bitmaps\\Fonds\\fondPartieAttaque.bmp");
    mymap["fondAffichagePioche"] = chargement("..\\Bitmaps\\Fonds\\fondAffichagePioche.bmp");
    mymap["templateCarteCreatureVide"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteCreatureVide.bmp");
    mymap["templateCarteEnergieVide"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteEnergieVide.bmp");
    mymap["templateCarteSpecialeVide"] = chargement("..\\Bitmaps\\Templates\\TemplateCarteSpecialVide.bmp");
    mymap["templateAffichageEnergie"] = chargement("..\\Bitmaps\\Templates\\templateAffichageEnergie.bmp");
    mymap["templateAffichageZoneTexte"] = chargement("..\\Bitmaps\\Templates\\templateAffichageZoneTexte.bmp");
    mymap["boutonOuiNon"] = chargement("..\\Bitmaps\\Boutons\\boutonsOuiNon.bmp");
    mymap["boutonOuiNonSmall"] = chargement("..\\Bitmaps\\Boutons\\boutonOuiNonSmall.bmp");
    mymap["bouton1Ou2"] = chargement("..\\Bitmaps\\Boutons\\bouton1Ou2.bmp");
    mymap["fondVictoire"] = chargement("..\\Bitmaps\\Fonds\\fondVictoire.bmp");
    mymap["fondCarteDejaPossede1"] = chargement("..\\Bitmaps\\Fonds\\fondCarteDejaPossede1.bmp");
    mymap["fondCarteDejaPossede2"] = chargement("..\\Bitmaps\\Fonds\\fondCarteDejaPossede2.bmp");

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
    al_destroy_bitmap(mymap["fondChargementJoueurOui"]);
    al_destroy_bitmap(mymap["fondChargementJoueurNon"]);
    al_destroy_bitmap(mymap["fondPartiePioche"]);
    al_destroy_bitmap(mymap["fondPartieAttaque"]);
    al_destroy_bitmap(mymap["templateCarteCreatureVide"]);
    al_destroy_bitmap(mymap["templateCarteEnergieVide"]);
    al_destroy_bitmap(mymap["templateCarteSpecialeVide"]);
    al_destroy_bitmap(mymap["boutonOuiNon"]);

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
        if (mouse.x >= 556 && mouse.x <= 556+168 && mouse.y >= 720-18-66 && mouse.y <= 720-18)
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


void iniTabCollectionEnergie(int miseEnPage[4][4][3])
{
    int EspaceDefense = 160;
    int EspaceInterDefenses = 80;
    int Xinitial = 200;
    int Yinitial = 130+20;

    for(int j = 0; j < 4; j++)
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


void iniTabCollectionSpeciale(int miseEnPage[2][3][3])
{
    int EspaceDefense = 160;
    int EspaceInterDefenses = 80;
    int Xinitial = 320;
    int Yinitial = 230+20;

    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < 3; i++)
        {
            miseEnPage[j][i][0] = Xinitial;
            Xinitial = miseEnPage[j][i][0] + EspaceDefense + EspaceInterDefenses;

            miseEnPage[j][i][1] = Yinitial;
        }
        Yinitial = Yinitial + 130;
        Xinitial = 320;
    }
}


void iniTabCollectionDeck(int miseEnPage[3][5][3])
{
    int EspaceDefense = 160;
    int EspaceInterDefenses = 80;
    int Xinitial = 80;
    int Yinitial = 190+20;

    for(int j = 0; j < 3; j++)
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

std::string iniNomChargementJoueur(ALLEGRO_BITMAP* fond, int posX, int posY, std::map<int,std::string> tabNoms)
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
    int fin(0);
    char ascii;

    al_draw_bitmap(fond,0,0,0);
    for (const auto &elem : tabNoms)
    {
        al_draw_text(agencyFB,colorText,1280/2,elem.first,ALLEGRO_ALIGN_CENTER,elem.second.c_str());
    }
    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if(event.type == ALLEGRO_EVENT_KEY_CHAR)
        {
            ///ESPACE
            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
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

            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                fin = 1;
            }
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

        for (const auto &elem : tabNoms)
        {
            al_draw_text(agencyFB,colorText,1280/2,elem.first,ALLEGRO_ALIGN_CENTER,elem.second.c_str());
        }

        al_draw_text(agencyFB,colorText,posX,posY,0,nom.c_str());
        al_flip_display();

    }while (fin == 0);

    return nom;
}


void affichageNomPvEnergie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_FONT* agencyFB = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);

    std::string pv = std::to_string(p.getPDV());
    std::string H = std::to_string(p.getEnergie()["H"]);
    std::string K = std::to_string(p.getEnergie()["K"]);
    std::string N = std::to_string(p.getEnergie()["N"]);
    std::string C = std::to_string(p.getEnergie()["C"]);

    al_draw_text(agencyFB,colorText,44+265/2,53,ALLEGRO_ALIGN_CENTER,p.getNom().c_str());

    al_draw_text(agencyFB,colorText,352+78/2,53,ALLEGRO_ALIGN_CENTER,pv.c_str());

    al_draw_bitmap(mymap["templateAffichageEnergie"],513,38,0);

    al_draw_text(agencyFB,colorText,637,115,0,H.c_str());
    al_draw_text(agencyFB,colorText,756,115,0,K.c_str());
    al_draw_text(agencyFB,colorText,672,157,0,C.c_str());
    al_draw_text(agencyFB,colorText,783,157,0,N.c_str());

    al_flip_display();
}

void actionPioche(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",40);
    ALLEGRO_FONT* agencyFB3 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB4 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",22);
    ALLEGRO_FONT* agencyFB5 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",18);
    ALLEGRO_FONT* agencyFB6 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",16);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    int condition = 0;
    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;

    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,340,ALLEGRO_ALIGN_CENTER,"Pressez P");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,390,ALLEGRO_ALIGN_CENTER,"pour piocher");
    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_P)
        {
            condition = 1;
        }

    }while (condition == 0);

    al_draw_bitmap(mymap["fondPartiePioche"],0,0,0);
    affichageCarteActive(p,mymap);
    affichageNomPvEnergie(p,mymap);
    affichageCarteEnjeu(p);

    if (p.getPioche().front()->get_EstUtilise() == CREATURE)
    {
        pv = std::to_string(p.getPioche().front()->getPV());
        degat1 = "Degats : " + std::to_string(p.getPioche().front()->getAttaque()[0].getDegat());
        degat2 = "Degats : " + std::to_string(p.getPioche().front()->getAttaque()[1].getDegat());

        if (p.getPioche().front()->getAttaque(0).getEnergie() == "H")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(0).getEnergieLV()) + " Haki";
            energieRequis2 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(1).getEnergieLV()) + " Haki";
        }
        if (p.getPioche().front()->getAttaque(0).getEnergie() == "N")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(0).getEnergieLV()) + " Nen";
            energieRequis2 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(1).getEnergieLV()) + " Nen";
        }
        if (p.getPioche().front()->getAttaque(0).getEnergie() == "K")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(0).getEnergieLV()) + " Ki";
            energieRequis2 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(1).getEnergieLV()) + " Ki";
        }
        if (p.getPioche().front()->getAttaque(0).getEnergie() == "C")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(0).getEnergieLV()) + " Chakra";
            energieRequis2 = "Requis : " + std::to_string(p.getPioche().front()->getAttaque(1).getEnergieLV()) + " Chakra";
        }

        al_draw_scaled_bitmap(mymap["templateCarteCreatureVide"],0,0,410,608,574,352,225,333.6,0);
        al_draw_scaled_bitmap(mymap[p.getPioche().front()->getNom()],0,0,359,202,574+14,352+59,197.5,111,0);

        al_draw_text(agencyFB3,colorText,574+14+151/2,365,ALLEGRO_ALIGN_CENTER,p.getPioche().front()->getNom().c_str());
        al_draw_text(agencyFB4,colorText,574+14+151+10+37/2,370,ALLEGRO_ALIGN_CENTER,pv.c_str());

        al_draw_text(agencyFB5,colorText,595,535,0,p.getPioche().front()->getAttaque(0).getNom().c_str());
        al_draw_text(agencyFB6,colorTextSmall,595,555,0,p.getPioche().front()->getAttaque(0).getDesc().c_str());
        al_draw_text(agencyFB5,colorText,595,575,0,degat1.c_str());
        al_draw_text(agencyFB5,colorText,777,575,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

        al_draw_text(agencyFB5,colorText,595,607,0,p.getPioche().front()->getAttaque(1).getNom().c_str());
        al_draw_text(agencyFB6,colorTextSmall,595,627,0,p.getPioche().front()->getAttaque(1).getDesc().c_str());
        al_draw_text(agencyFB5,colorText,595,647,0,degat2.c_str());
        al_draw_text(agencyFB5,colorText,777,647,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());
    }
    else if (p.getPioche().front()->get_EstUtilise() == ENERGIE)
    {
        lvlEnergie = std::to_string(p.getPioche().front()->getLV());

        al_draw_scaled_bitmap(mymap["templateCarteEnergieVide"],0,0,410,608,574,352,225,333.6,0);
        al_draw_text(agencyFB3,colorText,574+14+151/2,365,ALLEGRO_ALIGN_CENTER,p.getPioche().front()->getNom().c_str());
        al_draw_text(agencyFB4,colorText,574+14+151+10+37/2,370,ALLEGRO_ALIGN_CENTER,lvlEnergie.c_str());

        if (p.getPioche().front()->getType() == "H")
        {
            al_draw_scaled_bitmap(mymap["fondHaki"],0,0,359,319,575+14,353.5+59,197.5,175.5,0);
            al_draw_text(agencyFB5,colorText,575+224/2,610,ALLEGRO_ALIGN_CENTER,"Energie mentale devastatrice");
        }
        if (p.getPioche().front()->getType() == "K")
        {
            al_draw_scaled_bitmap(mymap["fondKi"],0,0,359,319,575+14,353.5+59,197.5,175.5,0);
            al_draw_text(agencyFB5,colorText,575+224/2,610,ALLEGRO_ALIGN_CENTER,"Energie vitale pouvant");
            al_draw_text(agencyFB5,colorText,575+224/2,630,ALLEGRO_ALIGN_CENTER,"etre deployée");
        }
        if (p.getPioche().front()->getType() == "C")
        {
            al_draw_scaled_bitmap(mymap["fondChakra"],0,0,359,319,575+14,353.5+59,197.5,175.5,0);
            al_draw_text(agencyFB5,colorText,575+224/2,610,ALLEGRO_ALIGN_CENTER,"Energie spirituelle");
            al_draw_text(agencyFB5,colorText,575+224/2,630,ALLEGRO_ALIGN_CENTER,"circulant dans le corps");
        }
        if (p.getPioche().front()->getType() == "N")
        {
            al_draw_scaled_bitmap(mymap["fondNen"],0,0,359,319,575+14,353.5+59,197.5,175.5,0);
            al_draw_text(agencyFB5,colorText,575+224/2,610,ALLEGRO_ALIGN_CENTER,"Force d'esprit");
            al_draw_text(agencyFB5,colorText,575+224/2,630,ALLEGRO_ALIGN_CENTER,"creant une aura puissante");
        }
    }
    else
    {
        al_draw_scaled_bitmap(mymap["templateCarteSpecialeVide"],0,0,410,608,574,352,225,333.6,0);
        al_draw_scaled_bitmap(mymap["fondCarteSpeciale"],0,0,359,202,574.5+14,353+59,197.5,110.5,0);
        al_draw_text(agencyFB3,colorText,574+14+197/2,365,ALLEGRO_ALIGN_CENTER,p.getPioche().front()->getNom().c_str());

        if (p.getPioche().front()->get_EstUtilise() == NECRO)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,560,ALLEGRO_ALIGN_CENTER,"Réanimation d'une carte");
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"du cimetière");
        }
        if (p.getPioche().front()->get_EstUtilise() == SUPER_ENERGIE)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,560,ALLEGRO_ALIGN_CENTER,"Ajout de deux energies de");
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"de chaque type");
            al_draw_text(agencyFB5,colorText,575+224/2,600,ALLEGRO_ALIGN_CENTER,"dans votre main");
        }
        if (p.getPioche().front()->get_EstUtilise() == BOULE_DE_FEU)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,560,ALLEGRO_ALIGN_CENTER,"Attaque directe sur l'ennemi");
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"en échange de points de vie");
        }
        if (p.getPioche().front()->get_EstUtilise() == VISION_ULTIME)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"Permet de voir sa pioche");
        }
        if (p.getPioche().front()->get_EstUtilise() == MAIN_MAGIQUE)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,560,ALLEGRO_ALIGN_CENTER,"Choix possible de la");
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"prochaine carte piochée");
        }
        if (p.getPioche().front()->get_EstUtilise() == PROTECTION)
        {
            al_draw_text(agencyFB5,colorText,575+224/2,560,ALLEGRO_ALIGN_CENTER,"Protection contre la");
            al_draw_text(agencyFB5,colorText,575+224/2,580,ALLEGRO_ALIGN_CENTER,"prochaine attaque");
            al_draw_text(agencyFB5,colorText,575+224/2,600,ALLEGRO_ALIGN_CENTER,"de l'ennemi");
        }
    }

    al_flip_display();
}

int choixPioche1(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int choix;
    int fin(0);
    int bouton(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Voulez vous jouer");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"cette carte ?");
    al_draw_bitmap(mymap["boutonOuiNon"],44+386/2-293/2,425,0);
    al_flip_display();


    do
    {
        al_wait_for_event(queue,&event);
        al_draw_bitmap(mymap["boutonOuiNon"],44+386/2-293/2,425,0);
        al_flip_display();

        if (bouton == 0)
        {
            al_draw_rectangle(93.5,427.5,90+135,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                bouton = 1;
            }
            choix = 1;
        }
        if (bouton == 1)
        {
            al_draw_rectangle(94+135+23,427.5,89+135+135+23,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                bouton = 0;
            }
            choix = 2;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            fin = 1;
        }
        al_flip_display();

    }while (fin != 1);

    return choix;
}


int choixPioche2(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int choix;
    int fin(0);
    int bouton(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,265,ALLEGRO_ALIGN_CENTER,"Voulez vous vraiment");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,315,ALLEGRO_ALIGN_CENTER,"remplacer votre carte");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,365,ALLEGRO_ALIGN_CENTER,"active ?");


    do
    {
        al_wait_for_event(queue,&event);
        al_draw_bitmap(mymap["boutonOuiNon"],44+386/2-293/2,425,0);
        al_flip_display();

        if (bouton == 0)
        {
            al_draw_rectangle(93.5,427.5,90+135,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                bouton = 1;
            }
            choix = 1;
        }
        if (bouton == 1)
        {
            al_draw_rectangle(94+135+23,427.5,89+135+135+23,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                bouton = 0;
            }
            choix = 2;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            fin = 1;
        }
        al_flip_display();

    }while (fin != 1);

    return choix;
}


void affichageRemiseSousPioche(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"La carte a été remise");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"dans la pioche");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"pour continuer");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichageCarteAjoutee(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"La carte a été jouée");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"avec succès");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"pour continuer");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichagePasDeCarteActive(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Vous n'avez pas de");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"carte créature active");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichagePasDeCarteActiveEnnemie(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,275,ALLEGRO_ALIGN_CENTER,"L'ennemi n'a pas de");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,325,ALLEGRO_ALIGN_CENTER,"carte créature active");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,375,ALLEGRO_ALIGN_CENTER,"=> -50");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichageCarteActive(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",40);
    ALLEGRO_FONT* agencyFB3 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB4 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",22);
    ALLEGRO_FONT* agencyFB5 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",18);
    ALLEGRO_FONT* agencyFB6 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",16);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);

    if (p.getCreature() != nullptr)
    {
        std::string energieRequis1;
        std::string energieRequis2;
        std::string pv = std::to_string(p.getCreature()->getPV());
        std::string degat1 = "Degats : " + std::to_string(p.getCreature()->getAttaque()[0].getDegat());
        std::string degat2 = "Degats : " + std::to_string(p.getCreature()->getAttaque()[1].getDegat());

        if (p.getCreature()->getAttaque(0).getEnergie() == "H")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Haki";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Haki";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "N")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Nen";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Nen";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "K")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Ki";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Ki";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "C")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Chakra";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Chakra";
        }

        al_draw_scaled_bitmap(mymap["templateCarteCreatureVide"],0,0,410,608,913,115.5,329,487,0);
        al_draw_scaled_bitmap(mymap[p.getCreature()->getNom()],0,0,359,202,913+20,116.5+85,288,162,0);

        al_draw_text(agencyFB2,colorText,1280-351+228/2,138,ALLEGRO_ALIGN_CENTER,p.getCreature()->getNom().c_str());
        al_draw_text(agencyFB3,colorText,1280-117+62/2,145,ALLEGRO_ALIGN_CENTER,pv.c_str());

        al_draw_text(agencyFB3,colorText,1280-351+15,380,0,p.getCreature()->getAttaque(0).getNom().c_str());
        al_draw_text(agencyFB4,colorTextSmall,1280-351+15,420,0,p.getCreature()->getAttaque(0).getDesc().c_str());
        al_draw_text(agencyFB4,colorText,1280-351+15,450,0,degat1.c_str());
        al_draw_text(agencyFB4,colorText,1280-56-15,450,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

        al_draw_text(agencyFB3,colorText,1280-351+15,482,0,p.getCreature()->getAttaque(1).getNom().c_str());
        al_draw_text(agencyFB4,colorTextSmall,1280-351+15,522,0,p.getCreature()->getAttaque(1).getDesc().c_str());
        al_draw_text(agencyFB4,colorText,1280-351+15,552,0,degat2.c_str());
        al_draw_text(agencyFB4,colorText,1280-56-15,552,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());

        al_flip_display();
    }
}


void affichageCarteActiveEnnemie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_FONT* agencyFB3 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB4 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",22);
    ALLEGRO_FONT* agencyFB5 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",18);
    ALLEGRO_FONT* agencyFB6 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",16);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);

    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;

    if (p.getCreature() != nullptr)
    {
        pv = std::to_string(p.getCreature()->getPV());
        degat1 = "Degats : " + std::to_string(p.getCreature()->getAttaque()[0].getDegat());
        degat2 = "Degats : " + std::to_string(p.getCreature()->getAttaque()[1].getDegat());

        if (p.getCreature()->getAttaque(0).getEnergie() == "H")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Haki";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Haki";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "N")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Nen";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Nen";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "K")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Ki";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Ki";
        }
        if (p.getCreature()->getAttaque(0).getEnergie() == "C")
        {
            energieRequis1 = "Requis : " + std::to_string(p.getCreature()->getAttaque(0).getEnergieLV()) + " Chakra";
            energieRequis2 = "Requis : " + std::to_string(p.getCreature()->getAttaque(1).getEnergieLV()) + " Chakra";
        }

        al_draw_scaled_bitmap(mymap["templateCarteCreatureVide"],0,0,410,608,574,352,225,333.6,0);
        al_draw_scaled_bitmap(mymap[p.getCreature()->getNom()],0,0,359,202,574+14,352+59,197.5,111,0);

        al_draw_text(agencyFB3,colorText,574+14+151/2,365,ALLEGRO_ALIGN_CENTER,p.getCreature()->getNom().c_str());
        al_draw_text(agencyFB4,colorText,574+14+151+10+37/2,370,ALLEGRO_ALIGN_CENTER,pv.c_str());

        al_draw_text(agencyFB5,colorText,595,535,0,p.getCreature()->getAttaque(0).getNom().c_str());
        al_draw_text(agencyFB6,colorTextSmall,595,555,0,p.getCreature()->getAttaque(0).getDesc().c_str());
        al_draw_text(agencyFB5,colorText,595,575,0,degat1.c_str());
        al_draw_text(agencyFB5,colorText,777,575,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

        al_draw_text(agencyFB5,colorText,595,607,0,p.getCreature()->getAttaque(1).getNom().c_str());
        al_draw_text(agencyFB6,colorTextSmall,595,627,0,p.getCreature()->getAttaque(1).getDesc().c_str());
        al_draw_text(agencyFB5,colorText,595,647,0,degat2.c_str());
        al_draw_text(agencyFB5,colorText,777,647,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());

        al_flip_display();
    }
}


int choixSiAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int choix;
    int fin(0);
    int bouton(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Voulez vous attaquer");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"l'adversaire ?");
    al_draw_bitmap(mymap["boutonOuiNon"],44+386/2-293/2,425,0);
    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        al_draw_bitmap(mymap["boutonOuiNon"],44+386/2-293/2,425,0);
        al_flip_display();

        if (bouton == 0)
        {
            al_draw_rectangle(93.5,427.5,90+135,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                bouton = 1;
            }
            choix = 1;
        }
        if (bouton == 1)
        {
            al_draw_rectangle(94+135+23,427.5,89+135+135+23,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                bouton = 0;
            }
            choix = 2;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            fin = 1;
        }
        al_flip_display();

    }while (fin != 1);

    return choix;
}


int choixAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int choix;
    int fin(0);
    int bouton(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Quelle attaque");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"voulez vous utiliser ?");
    al_draw_bitmap(mymap["bouton1Ou2"],44+386/2-293/2,425,0);
    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        al_draw_bitmap(mymap["bouton1Ou2"],44+386/2-293/2,425,0);
        al_flip_display();

        if (bouton == 0)
        {
            al_draw_rectangle(93.5,427.5,90+135,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                bouton = 1;
            }
            choix = 1;
        }
        if (bouton == 1)
        {
            al_draw_rectangle(94+135+23,427.5,89+135+135+23,422.5+84,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                bouton = 0;
            }
            choix = 2;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            fin = 1;
        }
        al_flip_display();

    }while (fin != 1);

    return choix;
}


void affichagePasAssezEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Impposible vous n'avez");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"pas assez d'energie");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}

void affichageAttaqueReussie(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,325,ALLEGRO_ALIGN_CENTER,"Attaque reussie !");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichageJoueurSuivant(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,325,ALLEGRO_ALIGN_CENTER,"Tour terminé");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


void affichageJoueurProtege(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE COMBAT");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Joueur ennemi protégé");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"par la carte PROTECTION");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"passer au joueur suivant");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}

void affichageCarteEnjeu(Plateau p)
{
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);

    std::string chaine = "Enjeu : " + p.GetCarteEJ()->getNom();

    al_draw_text(agencyFB2,colorText,1080,630,ALLEGRO_ALIGN_CENTER,chaine.c_str());

    al_flip_display();
}

void affichageSuperEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Vous avez gagné 2 énergies");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"de chaque type !");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}

void affichageProtection(std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Vous serez protégé");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"au prochain tour !");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

    }while (condition == 0);
}


int affichageBouleDeFeu(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);
    std::string pv;
    std::string pvEnnemi = "PV de l'adversaire :" + std::to_string(p.getPDV());
    int cpt(0);
    char ascii;

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,250,ALLEGRO_ALIGN_CENTER,"L'adversaire perd 1.5x");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"des PV sacrifiés (<250) !");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2-60,400,0,pvEnnemi.c_str());
    al_draw_text(agencyFB2,colorTextSmall,44+385/2-60,360,0,"PV sacrifiés : ");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

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
            else if (event.keyboard.keycode == 63 && pv.size() > 0)
            {
                ascii = 8;
                pv.pop_back();
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
                pv = pv + ascii;
            }
            cpt = 0;
        }

        al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
        al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,275,ALLEGRO_ALIGN_CENTER,"L'adversaire perd 1.5x");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,325,ALLEGRO_ALIGN_CENTER,"les PV sacrifiés (<250) !");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2-30,360,0,"PV : ");

        al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

        al_draw_text(agencyFB2,colorText,44+385/2+5,360,0,pv.c_str());

        al_flip_display();


        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_P)
        {
            condition = 1;
        }
        if (atoi(pv.c_str()) < 0 || atoi(pv.c_str()) > 250)
        {
            condition = 0;
        }

    } while (condition == 0);

    return atoi(pv.c_str());
}


void affichageVisionUltime(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_FONT* agencyFB3 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);
    int posY(151);
    std::string carte;

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Pressez Espace pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"afficher votre pioche");

    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_SPACE)
        {
            al_draw_bitmap(mymap["fondAffichagePioche"],0,0,0);

            posY = 151;

            for (int i = 0; i < p.getPioche().size(); i++)
            {
                carte = "Carte " + std::to_string(i) + " : ";
                al_draw_text(agencyFB3,colorText,520,posY,0,carte.c_str());
                al_draw_text(agencyFB3,colorText,612,posY,0,p.getPioche()[i]->getNom().c_str());

                posY = posY + 35;
            }

            al_flip_display();
        }
        else
        {
            al_draw_bitmap(mymap["fondPartiePioche"],0,0,0);
            affichageCarteActive(p,mymap);
            affichageNomPvEnergie(p,mymap);
            affichageCarteEnjeu(p);

            al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
            al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
            al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Pressez Espace pour");
            al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"afficher votre pioche");

            al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
            al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

            al_flip_display();
        }

        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }

        al_flip_display();

    }while (condition == 0);
}


std::string affichageMainMagique(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",45);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int condition(0);
    std::string nom;
    int cpt(0);
    char ascii;

    al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
    al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,250,ALLEGRO_ALIGN_CENTER,"L'adversaire perd 1.5x");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"des PV sacrifiés (<250) !");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2-60,360,0,"Carte Choisie : ");


    al_draw_text(agencyFB2,colorTextSmall,44+385/2,300,ALLEGRO_ALIGN_CENTER,"Pressez Espace pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,350,ALLEGRO_ALIGN_CENTER,"afficher votre pioche");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
    al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

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

        al_draw_bitmap(mymap["templateAffichageZoneTexte"],33,167,0);
        al_draw_text(agencyFB1,rouge,44+385/2,200,ALLEGRO_ALIGN_CENTER,"PHASE DE PIOCHE");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,275,ALLEGRO_ALIGN_CENTER,"L'adversaire perd 1.5x");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,325,ALLEGRO_ALIGN_CENTER,"les PV sacrifiés (<250) !");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2-30,360,0,"PV : ");

        al_draw_text(agencyFB2,colorTextSmall,44+385/2,440,ALLEGRO_ALIGN_CENTER,"Pressez Entrer pour");
        al_draw_text(agencyFB2,colorTextSmall,44+385/2,490,ALLEGRO_ALIGN_CENTER,"continuer");

        al_draw_text(agencyFB2,colorText,44+385/2+5,360,0,nom.c_str());

        al_flip_display();


        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_P)
        {
            condition = 1;
        }
        if (atoi(nom.c_str()) < 0 || atoi(nom.c_str()) > 250)
        {
            condition = 0;
        }

    } while (condition == 0);

    return nom;
}

void affichageVictoire(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mymap)
{
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event;
    if (!queue)
        erreur("Initialisation","queue");
    al_register_event_source(queue,al_get_keyboard_event_source());

    ALLEGRO_FONT* agencyFB70 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",70);
    ALLEGRO_FONT* agencyFB1 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",50);
    ALLEGRO_FONT* agencyFB40 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",40);
    ALLEGRO_FONT* agencyFB2 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",35);
    ALLEGRO_FONT* agencyFB3 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);
    ALLEGRO_FONT* agencyFB4 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",22);
    ALLEGRO_FONT* agencyFB5 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",18);
    ALLEGRO_FONT* agencyFB6 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",16);
    ALLEGRO_COLOR colorText = al_map_rgb(30,30,30);
    ALLEGRO_COLOR colorTextSmall = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);

    int menu(0);
    ALLEGRO_MOUSE_STATE mouse;

    int condition(0);
    bool choix(false);
    int bouton(0);
    std::string pv;
    std::string degat1;
    std::string degat2;
    std::string energieRequis1;
    std::string energieRequis2;
    std::string lvlEnergie;

    al_draw_bitmap(mymap["fondVictoire"],0,0,0);

    al_draw_text(agencyFB70,rouge,405,194,ALLEGRO_ALIGN_CENTER,gagnant.getNom().c_str());
    al_draw_text(agencyFB1,colorText,410,390,0,"500");
    al_draw_text(agencyFB1,colorText,410,452,0,perdant.GetCarteEJ()->getNom().c_str());


    if (perdant.GetCarteEJ()->get_EstUtilise() == CREATURE)
    {
        pv = std::to_string(perdant.GetCarteEJ()->getPV());
        degat1 = "Degats : " + std::to_string(perdant.GetCarteEJ()->getAttaque()[0].getDegat());
        degat2 = "Degats : " + std::to_string(perdant.GetCarteEJ()->getAttaque()[1].getDegat());

        if (perdant.GetCarteEJ()->getAttaque(0).getEnergie() == "H")
        {
            energieRequis1 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(0).getEnergieLV()) + " Haki";
            energieRequis2 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(1).getEnergieLV()) + " Haki";
        }
        if (perdant.GetCarteEJ()->getAttaque(0).getEnergie() == "N")
        {
            energieRequis1 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(0).getEnergieLV()) + " Nen";
            energieRequis2 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(1).getEnergieLV()) + " Nen";
        }
        if (perdant.GetCarteEJ()->getAttaque(0).getEnergie() == "K")
        {
            energieRequis1 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(0).getEnergieLV()) + " Ki";
            energieRequis2 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(1).getEnergieLV()) + " Ki";
        }
        if (perdant.GetCarteEJ()->getAttaque(0).getEnergie() == "C")
        {
            energieRequis1 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(0).getEnergieLV()) + " Chakra";
            energieRequis2 = "Requis : " + std::to_string(perdant.GetCarteEJ()->getAttaque(1).getEnergieLV()) + " Chakra";
        }

        al_draw_bitmap(mymap["templateCarteCreatureVide"],774,57,0);

        al_draw_text(agencyFB40,colorText,463 + 275/2 + 338,88,ALLEGRO_ALIGN_CENTER,perdant.GetCarteEJ()->getNom().c_str());
        al_draw_text(agencyFB2,colorText,758 + 27 + 338,92,ALLEGRO_ALIGN_CENTER,pv.c_str());

        al_draw_text(agencyFB3,colorText,470 + 338,390,0,perdant.GetCarteEJ()->getAttaque(0).getNom().c_str());
        al_draw_text(agencyFB3,colorTextSmall,470 + 338,425,0,perdant.GetCarteEJ()->getAttaque(0).getDesc().c_str());
        al_draw_text(agencyFB3,colorText,470 + 338,465,0,degat1.c_str());
        al_draw_text(agencyFB3,colorText,800 + 338,465,ALLEGRO_ALIGN_RIGHT,energieRequis1.c_str());

        al_draw_text(agencyFB3,colorText,470 + 338,520,0,perdant.GetCarteEJ()->getAttaque(1).getNom().c_str());
        al_draw_text(agencyFB3,colorTextSmall,470 + 338,555,0,perdant.GetCarteEJ()->getAttaque(1).getDesc().c_str());
        al_draw_text(agencyFB3,colorText,470 + 338,595,0,degat2.c_str());
        al_draw_text(agencyFB3,colorText,800 + 338,595,ALLEGRO_ALIGN_RIGHT,energieRequis2.c_str());

        al_draw_bitmap(mymap[perdant.GetCarteEJ()->getNom()],460 + 339,163,0);
    }
    else if (perdant.GetCarteEJ()->get_EstUtilise() == ENERGIE)
    {
        lvlEnergie = std::to_string(perdant.GetCarteEJ()->getLV());

        al_draw_bitmap(mymap["templateCarteEnergieVide"],774,57,0);

        al_draw_text(agencyFB40,colorText,463 + 275/2 + 338,88,ALLEGRO_ALIGN_CENTER,perdant.GetCarteEJ()->getNom().c_str());
        al_draw_text(agencyFB40,colorText,778 + 8 + 338,88,ALLEGRO_ALIGN_CENTER,lvlEnergie.c_str());

        if (perdant.GetCarteEJ()->getType() == "H")
        {
            al_draw_bitmap(mymap["fondHaki"],460 + 338+2,163+3,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,540,ALLEGRO_ALIGN_CENTER,"Energie mentale devastatrice");
        }
        if (perdant.GetCarteEJ()->getType() == "K")
        {
            al_draw_bitmap(mymap["fondKi"],460 + 338+2,163+3,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,520,ALLEGRO_ALIGN_CENTER,"Energie vitale pouvant");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,560,ALLEGRO_ALIGN_CENTER,"etre deployée");
        }
        if (perdant.GetCarteEJ()->getType() == "C")
        {
            al_draw_bitmap(mymap["fondChakra"],460 + 338+2,163+3,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,520,ALLEGRO_ALIGN_CENTER,"Energie spirituelle");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,560,ALLEGRO_ALIGN_CENTER,"circulant dans le corps");
        }
        if (perdant.GetCarteEJ()->getType() == "N")
        {
            al_draw_bitmap(mymap["fondNen"],460 + 338+2,163+3,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/ + 338,520,ALLEGRO_ALIGN_CENTER,"Force d'esprit");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,560,ALLEGRO_ALIGN_CENTER,"creant une aura puissante");
        }
    }
    else
    {
        al_draw_bitmap(mymap["templateCarteSpecialeVide"],774,57,0);

        al_draw_text(agencyFB40,colorText,463 + 361/2 + 338,88,ALLEGRO_ALIGN_CENTER,perdant.GetCarteEJ()->getNom().c_str());

        if (perdant.GetCarteEJ()->get_EstUtilise() == NECRO)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"],460 + 340,165,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,460,ALLEGRO_ALIGN_CENTER,"Réanimation d'une carte");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,500,ALLEGRO_ALIGN_CENTER,"du cimetière");
        }
        if (perdant.GetCarteEJ()->get_EstUtilise() == SUPER_ENERGIE)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"],460 + 340,165,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,440,ALLEGRO_ALIGN_CENTER,"Ajout de deux energies de");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,480,ALLEGRO_ALIGN_CENTER,"de chaque type");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,520,ALLEGRO_ALIGN_CENTER,"dans votre main");
        }
        if (perdant.GetCarteEJ()->get_EstUtilise() == BOULE_DE_FEU)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"],460 + 340,165,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,460,ALLEGRO_ALIGN_CENTER,"Attaque directe sur l'ennemi");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,500,ALLEGRO_ALIGN_CENTER,"en échange de points de vie");
        }
        if (perdant.GetCarteEJ()->get_EstUtilise() == VISION_ULTIME)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"], 460 + 340, 165, 0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338, 480,ALLEGRO_ALIGN_CENTER,"Permet de voir sa pioche");
        }
        if (perdant.GetCarteEJ()->get_EstUtilise() == MAIN_MAGIQUE)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"],460 + 340,165,0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,460,ALLEGRO_ALIGN_CENTER,"Choix possible de la");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,500,ALLEGRO_ALIGN_CENTER,"prochaine carte piochée");
        }
        if (perdant.GetCarteEJ()->get_EstUtilise() == PROTECTION)
        {
            al_draw_bitmap(mymap["fondCarteSpeciale"], 460 + 340,165, 0);
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,440,ALLEGRO_ALIGN_CENTER,"Protection contre la");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,480,ALLEGRO_ALIGN_CENTER,"prochaine attaque");
            al_draw_text(agencyFB2,colorTextSmall,460 + 359/2 + 338,520,ALLEGRO_ALIGN_CENTER,"de l'ennemi");
        }
    }

    al_draw_bitmap(mymap["boutonOuiNonSmall"],426,720-155,0);
    al_flip_display();

    do
    {
        al_wait_for_event(queue,&event);

        al_draw_bitmap(mymap["boutonOuiNonSmall"],426,720-155,0);
        al_flip_display();

        if (bouton == 0)
        {
            al_draw_rectangle(426+3,720-155+3,426+110-2,720-155+69-2,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                bouton = 1;
            }
            choix = true;
        }
        if (bouton == 1)
        {
            al_draw_rectangle(426+110+18.5+2,720-155+3,426+2*110+18.5-3,720-155+69-2,rouge,5);
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                bouton = 0;
            }
            choix = false;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            condition = 1;
        }
        al_flip_display();

    }while (condition == 0);

    condition = 0;

    if (choix)
    {
        for (const auto& elem : gagnant.getDeck().getDeck())
        {
            if (elem->getNom() == perdant.GetCarteEJ()->getNom())
            {
                condition = 1;
            }
        }

        if (condition == 0)
        {
            ajoutCarteEnjeu(gagnant,perdant,mymap);
        }
        else
        {
            do
            {
                al_draw_bitmap(mymap["fondCarteDejaPossede1"],0,0,0);

                al_get_mouse_state(&mouse);

                ///RETOUR
                if (mouse.x >= 556 && mouse.x <= 556+168 && mouse.y >= 720-18-66 && mouse.y <= 720-18)
                {
                    al_draw_bitmap(mymap["fondCarteDejaPossede2"],0,0,0);

                    if (mouse.buttons & 1)
                    {
                        menu = 1;
                    }
                }
                al_flip_display();

            }while (menu != 1);
        }

    }
}


void ajoutCarteEnjeu(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap)
{
    ALLEGRO_FONT* agencyFB30 = chargementPolice("..\\Fonts\\agency-fb-bold.ttf",30);

    ALLEGRO_COLOR colorText = al_map_rgb(55,55,55);
    ALLEGRO_COLOR rouge = al_map_rgb(193,39,45);
    ALLEGRO_COLOR noirPresque2 = al_map_rgb(35,35,35);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_EVENT event = {0};
    if (!queue)
    {
        erreur("Initialisation","queue");
    }
    al_register_event_source(queue,al_get_keyboard_event_source());

    Collections collection;
    std::map<int, Joueur> tabJoueur;

    bool deckComplet = false;
    int compteurDeCartesChoisies(0);
    int x(0), y(0);
    int cpt(0);
    int numeroJoueur(0);
    int tabDeck[3][5][3] = {0};
    Carte* carteRemplacee;

    iniTabCollectionDeck(tabDeck);
    collection.chargerCollectionEntiere();

    tabJoueur = chargementJoueurs(collection);

    for (auto &elem : tabJoueur)
    {
        if (gagnant.getNom() == elem.second.getNom())
        {
            numeroJoueur = elem.first;
        }
    }

    std::cout << "NOM DU JOUEUR GAGNANT : " << tabJoueur[numeroJoueur].getNom() << std::endl;

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
                al_draw_text(agencyFB30,colorText,tabDeck[j][i][0] + 80 - al_get_text_width(agencyFB30,tabJoueur[numeroJoueur].getDeck().getDeck()[cpt]->getNom().c_str())/2,tabDeck[j][i][1],0,tabJoueur[numeroJoueur].getDeck().getDeck()[cpt]->getNom().c_str());
                tabDeck[j][i][2] = cpt;
                cpt++;
            }
        }

        ///AFFICHAGE SELECTION
        al_draw_rectangle(tabDeck[y][x][0]-1,tabDeck[y][x][1]-20,tabDeck[y][x][0]+160-1,tabDeck[y][x][1]+80-20,noirPresque2,7);
        al_draw_text(agencyFB30,rouge,tabDeck[y][x][0] + 80 - al_get_text_width(agencyFB30,tabJoueur[numeroJoueur].getDeck().getDeck()[tabDeck[y][x][2]]->getNom().c_str())/2,tabDeck[y][x][1],0,tabJoueur[numeroJoueur].getDeck().getDeck()[tabDeck[y][x][2]]->getNom().c_str());


        ///MOUVEMENTS
        if (event.type == ALLEGRO_EVENT_KEY_CHAR)
        {
            switch (event.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP: if(y != 0) y--; break;
                case ALLEGRO_KEY_RIGHT: if(x != 4) x++; break;
                case ALLEGRO_KEY_DOWN: if(y != 2) y++; break;
                case ALLEGRO_KEY_LEFT: if(x != 0) x--; break;
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

    std::cout << "CARTE A RAJOUTER : " << perdant.GetCarteEJ()->getNom() << std::endl;
    std::cout << "CARTE A ENLEVER  : " << carteRemplacee->getNom() << std::endl;

    achatCarteBoutique(&tabJoueur[numeroJoueur],perdant.GetCarteEJ(),carteRemplacee);

    ///SAUVEGARDE
    RemplacedeJoueur(tabJoueur,collection);
}
