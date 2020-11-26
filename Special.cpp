#include "Special.h"

Special::Special() {

}

Special::~Special() {

}

void Special::setSpecial(std::string nom, std::string desc, int utilisation, int prix) {
    setNom(nom);
    setDesc(desc);
    set_EstUtilise(utilisation);
    setPrix(prix);
}

void Special::afficher() {
    std::cout << "La carte s'appelle : " << getNom() << std::endl;
    std::cout << "Description : " << getDesc() << std::endl;
}
