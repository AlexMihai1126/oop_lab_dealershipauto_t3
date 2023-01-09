//
// Created by Alex on 07/12/2022.
//
#include "coupe.hpp"
#include <utility>

Coupe::Coupe() : Masina() {
    acc_100 = 0;
    isConvertible = false;
}

Coupe::Coupe(std::string marca, std::string model, std::string vin, int an_fab, int luna_fab, float acc, bool is_c)
        : Masina(std::move(marca), std::move(model), std::move(vin), an_fab, luna_fab), acc_100(acc),
          isConvertible(is_c) {
//constr cu lista de init, apelare constr de baza
}

bool Coupe::getConvertible() const {
    return isConvertible;
}

float Coupe::getAcc100() const {
    return acc_100;
}

[[maybe_unused]] void
Coupe::setCoupe(std::string marca_, std::string model_, std::string vin_, int an_fab_, int luna_fab_, float acc_100_,
                bool is_c_) {
    setID(IDGen::getIDGen().getID());
    setMarca(std::move(marca_));
    setModel(std::move(model_));
    setVin(std::move(vin_));
    setAnFab(an_fab_);
    setLunaFab(luna_fab_);
    setAcc(acc_100_);
    setConv(is_c_);
}

Coupe::Coupe(const Coupe &copy) : Masina(copy) {
    acc_100 = copy.acc_100;
    isConvertible = copy.isConvertible;
    //constr de copiere
}

void Coupe::afisareMasina() const {
    Masina::afisareMasina();
    if (getConvertible() == 1) {
        std::cout << "Convertible" << std::endl;
    } else {
        std::cout << "Not Convertible" << std::endl;
    }
    std::cout << "Acceleratie 0-100: " << getAcc100() << std::endl;
}

void Coupe::print(std::ostream &os) const {
    os << "Coupe:" << std::endl;
    os << "ID: " << getIDMasina() << std::endl;
    os << "Marca: " << getMarca() << std::endl;
    os << "Model: " << getModel() << std::endl;
    os << "Vin: " << getVin() << std::endl;
    os << "An fabricatie: " << getAnFab() << std::endl;
    os << "Luna fabricatie: " << getLunaFab() << std::endl;
    if (getConvertible() == 1) {
        os << "Convertible" << std::endl;
    } else {
        os << "Not Convertible" << std::endl;
    }
    os << "Acceleratie 0-100: " << getAcc100() << std::endl;
}

void Coupe::read(std::istream &is) {
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
    std::cout << "Acceleratie 0-100: ";
    is.sync();
    is >> acc_100;
    std::cout << "Convertible? (true/false): ";
    is.sync();
    is >> isConvertible;
}

void Coupe::setAcc(float acc) {
    acc_100 = acc;
}

void Coupe::setConv(bool cn) {
    isConvertible = cn;
}

Coupe &Coupe::operator=(const Coupe &rhs) {
    if(this !=&rhs){
        Masina::operator=(rhs);
        acc_100=rhs.acc_100;
        isConvertible=rhs.isConvertible;
    }
    return *this;
}