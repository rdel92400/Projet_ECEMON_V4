#include <iostream>
#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"






int main() {
    Collections Collection;

    Attaque Boule_de_Feu("Boule de feu", "KK", "Tire une boule de feu", 30);
    Attaque Boule_de_Glace("Boule de glace", "HH", "Tire une boule de glace", 30);

    Creature Demon(100);
    Demon.setNom("Gerard");
    Demon.setDesc("Pas gentil");
    Demon.set_EstUtilise(false);
    Demon.AssigneAttaque(Boule_de_Feu, Boule_de_Glace);
    Demon.afficher();
    Demon.recevoirDegat(Boule_de_Glace);
    Demon.afficher();

    return 0;
}

