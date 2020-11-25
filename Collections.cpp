//
// Created by Romain,Charles et pas Maxence on 04/11/2020.
//

#include "Collections.h"

Collections::Collections() {}

Collections::~Collections() {}

void Collections::chargerCollectionEntiere() {
///Ini des attaques

    ///Attaques de DBZ
    Attaque Kamehameha("Kamehameha", "K",2, "Rayon d'énergie surpuissante !", 250);
    Attaque coupMeteor("Coup Meteor", "K",2, "Attaque physique tres puissante", 200);

    Attaque canonGarric("Canon Garric", "K",2, "Rayon d'énergie surpuissant !", 250);
    Attaque coupFinal("Coup Final", "K",2, "Attaque physique tres puissante", 200);

    Attaque kienzan("Kienzan", "K",2, "Disque d'énergie tranchant", 200);
    Attaque enchainementDevas("Enchainement devastateur", "K",2, "Krilin roue de coup son adversaire", 150);

    Attaque rayonMortel("Rayon Mortel", "K",2, "Rayon capable de tout traverser", 250);
    Attaque attaqueSR("Attaque sans rancoeur", "K",2, "Explosion de colere et dechainement", 200);

    Attaque makankosappo("Makankosappo", "K",2, "Rayon surpuissant", 250);
    Attaque regeneratiob("Regeneration", "K",2, "Regeneration des points de vie", 0);

    //Attaque attaqueSui("Attaque suicide", "K",3, "Le saibaman s'accroche à son adversaire et explose", 400);

    ///Attaques One Piece
    Attaque elephantGun("ElephantGun", "H",2, "Une attaque surpuissante !", 250);
    Attaque jetPunch("JetPunch", "H",2, "Coup de point en gear Second", 200);

    Attaque santoryu("Santoryu", "H",2, "Zoro attaque utilisant ses 3 sabres", 200);
    Attaque enmaSlash("Enma Slash", "H",1, "Attaque avec l'epee legendaire Enma", 150);

    Attaque jarret("Jarret", "H",2, "Coup devastateur dans la cuisse", 200);
    Attaque troisiemeHache("Troisieme Hache", "H",1, "Rafale de coups de pied au visage", 150);

    Attaque tournesolStar("Tournesol Star","H",2, "Tire 5 balles explosives puissantes",175);
    Attaque billeEnflamee("Bille enflamee","H",1, "Tire une bille qui brule la cible",100);

    Attaque hornPoint("Horn Point","H",1, "Des cornes poussent sur sa tete",100);
    Attaque soin("Soin","H",1, "Permet de regagner de la vie",-150);

    ///Attaques Naruto
    Attaque rasengan("Rasengan","C",2,"Una attaque vent très puissante",250);
    Attaque clonage("Clonage","C",1, "Apparition de 1000 clones de Naruto",200);

    Attaque milleOiseaux("Mille oiseaux","C",1, "Una attaque éléctrique très puissante",250);
    Attaque bouleDeFeuSupreme("Boule de feu supreme","C",1, "Sasuke crache une boule de feu",200);

    Attaque astreDivin("Astre Divin","C",2, "Apparition d'un astre geant",200);
    Attaque attractionCeleste("Attraction Celeste","C",1, "Attire ou repousse l'adversaire",150);

    Attaque manipulationDesOmbres("Manipulation Des Ombres","C",1, "Manipulation de son ombre",175);
    Attaque etreinteMortelle("Etreinte Mortelle","C",1, "Immobilisation de l'adversaire",175);

    Attaque forceAmelioree("Force amelioree","C",1, "Coup de poing devastateur",150);

    ///Attaque HxH

    Attaque pfc("Pierre Ciseaux Papier", "N",1,  "Concentration et explosion du nen", 150);
    Attaque transfoUlt("Transformation Ultime", "N",3, "Explosion de colere et dechainement", 300);

    Attaque griffes("Griffes", "N",1,  "Kirua griffes son enemi", 150);
    Attaque serpentEv("Le serpent s'eveillant", "N",2, "Augmantation de vitesse et tranchant", 250);

    Attaque jeuDeCarte("Jeu de carte", "N",1, "Utilisation de magie avec des cartes", 150);
    Attaque pansyGum("Pansy Gum", "N",2, "Utilisation de gum", 250);

    Attaque chaineMat("Chaine materialise", "N",1, "Materialisation d'une chaine", 150);
    Attaque Emperor("Emperor Time", "N",3, "Specialisation : Surpuissance", 300);

    Attaque poingUtl("Poing ultime", "N",1, "Coup de poing surpuissant", 200);
    Attaque Tech1000("Technique des 1000 paumes", "N",3, "Invocation de Hyakushiki Kannon", 300);

///Ini des creatures

    ///Creatures DBZ
    Carte* goku(0);
    goku = new Creature(1000);
    goku->setCreature("Goku", "C'est le personnage principal de Dragon Ball Z !", CREATURE, Kamehameha, coupMeteor);

    Carte* vegeta(0);
    vegeta = new Creature(900);
    vegeta->setCreature("Vegeta", "C'est le rival de Son Goku et le prince des saiyans", CREATURE, canonGarric, coupFinal);

    Carte* krilin(0);
    krilin = new Creature(700);
    krilin->setCreature("Krilin", "Ami de Son Goku depuis l'enfance", CREATURE, kienzan, enchainementDevas);

    Carte* freezer(0);
    freezer = new Creature(1000);
    freezer->setCreature("Freezer", "Ennemi principal de Son Goku, il hait les saiyans", CREATURE, rayonMortel, attaqueSR);

    Carte* piccolo(0);
    piccolo = new Creature(500);
    piccolo->setCreature("Piccolo", "Extraterrestre très puissant qui peut se regénérer", CREATURE, makankosappo, regeneratiob);

    ///Creatures One Piece
    Carte* luffy(0);
    luffy = new Creature(1000);
    luffy->setCreature("Monkey D Luffy", "Le futur roi des pirates !", CREATURE, elephantGun, jetPunch);

    Carte* zoro(0);
    zoro = new Creature(750);
    zoro->setCreature("Roronoa zoro", "meilleur épéiste a bord du Sunny et bras droit de Luffy !", CREATURE, santoryu,enmaSlash);

    Carte* sanji(0);
    sanji = new Creature(750);
    sanji->setCreature("Sanji", "Cuisinier a bord du sunny et un combatant redoutable", CREATURE, jarret, troisiemeHache);

    Carte* usopp(0);
    usopp = new Creature(300);
    usopp->setCreature("Usopp", "Le sniper de l'equipage", CREATURE,tournesolStar,billeEnflamee);

    Carte* chopper(0);
    chopper = new Creature(200);
    chopper->setCreature("Chopper","C'est le medecin de l'equipage. C'est un Cerf ayant mangé un fruit du demon et qui a donc acquis la capacite de la parole",CREATURE,hornPoint,soin);

    ///Creatures Naruto
    Carte* naruto(0);
    naruto = new Creature(1000);
    naruto->setCreature("Uzumaki Naruto","C'est le personnage principal du manga Naruto",CREATURE,rasengan,clonage);

    Carte* sasuke(0);
    sasuke = new Creature(1000);
    sasuke->setCreature("Uchiwa Sasuke","Le plus grand ami et rival de Naruto",CREATURE,milleOiseaux,bouleDeFeuSupreme);

    Carte* pain(0);
    pain = new Creature(750);
    pain->setCreature("Pain","Chef de l'Akatsuki, la plus grande organisation criminelle",CREATURE,astreDivin,attractionCeleste);

    Carte* shikamaru(0);
    shikamaru = new Creature(750);
    shikamaru->setCreature("Nara Shikamaru","16ème chef du clan Nara", CREATURE,manipulationDesOmbres,etreinteMortelle);

    Carte* sakura(0);
    sakura = new Creature(300);
    sakura->setCreature("Haruno Sakura","Grande ninja medecin",CREATURE,forceAmelioree,soin);

    ///Carte HxH
    Carte* gon(0);
    gon = new Creature(800);
    gon->setCreature("Gon Freecss", "Protagoniste de Hunter X Hunter et future Hunter", CREATURE, pfc, transfoUlt);

    Carte* kirua(0);
    kirua = new Creature(800);
    kirua->setCreature("Kirua Zoldik", "Meilleur ami de Gon et très celebre assassin", CREATURE, griffes, serpentEv);

    Carte* hisoka(0);
    hisoka = new Creature(900);
    hisoka->setCreature("Hisoka Morow", "Hunter profesionnel qui fait parti de la brigade fantome et qui est le principal enemi de Gon", CREATURE, jeuDeCarte, pansyGum);

    Carte* kurapika(0);
    kurapika = new Creature(750);
    kurapika->setCreature("Kurapika", "Membre du clan Kuruta, il possede les yeux rouges et veut exterminer la brigade fantome", CREATURE, chaineMat, Emperor);

    Carte* netero(0);
    netero = new Creature(1000);
    netero->setCreature("Isaac Netero", "President de l'association hunter et surrement le plus fort d'entre eux", CREATURE, poingUtl, Tech1000);


    ///Carte Energie

    Carte* ki1(0);
    ki1 = new Energie(1, "K");
    ki1->setEnergie("Ki Lv 1", "Faible carte énergie de Ki", ENERGIE);

    Carte* ki2(0);
    ki2 = new Energie(2, "K");
    ki2->setEnergie("Ki Lv 2", "Carte intermediare d'énergie de Ki", ENERGIE);

    Carte* ki3(0);
    ki3 = new Energie(3, "K");
    ki3->setEnergie("Ki Lv 3", "Puissante carte énergie de Ki", ENERGIE);

    Carte* haki1(0);
    haki1 = new Energie(1, "H");
    haki1->setEnergie("Haki Lv 1", "Faible carte énergie de Haki", ENERGIE);

    Carte* haki2(0);
    haki2 = new Energie(2, "H");
    haki2->setEnergie("Haki Lv 2", "Carte intermediare d'énergie de Haki", ENERGIE);

    Carte* haki3(0);
    haki3 = new Energie(3, "H");
    haki3->setEnergie("Haki Lv 3", "Puissante carte énergie de Haki", ENERGIE);

    Carte* chakra1(0);
    chakra1 = new Energie(1, "C");
    chakra1->setEnergie("Chakra Lv 1", "Faible carte énergie de Chakra", ENERGIE);

    Carte* chakra2(0);
    chakra2 = new Energie(2, "C");
    chakra2->setEnergie("Chakra Lv 2", "Carte intermediaire d'énergie de Chakra", ENERGIE);

    Carte* chakra3(0);
    chakra3 = new Energie(3, "C");
    chakra3->setEnergie("Chakra Lv 3", "Puissante carte énergie de Chakra", ENERGIE);

    Carte* nen1(0);
    nen1 = new Energie(1, "N");
    nen1->setEnergie("Nen Lv 1", "faible carte énergie de nen", ENERGIE);

    Carte* nen2(0);
    nen2 = new Energie(2, "N");
    nen2->setEnergie("Nen Lv 2", "Carte intermediaire d'énergie de nen", ENERGIE);

    Carte* nen3(0);
    nen3 = new Energie(3, "N");
    nen3->setEnergie("Nen Lv 3", "Puissante carte énergie de Nen", ENERGIE);

///Chargement des cartes dans le vecteur de cartes

    ///Pour les cartes Creatures de DBZ
    setCarte(goku);
    setCarte(vegeta);
    setCarte(krilin);
    setCarte(freezer);
    setCarte(piccolo);

    ///Pour les carte Creatures de One Piece
    setCarte(luffy);
    setCarte(zoro);
    setCarte(sanji);
    setCarte(usopp);
    setCarte(chopper);

    ///Pour les cartes Creatures de Naruto
    setCarte(naruto);
    setCarte(sasuke);
    setCarte(pain);
    setCarte(shikamaru);
    setCarte(sakura);

    ///Pour les cartes Creatures de HxH
    setCarte(gon);
    setCarte(kirua);
    setCarte(kurapika);
    setCarte(hisoka);
    setCarte(netero);

    ///Pour les cartes Energies de DBZ
    setCarte(ki1);
    setCarte(ki2);
    setCarte(ki3);

    ///Pour les cartes Energies de One Piece
    setCarte(haki1);
    setCarte(haki2);
    setCarte(haki3);

    ///Pour les cartes Energies de Naruto
    setCarte(chakra1);
    setCarte(chakra2);
    setCarte(chakra3);

    ///Pour les cartes Energies de HxH
    setCarte(nen1);
    setCarte(nen2);
    setCarte(nen3);


}


