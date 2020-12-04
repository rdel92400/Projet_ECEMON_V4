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
std::map<std::string,ALLEGRO_BITMAP*> chargementBitmaps();
void destructionBitmaps(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void regles(std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);

std::string iniNom(ALLEGRO_BITMAP* fond);
std::string iniNomChargementJoueur(ALLEGRO_BITMAP* fond, int posX, int posY, std::map<int,std::string> tabNoms);

///PARTIE
void affichageNomPvEnergie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageCarteActive(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageCarteActiveEnnemie(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageRemiseSousPioche(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageCarteAjoutee(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichagePasDeCarteActive(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichagePasDeCarteActiveEnnemie(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichagePasAssezEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageAttaqueReussie(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageJoueurSuivant(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageJoueurProtege(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageCarteEnjeu(Plateau p);
void affichageSuperEnergie(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageProtection(std::map<std::string,ALLEGRO_BITMAP*> mymap);
int affichageBouleDeFeu(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageVisionUltime(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
void affichageVictoire(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mymap);

void actionPioche(Plateau p, std::map<std::string,ALLEGRO_BITMAP*> mymap);
int choixPioche1(std::map<std::string,ALLEGRO_BITMAP*> mymap);
int choixPioche2(std::map<std::string,ALLEGRO_BITMAP*> mymap);
int choixSiAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap);
int choixAttaque(std::map<std::string,ALLEGRO_BITMAP*> mymap);
void ajoutCarteEnjeu(Plateau gagnant, Plateau perdant, std::map<std::string,ALLEGRO_BITMAP*> mapBitmap);


#endif //PROJET_ECEMON_V4_ALLEGRO_H