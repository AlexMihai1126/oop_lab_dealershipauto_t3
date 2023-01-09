//
// Created by Alex on 06/12/2022.
//
#include "dealership.hpp"

int dealer::getNrMasini() {
    return nr_masini;
}

void dealer::adaugaMasina(const std::shared_ptr<Masina> &add) {
    nr_masini++;
    stoc.push_back(add);
}

void dealer::stergeMasina(const std::string &vin_r) {
    auto it = stoc.begin();
    for (const auto &masina: dealer::stoc) {
        if (masina->getVin() == vin_r) {
            stoc.erase(it);
            nr_masini--;
            return;
        }
        ++it;
    }
    throw NotFound();
}

std::vector<std::shared_ptr<Masina>> &dealer::getStoc() {
    return dealer::stoc;
}

std::shared_ptr<Masina> dealer::cautaVIN(const std::string &key) {
    for (const auto &masina: dealer::stoc)
        if (masina->getVin() == key)
            return masina;
    throw NotFound();
}

std::vector<std::shared_ptr<Masina>> dealer::cautaBrand(const std::string &key) {
    std::vector<std::shared_ptr<Masina>> rezultate;
    for (const auto &masina: dealer::stoc) {
        if (masina->getMarca() == key) rezultate.push_back(masina);
    }
    if (!rezultate.empty()) return rezultate;
    throw NotFound();
}

std::vector<std::shared_ptr<Suv>> dealer::cautaSUV() {
    std::vector<std::shared_ptr<Suv>> suvs;

    for (const auto &masina_: dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Suv)) {
            auto suv_result = std::dynamic_pointer_cast<Suv>(masina_);
            suvs.push_back(suv_result);
        }
    }
    if (!suvs.empty()) return suvs;
    throw NotFound();
}

std::vector<std::shared_ptr<Sedan>> dealer::cautaSedan() {
    std::vector<std::shared_ptr<Sedan>> sedans;

    for (const auto &masina_: dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Sedan)) {
            auto sedan_result = std::dynamic_pointer_cast<Sedan>(masina_);
            sedans.push_back(sedan_result);
        }
    }
    if (!sedans.empty()) return sedans;
    throw NotFound();
}

std::vector<std::shared_ptr<Coupe>> dealer::cautaCoupe() {
    std::vector<std::shared_ptr<Coupe>> coupes;

    for (const auto &masina_: dealer::stoc) {
        const auto &masina_ref = *masina_;
        if (typeid(masina_ref) == typeid(Coupe)) {
            auto coupe_result = std::dynamic_pointer_cast<Coupe>(masina_);
            coupes.push_back(coupe_result);
        }
    }
    if (!coupes.empty()) return coupes;
    throw NotFound();
}


std::vector<std::shared_ptr<Masina>> dealer::stoc;
int dealer::nr_masini;