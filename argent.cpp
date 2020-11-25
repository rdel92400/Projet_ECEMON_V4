//
// Created by Romain on 25/11/2020.
//

#include "argent.h"

void victoireArgent(Joueur joueurRecu) {
    int nouvelArgent;
    nouvelArgent = joueurRecu.getArgent() + ARGENT_VICTOIRE;
    joueurRecu.setArgent(nouvelArgent);
}

int achat(Joueur joueurRecu, Carte carteRecue) {
    int nouvelArgent;

    if ((joueurRecu.getArgent() - carteRecue.getPrix()) < 0) {
        ///Return -1 car il n'a pas pu acheter
        return -1;
    } else {
        nouvelArgent = joueurRecu.getArgent() - carteRecue.getPrix();
        joueurRecu.setArgent(nouvelArgent);
        ///Return 1 car il a pu acheter
        return 1;
    }
}

