//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"
#include <iostream>
#include <utility>
#include "exceptions.hpp"

masina::masina() {
    this->marca = " ";
    this->model = " ";
    this->vin = " ";
    this->an_fab = 2000;
    this->luna_fab = 1;
}

masina::masina(std::string marca, std::string model, std::string vin, int an_fab = 2000, int luna_fab = 01) {
    if (an_fab < 2000) throw YearOutOfRange();
    if (luna_fab < 1 || luna_fab > 12) throw MonthOutOfRange();
    this->marca = std::move(marca);
    this->model = std::move(model);
    this->vin = std::move(vin);
    this->an_fab = an_fab;
    this->luna_fab = luna_fab;
}


masina::masina(const masina &copy) {
    this->marca = copy.marca;
    this->model = copy.model;
    this->vin = copy.vin;
    this->an_fab = copy.an_fab;
    this->luna_fab = copy.luna_fab;
}

[[maybe_unused]]void masina::setMarca(std::string marca_) {
    this->marca = std::move(marca_);
}

[[maybe_unused]]void masina::setModel(std::string model_) {
    this->model = std::move(model_);
}

[[maybe_unused]]void masina::setVin(std::string vin_) {
    this->vin = std::move(vin_);
}

[[maybe_unused]]void masina::setAnFab(int an_fab_) {
    this->an_fab = an_fab_;
}

[[maybe_unused]]void masina::setLunaFab(int luna_fab_) {
    this->luna_fab = luna_fab_;
}

std::string masina::getModel() const {
    return model;
}

std::string masina::getMarca() const {
    return marca;
}

std::string masina::getVin() const {
    return vin;
}

int masina::getAnFab() const {
    return an_fab;
}

int masina::getLunaFab() const {
    return luna_fab;
}

void masina::afisareMasina() const {
    std::cout << "Marca: " << getMarca() << " ";
    std::cout << "Model: " << getModel() << " ";
    std::cout << "VIN: " << getVin() << std::endl;
    std::cout << "Luna fabricatie: " << getLunaFab() << " ";
    std::cout << "An fabricatie: " << getAnFab() << std::endl;
}

masina &masina::operator=(const masina &rhs) {
    if(this !=&rhs){
        model=rhs.model;
        marca=rhs.marca;
        vin=rhs.vin;
        an_fab=rhs.an_fab;
        luna_fab=rhs.luna_fab;
    }
    return *this;
}

masina::~masina() = default;