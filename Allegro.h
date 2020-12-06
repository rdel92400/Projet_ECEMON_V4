//
// Created by charles on 25/11/2020.
//

#ifndef PROJET_ECEMON_V4_ALLEGRO_H
#define PROJET_ECEMON_V4_ALLEGRO_H

#include "Principal.h"
#include "Plateau.h"
#include "sauvegarde.h"
#include "argent.h"


void iniTabCollectionCreature(int miseEnPage[4][5][3]);
void iniTabCollectionEnergie(int miseEnPage[4][4][3]);
void iniTabCollectionSpeciale(int miseEnPage[2][3][3]);
void iniTabCollectionDeck(int miseEnPage[3][5][3]);

void erreur(const char* titre, const char* txt);
ALLEGRO_BITMAP* chargement(const std::string& nomImage);
ALLEGRO_FONT* chargementPolice(const std::string& nomImage,int size);
std::map<std::string,ALLEGRO_FONT*> chargementToutesLesPolices();
std::map<std::string,ALLEGRO_BITMAP*> chargementBitmaps();
void destructionBitmaps(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void regles(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, std::map<std::string,ALLEGRO_SAMPLE*> mapSample);

std::string iniNom(ALLEGRO_BITMAP* fond, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
std::string iniNomChargementJoueur(ALLEGRO_BITMAP* fond, int posX, int posY, std::map<int,std::string> tabNoms, std::map<std::string,ALLEGRO_FONT*> myMapPolice);

///PARTIE
void affichageNomPvEnergie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageCarteActive(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageCarteActiveEnnemie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageRemiseSousPioche(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageCarteAjoutee(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichagePasDeCarteActive(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichagePasDeCarteActiveEnnemie(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichagePasAssezEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageAttaqueReussie(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageJoueurSuivant(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageJoueurProtege(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageCarteEnjeu(Plateau p, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageSuperEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageProtection(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int affichageBouleDeFeu(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageVisionUltime(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void affichageVictoire(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int affichageMainMagique(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int affichageNecro(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);

void actionPioche(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int choixPioche1(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int choixPioche2(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int choixSiAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
int choixAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);
void ajoutCarteEnjeu(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap, std::map<std::string,ALLEGRO_FONT*> myMapPolice);


#endif //PROJET_ECEMON_V4_ALLEGRO_H