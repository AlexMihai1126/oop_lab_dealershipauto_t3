//
// Created by Alex on 06/12/2022.
//
#include "dealership.hpp"

int Dealer::getNrMasini() {
    return nr_masini;
}

void Dealer::adaugaMasina(const std::shared_ptr<Masina> &add) {
    nr_masini++;
    stoc.push_back(add);
}

void Dealer::stergeMasina(const std::string &vin_r) {
    auto it = stoc.begin();
    for (const auto &masina: Dealer::stoc) {
        if (masina->getVin() == vin_r) {
            stoc.erase(it);
            nr_masini--;
            return;
        }
        ++it;
    }
    throw NotFound();
}

std::vector<std::shared_ptr<Masina>> &Dealer::getStoc() {
    return Dealer::stoc;
}

std::shared_ptr<Masina> Dealer::cautaVIN(const std::string &key) {
    for (const auto &masina: Dealer::stoc)
        if (masina->getVin() == key)
            return masina;
    throw NotFound();
}

std::vector<std::shared_ptr<Masina>> Dealer::cautaBrand(const std::string &key) {
    std::vector<std::shared_ptr<Masina>> rezultate;
    for (const auto &masina: Dealer::stoc) {
        if (masina->getMarca() == key) rezultate.push_back(masina);
    }
    if (!rezultate.empty()) return rezultate;
    throw NotFound();
}

std::vector<std::shared_ptr<Suv>> Dealer::cautaSUV() {
    std::vector<std::shared_ptr<Suv>> suvs;

    for (const auto &masina_: Dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Suv)) {
            auto suv_result = std::dynamic_pointer_cast<Suv>(masina_);
            suvs.push_back(suv_result);
        }
    }
    if (!suvs.empty()) return suvs;
    throw NotFound();
}

std::vector<std::shared_ptr<Sedan>> Dealer::cautaSedan() {
    std::vector<std::shared_ptr<Sedan>> sedans;

    for (const auto &masina_: Dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Sedan)) {
            auto sedan_result = std::dynamic_pointer_cast<Sedan>(masina_);
            sedans.push_back(sedan_result);
        }
    }
    if (!sedans.empty()) return sedans;
    throw NotFound();
}

std::vector<std::shared_ptr<Coupe>> Dealer::cautaCoupe() {
    std::vector<std::shared_ptr<Coupe>> coupes;

    for (const auto &masina_: Dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Coupe)) {
            auto coupe_result = std::dynamic_pointer_cast<Coupe>(masina_);
            coupes.push_back(coupe_result);
        }
    }
    if (!coupes.empty()) return coupes;
    throw NotFound();
}


std::vector<std::shared_ptr<Masina>> Dealer::stoc;
int Dealer::nr_masini;