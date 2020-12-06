//
// Created by Romain on 21/11/2020.
//

#include "sauvegarde.h"
#include "Allegro.h"

void sauvegardeJoueur(Joueur joueurRecu, Collections collection) {
    std::map<int, std::string> indiceCarte;
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");

    for (int i = 0; i < NOMBRE_CARTE_COLLEC; i++) {
        indiceCarte[i] = collection.getCarte()[i]->getNom();
    }

    std::ofstream fichier(fichierDeSauvegarde.c_str(), std::ios::app);
    fichier.open("fichierDeSauvegarde", std::ios::app);

    if (fichier) {
        fichier << std::endl;

        fichier << joueurRecu.getNom() << std::endl;
        fichier << joueurRecu.getArgent() << std::endl;

        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
            for (const auto &elem : indiceCarte) {
                if (elem.second == joueurRecu.getDeck().getDeck()[i]->getNom()) {
                    fichier << elem.first << std::endl;
                }
            }

        }
        fichier << "stop" << std::endl;
    } else {
        std::cout << "Impossible d'ouvrir le fichier en ecriture" << std::endl;
    }

    fichier.close();
}


void RemplacedeJoueur(std::map<int, Joueur> joueursRecus, Collections collection)
{
    std::map<int, std::string> indiceCarte;
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");

    for (int i = 0; i < NOMBRE_CARTE_COLLEC; i++)
    {
        indiceCarte[i] = collection.getCarte()[i]->getNom();
    }

    std::ofstream fichier(fichierDeSauvegarde.c_str(), std::ios::out);
    fichier.open("fichierDeSauvegarde", std::ios::out);

    if (fichier)
    {
        for (auto &it : joueursRecus)
        {
            fichier << std::endl;

            fichier << it.second.getNom() << std::endl;
            fichier << it.second.getArgent() << std::endl;

            for (int i = 0; i < NOMBRE_CARTES_DECK; i++)
            {
                for (const auto &elem : indiceCarte)
                {
                    if (elem.second == it.second.getDeck().getDeck()[i]->getNom())
                    {
                        fichier << elem.first << std::endl;
                    }
                }
            }
            fichier << "stop" << std::endl;
        }
    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier en ecriture" << std::endl;
    }

    fichier.close();
}


Joueur chargementJoueur1(Collections collection, std::map<std::string, ALLEGRO_BITMAP *> mapBitmap, std::map<std::string,ALLEGRO_FONT*> myMapPolice) {
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");
    std::string nomRecup;
    std::string stopRecup;
    std::string arret = ("stop");
    int nombreRecup;
    int argentRecup;
    std::string choixNom;
    std::string finFichier;
    int index(0);

    std::map<int, std::string> tabNoms;

    int posY(230);

    Joueur joueurACharger;
    Deck deckaCharger;

    std::ifstream fichier(fichierDeSauvegarde.c_str(), std::ios::in);
    fichier.open("fichierDeSauvegarde", std::ios::in);

    if (fichier) {
        ///BOUCLE POUR ENREGISTREMENT DES NOMS
        while (getline(fichier, finFichier)) {
            al_draw_bitmap(mapBitmap["fondChargementJoueurOui"], 0, 0, 0);

            ///RECUP NOM
            fichier >> nomRecup;

            if (nomRecup != tabNoms[posY - 60]) {
                tabNoms[posY] = nomRecup;

                ///RECUP ARGENT
                fichier >> argentRecup;

                for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                    fichier >> nombreRecup;
                }

                ///RECUP STOP
                fichier >> stopRecup;

                posY = posY + 60;

                al_flip_display();
            }
        }
        fichier.close();

        do {
            choixNom = iniNomChargementJoueur(mapBitmap["fondChargementJoueurOui"], 670, 597, tabNoms,myMapPolice);

            fichier.open("fichierDeSauvegarde", std::ios::in);

            if (fichier) {
                ///Lecture du bon nom :
                while (getline(fichier, finFichier)) {
                    ///RECUP NOM
                    fichier >> nomRecup;

                    if (nomRecup == choixNom) {
                        ///RECUP ARGENT
                        fichier >> argentRecup;

                        joueurACharger.setNom(nomRecup);
                        joueurACharger.setArgent(argentRecup);

                        ///RECUP CARTES
                        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                            fichier >> nombreRecup;
                            deckaCharger.setDeck(collection.getCarte()[nombreRecup]);
                        }

                        joueurACharger.setDeck(deckaCharger);

                        index = 1;
                    } else {
                        ///RECUP ARGENT
                        fichier >> argentRecup;

                        ///RECUP CARTES
                        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                            fichier >> nombreRecup;
                        }

                        ///RECUP STOP
                        fichier >> stopRecup;
                    }
                }
            } else {
                std::cout << "Erreur ouverture fichier" << std::endl;
            }

            fichier.close();

        } while (index != 1);
    } else {
        std::cout << "Impossible d'ouvrir le fichier en LECTURE" << std::endl;
    }

    return joueurACharger;
}


