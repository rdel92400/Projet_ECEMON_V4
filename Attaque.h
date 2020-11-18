#ifndef PROJET_ECEMON_V4_ATTAQUE_H
#define PROJET_ECEMON_V4_ATTAQUE_H


#include "Principal.h"

class Attaque
{
public:
    Attaque();
    Attaque(std::string nom, std::string energieDem, int energieLV, std::string description, int degats);
    ~Attaque();

    void attaquer();

    std::string getNom() const;
    std::string getEnergie() const;
    std::string getDesc() const;
    int getDegat() const;
    int getEnergieLV() const;
    void setAttaque(std::string _nom, std::string _energieDem, int _energieLV, std::string _description, int _degats);

protected:
    std::string m_nom;
    std::string m_energieDem;
    int m_lvEnergie;
    std::string m_description;
    int m_degats;
};


#endif //PROJET_ECEMON_V4_ATTAQUE_H
