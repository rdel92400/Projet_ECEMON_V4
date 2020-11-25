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
    ALLEGRO_SAMPLE* sample = nullptr;
    std::map<std::string,ALLEGRO_BITMAP*> mapBitmap;


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
    al_reserve_samples(1);
    sample = al_load_sample("..\\Musique\\Son 8.ogg");
    if (!sample)
    {
        erreur("Chargement","Son 8");
    }
    //al_play_sample(sample,1,0,1,ALLEGRO_PLAYMODE_LOOP, nullptr);


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


    ///CHARGEMENT BITMAPS
    mapBitmap = chargementBitmaps();


    ///LANCEMENT DU JEU
    menu(mapBitmap);


    destructionBitmaps(mapBitmap);
    al_destroy_bitmap(fondChargement);
    al_destroy_sample(sample);
    al_destroy_display(display);


    //menu();

    return 0;
}

