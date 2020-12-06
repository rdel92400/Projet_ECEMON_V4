#include <iostream>
#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"
#include "Joueur.h"
#include "sauvegarde.h"
#include "Allegro.h"
#include "menu.h"


int main()
{
    ///ALEATOIRE
    std::srand ( unsigned ( std::time(nullptr) ) );

    ///Ini de la collection
    Collections collection;
    collection.chargerCollectionEntiere();
    //collection.chargementCreatures(); (chargement avec fichiers non fonctionnel)

    ///VARIABLES ALLEGRO
    ALLEGRO_DISPLAY *display = nullptr;
    ALLEGRO_BITMAP* fondChargement;
    std::map<std::string,ALLEGRO_SAMPLE*> mapSample;
    std::map<std::string,ALLEGRO_BITMAP*> mapBitmap;
    std::map<std::string,ALLEGRO_FONT*> mapFont;


    ///INI ALLEGRO
    if(!al_init())
    {
        erreur("Initialisation","Initialisation Allegro");
    }
    if (!al_init_image_addon())
    {
        erreur("Initialisation","Initialisation Image");
    }
    if (!al_install_mouse())
    {
        erreur("Initialisation","Initialisation Souris");
    }
    if (!al_install_keyboard())
    {
        erreur("Initialisation","Initialisation Clavier");
    }
    al_install_audio();
    if (!al_init_acodec_addon())
    {
        erreur("Initialisation","Initialisation Acodec");
    }
    al_init_font_addon();
    if (!al_init_ttf_addon())
    {
        erreur("Initialisation","Initialisation TTF");
    }
    if (!al_init_primitives_addon())
    {
        erreur("Initialisation","Initialisation Primitives dessins");
    }


    ///INI MUSIQUE
    al_reserve_samples(3);
    mapSample["menu"] = al_load_sample("..\\Musique\\menu.ogg");
    if (!mapSample["menu"])
    {
        erreur("Chargement","menu.ogg");
    }
    mapSample["combat"] = al_load_sample("..\\Musique\\combat.ogg");
    if (!mapSample["combat"])
    {
        erreur("Chargement","combat.ogg");
    }
    mapSample["click"] = al_load_sample("..\\Musique\\click.ogg");
    if (!mapSample["click"])
    {
        erreur("Chargement","click.ogg");
    }
    mapSample["click2"] = al_load_sample("..\\Musique\\click2.ogg");
    if (!mapSample["click2"])
    {
        erreur("Chargement","click2.ogg");
    }


    ///CREATION DE LA FENETRE
    display = al_create_display(1280,720);
    if(!display)
    {
        erreur("Fenetre","Creation de la fenetre");
    }


    ///AFFICHAGE ECRAN DE CHARGEMENT
    fondChargement = chargement("..\\Bitmaps\\Fonds\\fondChargement.bmp");
    al_draw_bitmap(fondChargement,0,0,0);
    al_flip_display();


    ///CHARGEMENT BITMAPS / FONTS
    mapBitmap = chargementBitmaps();
    mapFont = chargementToutesLesPolices();


    ///LANCEMENT DU JEU
    menu(mapBitmap,mapFont,mapSample);


    destructionBitmaps(mapBitmap);
    al_destroy_bitmap(fondChargement);
    al_destroy_sample(mapSample["menu"]);
    al_destroy_sample(mapSample["combat"]);
    al_destroy_sample(mapSample["click"]);
    al_destroy_display(display);


    //menu();

    return 0;
}

