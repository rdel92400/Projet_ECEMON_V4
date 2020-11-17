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

void Energie::setEnergie(std::string nom, std::string desc, int utilisation) {
    setNom(nom);
    setDesc(desc);
    set_EstUtilise(utilisation);
}
