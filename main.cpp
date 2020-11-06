#include <iostream>
#include "Principal.h"
#include "Carte.h"
#include "Creature.h"
#include "Attaque.h"
#include "Collections.h"


int main() {
    Collections Collection;
    Collection.chargerCollectionEntiere();
    Collection.getCreature()[0].afficher();
    return 0;
}

