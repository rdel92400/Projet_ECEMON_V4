#include "Energie.h"

Energie::Energie()
{
    //ctor
}

Energie::~Energie()
{
    //dtor
}

Energie::Energie(int lv, std::string type) : m_Lv(lv), m_type(type){

}

void Energie::setEnergie(std::string nom, std::string desc, int utilisation,int prix) {
    setNom(nom);
    setDesc(desc);
    set_EstUtilise(utilisation);
    setPrix(prix);
}

int Energie::getLV() const {
    return m_Lv;
}

std::string Energie::getType() {
    return m_type;
}
