//
// Created by Romain on 21/11/2020.
//

#include "sauvegarde.h"


void sauvegardeDeJoueur(Joueur joueurRecu, Collections collection) {
    std::map<int, std::string> indiceCarte;

    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");


    for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
        indiceCarte[i] = collection.getCarte()[i]->getNom();
    }

    std::ofstream fichier(fichierDeSauvegarde.c_str(), std::ios::app);
    fichier.open("fichierDeSauvegarde", std::ios::app);

    if (fichier) {
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
/*
Joueur chargementJoueur(Collections collection) {
    Joueur joueurACharger;
    std::string nomRecup;
    Deck deckaCharger;
    int nombreRecup;
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");

    std::ifstream fichier(fichierDeSauvegarde.c_str(), std::ios::in);
    fichier.open("fichierDeSauvegarde", std::ios::in);

    if (fichier) {

        getline(fichier, nomRecup);
        joueurACharger.setNom(nomRecup);

        fichier >> nombreRecup;
        joueurACharger.setArgent(nombreRecup);

        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
            fichier >> nombreRecup;
            deckaCharger.setDeck(collection.getCarte()[nombreRecup]);
        }

    } else {
        std::cout << "Impossible d'ouvrir le fichier en LECTURE" << std::endl;

    }

    joueurACharger.setDeck(deckaCharger);

    fichier.close();
    return joueurACharger;
}
*/

Joueur chargementJoueurAuChoix(Collections collection) {
    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");
    std::string nomRecup;
    std::string arret = ("stop");
    int nombreRecup;
    std::string choixNom;
    std::string finFichier;

    Joueur joueurACharger;
    Deck deckaCharger;

    std::ifstream fichier(fichierDeSauvegarde.c_str(), std::ios::in);
    fichier.open("fichierDeSauvegarde", std::ios::in);

    if (fichier) {
        while (getline(fichier, finFichier)) {

            ///Ici boucle sur tous les noms

            getline(fichier, nomRecup);
            ///Recevoir dans variable choix qui est le nom du mec choisi
            ///Fin de la valeur du nom
            fichier >> nombreRecup;

            for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                fichier >> nombreRecup;
            }
            getline(fichier, nomRecup);
        }

        ///Lecture du bon nom :

        while (getline(fichier, finFichier), finFichier != choixNom) {

            ///Ici boucle sur tous les noms

            getline(fichier, nomRecup);
            ///Recevoir dans variable choix qui est le nom du mec choisi
            ///Fin de la valeur du nom
            fichier >> nombreRecup;

            for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                fichier >> nombreRecup;
            }
            getline(fichier, nomRecup);

            ///Si le nom a été trouvé
            if (finFichier == choixNom) {
                getline(fichier, nomRecup);
                joueurACharger.setNom(nomRecup);

                fichier >> nombreRecup;
                joueurACharger.setArgent(nombreRecup);

                for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                    fichier >> nombreRecup;
                    deckaCharger.setDeck(collection.getCarte()[nombreRecup]);
                }
            }

        }


    } else {
        std::cout << "Impossible d'ouvrir le fichier en LECTURE" << std::endl;
    }

    joueurACharger.setDeck(deckaCharger);
    fichier.close();
    return joueurACharger;

}
