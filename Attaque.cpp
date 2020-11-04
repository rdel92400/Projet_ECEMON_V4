#include "Principal.h"

class Attaque
{
public:
    Attaque();
    Attaque(std::string nom, std::string energieDem, std::string description, int degats);
    ~Attaque();
    void attaquer();
    std::string getNom() const;
    std::string getEnergie() const;
    std::string getDesc() const;
    int getDegat() const;

protected:
    std::string m_nom;
    std::string m_energieDem;
    std::string m_description;
    int m_degats;
};