void Collections::setCarte(Carte *carteRecue) {
    m_collectionCarte.push_back(carteRecue);
}

std::vector<Carte *> Collections::getCarte() {
    return m_collectionCarte;
}



/*
void Collections::chargementCreatures()
{
    std::ifstream monFlux(R"(C:\Users\Charles\OneDrive - Groupe INSEEC (POCE)\ECE\ING- 2\Informatique\Projets\Projet_ECEMON_V4\Fichiers\CollectionCreatures.txt)");

    std::string tempFichier;
    std::string tempNom;
    std::string tempDescription;
    int tempPV;
    std::string tempNomAttaque1;
    std::string tempDescriptionAttaque1;
    std::string tempCoutAttaque1;
    int tempDegat1;
    std::string tempNomAttaque2;
    std::string tempDescriptionAttaque2;
    std::string tempCoutAttaque2;
    int tempDegat2;

    Creature creatureTemp;
    Attaque attaqueTemp1;
    Attaque attaqueTemp2;

    if(!monFlux)
    {
        std::cout << "Erreur chargemement fichier CollectionsCreatures.txt" << std::endl;
    }
    else
    {
        while (getline(monFlux,tempFichier))
        {
            getline(monFlux,tempNom);
            monFlux >> tempPV;
            getline(monFlux,tempDescription);

            getline(monFlux,tempNomAttaque1);
            getline(monFlux,tempDescriptionAttaque1);
            monFlux >> tempCoutAttaque1;
            monFlux >> tempDegat1;

            getline(monFlux,tempNomAttaque2);
            getline(monFlux,tempDescriptionAttaque2);
            monFlux >> tempCoutAttaque2;
            monFlux >> tempDegat2;

            attaqueTemp1.setAttaque(tempNomAttaque1,tempCoutAttaque1,tempDescriptionAttaque1,tempDegat1);
            attaqueTemp2.setAttaque(tempNomAttaque2,tempCoutAttaque2,tempDescriptionAttaque2,tempDegat2);

            creatureTemp.setCreature(tempNom,tempDescription,tempPV,false,attaqueTemp1,attaqueTemp2); //(Il faut rajouter la vie dans le setter)

            m_collectionCreatures.push_back(creatureTemp);
        }
    }
}
*/