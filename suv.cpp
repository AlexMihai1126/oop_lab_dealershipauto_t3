//
// Created by Alex on 07/12/2022.
//
#include "suv.hpp"

#include <utility>

Suv::Suv() : Masina() {
    garda_la_sol = 0;
    capacitate_tractare = 0;
}

Suv::Suv(std::string marca, std::string model, std::string vin, int an_fab, int luna_fab, float garda_sol, int cap_t)
        : Masina(std::move(marca), std::move(model), std::move(vin), an_fab, luna_fab), garda_la_sol(garda_sol),
          capacitate_tractare(cap_t) {
//constr de init cu lista de initializare
}

float Suv::getGardaLaSol() const {
    return garda_la_sol;
}

int Suv::getCapacitateTractare() const {
    return capacitate_tractare;
}

Suv::Suv(const Suv &copy) : Masina(copy) {
    garda_la_sol = copy.garda_la_sol;
    capacitate_tractare = copy.capacitate_tractare;
}

void Suv::setGardaSol(float g) {
    garda_la_sol = g;
}

void Suv::setCapT(int c) {
    capacitate_tractare = c;
}


[[maybe_unused]] void
Suv::setSuv(std::string marca_, std::string model_, std::string vin_, int an_fab_, int luna_fab_, float garda_sol_,
            int cap_t_) {
    setID(IDGen::getIDGen().getID());
    setMarca(std::move(marca_));
    setModel(std::move(model_));
    setVin(std::move(vin_));
    setAnFab(an_fab_);
    setLunaFab(luna_fab_);
    setGardaSol(garda_sol_);
    setCapT(cap_t_);
}

void Suv::afisareMasina() const {
    Masina::afisareMasina();
    std::cout << "Garda la sol: " << getGardaLaSol() << " ";
    std::cout << "Capacitate tractare: " << getCapacitateTractare() << std::endl;
}

void Suv::print(std::ostream &os) const {
    os << "SUV:" << std::endl;
    os << "ID: " << getIDMasina() << std::endl;
    os << "Marca: " << getMarca() << std::endl;
    os << "Model: " << getModel() << std::endl;
    os << "Vin: " << getVin() << std::endl;
    os << "An fabricatie: " << getAnFab() << std::endl;
    os << "Luna fabricatie: " << getLunaFab() << std::endl;
    os << "Garda la sol: " << getGardaLaSol() << std::endl;
    os << "Capacitate maxima de tractare: " << getCapacitateTractare() << std::endl;
}

void Suv::read(std::istream &is) {
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
    std::cout << "Garda la sol: ";
    is.sync();
    is >> garda_la_sol;
    std::cout << "Capacitate de tractare: ";
    is.sync();
    is >> capacitate_tractare;
}

Suv &Suv::operator=(const Suv &rhs) {
    if(this !=&rhs){
        Masina::operator=(rhs);
        garda_la_sol=rhs.garda_la_sol;
        capacitate_tractare=rhs.capacitate_tractare;
    }
    return *this;
}