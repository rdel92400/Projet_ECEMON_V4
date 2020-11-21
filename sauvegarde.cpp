//
// Created by Romain on 21/11/2020.
//

#include "sauvegarde.h"


void sauvegardeDeck(Joueur joueurRecu, Collections collection) {
    std::map<int, std::string> indiceCarte;

    std::string const fichierDeSauvegarde("Projet_ECEMON_V4//fichierDeSauvegarde");


    for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
        indiceCarte[i] = collection.getCarte()[i]->getNom();
    }

    std::ofstream fichier(fichierDeSauvegarde.c_str(), std::ios::app);
    fichier.open("fichierDeSauvegarde", std::ios::out);

    if (fichier) {
        fichier << joueurRecu.getNom() << std::endl;
        fichier << joueurRecu.getArgent() << std::endl;

        for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
            for (int i = 0; i < NOMBRE_CARTES_DECK; i++) {
                for (const auto &elem : indiceCarte) {
                    if (elem.second == joueurRecu.getDeck().getDeck()[i]->getNom()) {
                        fichier << elem.first << std::endl;
                    }
                }
            }

            fichier.close();
        }
    } else {
        std::cout << "Impossible d'ouvrir le fichier en ecriture" << std::endl;
    }

}


