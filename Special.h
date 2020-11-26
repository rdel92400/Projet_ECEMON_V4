#ifndef PROJET_ECEMON_V4_SPECIAL_H
#define PROJET_ECEMON_V4_SPECIAL_H
#include "Carte.h"
#include "Principal.h"



class Special : public Carte{
public:
    Special();
    ~Special();
    void setSpecial(std::string nom,std::string desc,int utilisation, int prix);
    void afficher();
private:


};


#endif //PROJET_ECEMON_V4_SPECIAL_H
