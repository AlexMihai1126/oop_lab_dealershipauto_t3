//
// Created by Alex on 07/12/2022.
//
#include "sedan.hpp"

#include <utility>

int Sedan::getClasa() const {
    return clasa;
}

Sedan::Sedan() : Masina() {
    clasa = 0;
}

Sedan::Sedan(std::string marca, std::string model, std::string vin, int an_fab, int luna_fab, int clasa_)
        : Masina(std::move(marca), std::move(model), std::move(vin), an_fab, luna_fab), clasa(clasa_) {
//constr de init cu lista de initializare
}

Sedan::Sedan(const Sedan &copy) : Masina(copy) {
    clasa = copy.clasa;
}

[[maybe_unused]] void
Sedan::setSedan(std::string marca_, std::string model_, std::string vin_, int an_fab_, int luna_fab_,
                int clasa_) {
    setID(IDGen::getIDGen().getID());
    setMarca(std::move(marca_));
    setModel(std::move(model_));
    setVin(std::move(vin_));
    setAnFab(an_fab_);
    setLunaFab(luna_fab_);
    setClasa(clasa_);
}

void Sedan::afisareMasina() const {
    Masina::afisareMasina();
    std::cout << "Clasa: " << getClasa() << std::endl;
}

void Sedan::print(std::ostream &os) const {
    os << "Sedan:" << std::endl;
    os << "ID: " << getIDMasina() << std::endl;
    os << "Marca: " << getMarca() << std::endl;
    os << "Model: " << getModel() << std::endl;
    os << "Vin: " << getVin() << std::endl;
    os << "An fabricatie: " << getAnFab() << std::endl;
    os << "Luna fabricatie: " << getLunaFab() << std::endl;
    if (getClasa() == 0) os << "Clasa: Sedan" << std::endl;
    if (getClasa() == 1) os << "Clasa: compact" << std::endl;
    if (getClasa() == 2) os << "Clasa: executive" << std::endl;
    if (getClasa() == 3) os << "Clasa: luxury" << std::endl;
}

void Sedan::read(std::istream &is) {
    std::string marca_;
    std::string model_;
    std::string vin_;
    int an_fab_;
    int luna_fab_;
    std::cout << "Marca: ";
    std::cin.sync();
    std::getline(std::cin, marca_);
    std::cout << "Model: ";
    std::cin.sync();
    std::getline(std::cin, model_);
    std::cout << "Vin: ";
    std::cin.sync();
    std::getline(std::cin, vin_);
    std::cout << "An de fabricatie: ";
    std::cin.sync();
    std::cin >> an_fab_;
    std::cout << "Luna de fabricatie: ";
    std::cin.sync();
    std::cin >> luna_fab_;
    Masina::setMarca(marca_);
    Masina::setModel(model_);
    Masina::setVin(vin_);
    Masina::setAnFab(an_fab_);
    Masina::setLunaFab(luna_fab_);
    std::cout << "Clasa: 1-compact, 2-luxury sau 3-executive: ";
    is.sync();
    is >> clasa;
}

void Sedan::setClasa(int cls) {
    clasa = cls;
}

Sedan &Sedan::operator=(const Sedan &rhs) {
    if(this !=&rhs){
        Masina::operator=(rhs);
        clasa=rhs.clasa;
    }
    return *this;
}
