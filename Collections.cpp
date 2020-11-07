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
    Attaque Kamehameha("Kamehameha", "KKK", "Une attaque surpuissante !", 250);
    Attaque coupMeteor("Coup Meteor", "KKP", "Une attaque physique tres puissante", 200);

    ///Attaques One Piece
    Attaque elephantGun("elephantGun", "KKK", "Une attaque surpuissante !", 250);
    Attaque jetPunch("jetPunch", "KKP", "L'attaque phare de Luffy en gear Second", 200);

    Attaque santoryu("Santoryu", "KK", "Zoro attaque utilisant ses 3 sabres", 200);
    Attaque enmaSlash("Enma Slash", "K", "Zoro attaque avec l'epee legendaire Enma", 150);

    Attaque jarret("Jarret", "KK", "Sanji assene un coup dans la zone haute de la cuisse", 200);
    Attaque troisiemeHache("Troisieme Hache", "K", "Une rafale de coup de pieds donnes au visage", 150);

    Attaque tournesolStar("Tournesol Star","KK","Tire 5 balles explosives en meme temps, l'explosion prend la forme d'une fleur",175);
    Attaque billeEnflamee("Bille enflamee","K","Tire une bille qui brule la cible",100);

    Attaque hornPoint("Horn Point","K","Chopper acquiert des enormes cornes tranchantes qu'il utilise pour attaquer",100);
    Attaque soin("Soin","K","Permet de regagner de la vie",-150);

    ///Attaques Naruto
    Attaque rasengan("Rasengan","CCC","Una attaque de type vent très puissante",250);
    Attaque clonage("Clonage","CC","Technique permettant de faire apparaitre 1000 clones",200);

    Attaque milleOiseaux("Mille oiseaux","CCC","Una attaque de type éléctrique très puissante",250);
    Attaque bouleDeFeuSupreme("Clonage","CC","Une attaque qui invoque une boule de feu géante",200);

    Attaque astreDivin("Astre Divin","CCC","Technique permettant d'enfermer l'ennemi dans un astre",200);
    Attaque attractionCeleste("Attraction Celeste","CC","Technique permettant d'attirer ou de repousser l'adversaire",150);

    Attaque manipulationDesOmbres("Manipulation Des Ombres","CC","Technique permettant de manipuler son ombre",175);
    Attaque etreinteMortelle("Etreinte Mortelle","CC","Immobilisation de l'adversaire grace aux ombres",175);

    Attaque forceAmelioree("Force amelioree","CC","Coup de poing avec une grande force de frappe",150);

///Ini des creatures

    ///Creatures DBZ
    Creature goku(1000);
    goku.setCreature("Goku", "C'est le personnage principal de Dragon Ball Z !", false, Kamehameha, coupMeteor);

    ///Creatures One Piece
    Creature luffy(1000);
    luffy.setCreature("Monkey D Luffy", "Le futur roi des pirates !", false, elephantGun, jetPunch);

    Creature zoro(750);
    zoro.setCreature("Roronoa zoro", "meilleur épéiste a bord du Sunny et bras droit de Luffy ! ", false, santoryu,enmaSlash);

    Creature sanji(750);
    sanji.setCreature("Sanji", "Cuisinier a bord du sunny et un combatant redoutable", false, jarret, troisiemeHache);

    Creature usopp(300);
    usopp.setCreature("Usopp", "Le sniper de l'equipage", false,tournesolStar,billeEnflamee);

    Creature chopper(200);
    chopper.setCreature("Chopper","C'est le medecin de l'equipage. C'est un Cerf ayant mangé un fruit du demon et qui a donc acquis la capacite de la parole",false,hornPoint,soin);

    ///Creatures Naruto
    Creature naruto(1000);
    naruto.setCreature("Uzumaki Naruto","C'est le personnage principal du manga Naruto",false,rasengan,clonage);

    Creature sasuke(1000);
    sasuke.setCreature("Uchiwa Sasuke","Le plus grand ami et rival de Naruto",false,milleOiseaux,bouleDeFeuSupreme);

    Creature pain(750);
    pain.setCreature("Rikudo Pain","Chef de l'Akatsuki, la plus grande organisation criminelle",false,astreDivin,attractionCeleste);

    Creature shikamaru(750);
    shikamaru.setCreature("Nara Shikamaru","16ème chef du clan Nara", false,manipulationDesOmbres,etreinteMortelle);

    Creature sakura(300);
    sakura.setCreature("Haruno Sakura","Grande ninja medecin",false,forceAmelioree,soin);


///Chargement des cartes dans le vecteur de cartes

    ///Pour les cartes de DBZ
    setCreature(goku);

    ///Pour les carte de One Piece
    setCreature(luffy);
    setCreature(zoro);
    setCreature(sanji);
    setCreature(usopp);
    setCreature(chopper);

    ///Pour les cartes de Naruto
    setCreature(naruto);
    setCreature(sasuke);
    setCreature(pain);
    setCreature(shikamaru);
    setCreature(sakura);

}

void Collections::setCreature(Creature creatureRecue) {
    m_collection.push_back(creatureRecue);
}

std::vector<Creature> Collections::getCreature() {
    return m_collection;
}