Joueur chargementJoueur2(Collections collection, std::map<std::string, ALLEGRO_BITMAP *> mapBitmap, const std::string &nomJoueur1, std::map<std::string,ALLEGRO_FONT*> myMapPolice)
{
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");
    std::string nomRecup;
    std::string stopRecup;
    std::string arret = ("stop");
    int nombreRecup;
    int argentRecup;
    std::string choixNom;
    std::string finFichier;
    int index(0);

    std::map<int, std::string> tabNoms;

    int posY(230);

    Joueur joueurACharger;
    Deck deckaCharger;

    std::ifstream fichier(fichierDeSauvegarde.c_str(), std::ios::in);
    fichier.open("fichierDeSauvegarde", std::ios::in);

    if (fichier) {
        ///BOUCLE POUR ENREGISTREMENT DES NOMS
        while (getline(fichier, finFichier)) {
            al_draw_bitmap(mapBitmap["fondChargementJoueurOui"], 0, 0, 0);

            ///RECUP NOM
            fichier >> nomRecup;

            if (nomRecup != tabNoms[posY - 60]) {
                tabNoms[posY] = nomRecup;

                ///RECUP ARGENT
                fichier >> argentRecup;

                for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                    fichier >> nombreRecup;
                }

                ///RECUP STOP
                fichier >> stopRecup;

                posY = posY + 60;

                al_flip_display();
            }
        }
        fichier.close();

        do {
            choixNom = iniNomChargementJoueur(mapBitmap["fondChargementJoueurOui"], 670, 597, tabNoms,myMapPolice);

            fichier.open("fichierDeSauvegarde", std::ios::in);

            if (fichier) {
                ///Lecture du bon nom :
                while (getline(fichier, finFichier)) {
                    ///RECUP NOM
                    fichier >> nomRecup;

                    if (nomRecup == choixNom && choixNom != nomJoueur1) {
                        ///RECUP ARGENT
                        fichier >> argentRecup;

                        joueurACharger.setNom(nomRecup);
                        joueurACharger.setArgent(argentRecup);

                        ///RECUP CARTES
                        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                            fichier >> nombreRecup;
                            deckaCharger.setDeck(collection.getCarte()[nombreRecup]);
                        }

                        joueurACharger.setDeck(deckaCharger);

                        index = 1;
                    } else {
                        ///RECUP ARGENT
                        fichier >> argentRecup;

                        ///RECUP CARTES
                        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                            fichier >> nombreRecup;
                        }

                        ///RECUP STOP
                        fichier >> stopRecup;
                    }
                }
            } else {
                std::cout << "Erreur ouverture fichier" << std::endl;
            }

            fichier.close();

        } while (index != 1);
    } else {
        std::cout << "Impossible d'ouvrir le fichier en LECTURE" << std::endl;
    }

    return joueurACharger;
}


std::map<int, Joueur> chargementJoueurs(Collections collection)
{
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");
    std::string nomRecup;
    std::string stopRecup;
    std::string arret = ("stop");
    int nombreRecup;
    int argentRecup;
    std::string choixNom;
    std::string finFichier;

    std::map<int, Joueur> joueursACharger;
    int increment = -1;

    std::vector<Deck> deckaCharger(8);

    std::ifstream fichier(fichierDeSauvegarde.c_str(), std::ios::in);
    fichier.open("fichierDeSauvegarde", std::ios::in);

    if (fichier) {

        while (getline(fichier, finFichier))
        {
            ///RECUP NOM
            fichier >> nomRecup;

            increment++;

            ///RECUP ARGENT
            fichier >> argentRecup;

            joueursACharger[increment].setNom(nomRecup);
            joueursACharger[increment].setArgent(argentRecup);

            ///RECUP CARTES
            for (int i = 0; i < NOMBRE_CARTES_DECK; i++)
            {
                fichier >> nombreRecup;
                deckaCharger[increment].setDeck(collection.getCarte()[nombreRecup]);
            }

            joueursACharger[increment].setDeck(deckaCharger[increment]);

            ///RECUP STOP
            fichier >> stopRecup;

        }
        joueursACharger.erase(increment);

    } else {
        std::cout << "Impossible d'ouvrir le fichier en LECTURE" << std::endl;
    }
    fichier.close();

    return joueursACharger;
}