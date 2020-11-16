//
// Created by Romain on 04/11/2020.
//

#include "Collections.h"

Collections::Collections() {}

Collections::~Collections() {}

void Collections::chargerCollectionEntiere() {
///Ini des attaques

    ///Attaques basiques
    Attaque Boule_de_Feu("Boule de feu", "KK", "Tire une boule de feu", 30);
    Attaque Boule_de_Glace("Boule de glace", "HH", "Tire une boule de glace", 30);

    ///Attaques de DBZ
    Attaque Kamehameha("Kamehameha", "KKS", "Une attaque surpuissante !", 250);
    Attaque coupMeteor("Coup Meteor", "KKP", "Une attaque physique tres puissante", 200);

    Attaque canonGarric("Canon Garric", "KKS", "Une attaque qui envoie un rayon d'énergie surpuissant !", 250);
    Attaque coupFinal("Coup Final", "KKP", "Vegeta enchaine son adversaire de coup avant de l'achever avec un coup surpuissant", 200);

    Attaque kienzan("Kienzan", "KKS", "Krilin envoie une disque d'énergie capable de tout trancher", 200);
    Attaque enchainementDevas("Enchainement devastateur", "KKP", "Krilin roue de coup son adversaire", 150);

    Attaque rayonMortel("Rayon Mortel", "KKS", "Freezer tire un rayon capable de tout traverser", 250);
    Attaque attaqueSR("Attaque sans rancoeur", "KKP", "Freezer laisse exploser sa colère et attaque sans relache", 200);

    Attaque makankosappo("Makankosappo", "KKS", "Piccolo charge un rayon surpuissant", 250);
    Attaque regeneratiob("Regeneration", "KK", "Piccolo utilise son sang Nemek pour recuperer des points de vie", 0);

    Attaque attaqueSui("Attaque suicide", "KKS", "Le saibaman s'accroche à son adversaire et explose", 400);

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
    Carte* goku(0);
    goku = new Creature(1000);
    goku->setCreature("Goku", "C'est le personnage principal de Dragon Ball Z !", false, Kamehameha, coupMeteor);

    Carte* vegeta(0);
    vegeta = new Creature(900);
    vegeta->setCreature("Vegeta", "C'est le rival de Son Goku et le prince des saiyans", false, canonGarric, coupFinal);

    Carte* krilin(0);
    krilin = new Creature(700);
    krilin->setCreature("Krilin", "Ami de Son Goku depuis l'enfance", false, kienzan, enchainementDevas);

    Carte* freezer(0);
    freezer = new Creature(1000);
    freezer->setCreature("Freezer", "Enemi principal de Son Goku, il hait les saiyans", false, rayonMortel, attaqueSR);

    Carte* saibaman(0);
    saibaman = new Creature(500);
    saibaman->setCreature("Saibaman", "Petite creature qui attaque en explosant", false, attaqueSui, attaqueSui);

    ///Creatures One Piece
    Carte* luffy(0);
    luffy = new Creature(1000);
    luffy->setCreature("Monkey D Luffy", "Le futur roi des pirates !", false, elephantGun, jetPunch);

    Carte* zoro(0);
    zoro = new Creature(750);
    zoro->setCreature("Roronoa zoro", "meilleur épéiste a bord du Sunny et bras droit de Luffy !", false, santoryu,enmaSlash);

    Carte* sanji(0);
    sanji = new Creature(750);
    sanji->setCreature("Sanji", "Cuisinier a bord du sunny et un combatant redoutable", false, jarret, troisiemeHache);

    Carte* usopp(0);
    usopp = new Creature(300);
    usopp->setCreature("Usopp", "Le sniper de l'equipage", false,tournesolStar,billeEnflamee);

    Carte* chopper(0);
    chopper = new Creature(200);
    chopper->setCreature("Chopper","C'est le medecin de l'equipage. C'est un Cerf ayant mangé un fruit du demon et qui a donc acquis la capacite de la parole",false,hornPoint,soin);

    ///Creatures Naruto
    Carte* naruto(0);
    naruto = new Creature(1000);
    naruto->setCreature("Uzumaki Naruto","C'est le personnage principal du manga Naruto",false,rasengan,clonage);

    Carte* sasuke(0);
    sasuke = new Creature(1000);
    sasuke->setCreature("Uchiwa Sasuke","Le plus grand ami et rival de Naruto",false,milleOiseaux,bouleDeFeuSupreme);

    Carte* pain(0);
    pain = new Creature(750);
    pain->setCreature("Rikudo Pain","Chef de l'Akatsuki, la plus grande organisation criminelle",false,astreDivin,attractionCeleste);

    Carte* shikamaru(0);
    shikamaru = new Creature(750);
    shikamaru->setCreature("Nara Shikamaru","16ème chef du clan Nara", false,manipulationDesOmbres,etreinteMortelle);

    Carte* sakura(0);
    sakura = new Creature(300);
    sakura->setCreature("Haruno Sakura","Grande ninja medecin",false,forceAmelioree,soin);


///Chargement des cartes dans le vecteur de cartes

    ///Pour les cartes de DBZ
    setCarte(goku);
    setCarte(vegeta);
    setCarte(krilin);
    setCarte(freezer);
    setCarte(saibaman);

    ///Pour les carte de One Piece
    setCarte(luffy);
    setCarte(zoro);
    setCarte(sanji);
    setCarte(usopp);
    setCarte(chopper);

    ///Pour les cartes de Naruto
    setCarte(naruto);
    setCarte(sasuke);
    setCarte(pain);
    setCarte(shikamaru);
    setCarte(sakura);

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