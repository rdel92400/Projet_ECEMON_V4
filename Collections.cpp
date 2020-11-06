//
// Created by Romain on 04/11/2020.
//

#include "Collections.h"

Collections::Collections() {
}

Collections::~Collections() {
}

void Collections::chargerCollectionEntiere() {
    ///Ini des attaques

    ///Attaques basiques
    Attaque Boule_de_Feu("Boule de feu", "KK", "Tire une boule de feu", 30);
    Attaque Boule_de_Glace("Boule de glace", "HH", "Tire une boule de glace", 30);

    ///Attaques de DBZ
    Attaque Kamehameha("Kamehameha","KKK","Une attaque surpuissante !",250);
    Attaque coupMeteor ("Coup Meteor","KKP","Une attque physique tres puissante", 200);
///Ini des creatures

///Exemple
    Creature Demon(100);
    Demon.setCreature("DEMON", "C'est un demon basique", false, Boule_de_Feu, Boule_de_Glace);

    ///Creatures DBZ
    Creature Goku(1000);
    Goku.setCreature("Goku","C'est le personnage principal de Dragon Ball Z !",false,Kamehameha,coupMeteor);

    ///Creatures One Piece

    ///Creatures Naruto

///Chargement des cartes dans le vecteur de cartes
    setCreature(Demon);
    setCreature(Goku);
}

void Collections::setCreature(Creature creatureRecue) {
    m_collection.push_back(creatureRecue);
}





