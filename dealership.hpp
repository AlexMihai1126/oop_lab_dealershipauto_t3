//
// Created by Alex on 06/12/2022.
//
#include "masina.hpp"
#include "coupe.hpp"
#include "sedan.hpp"
#include "suv.hpp"
#include "exceptions.hpp"
#include <vector>
#include <string>
#include <memory>

#ifndef OOP_DEALERSHIP_HPP
#define OOP_DEALERSHIP_HPP

class dealer {
    static std::vector<std::shared_ptr<masina>> stoc;
    static int nr_masini;
public:
    dealer() = delete;

    static int getNrMasini();

    static void stergeMasina(const std::string &);

    static void
    adaugaMasina(const std::shared_ptr<masina> &); //adauga o masina - intreaba clasa si dupa introduce datele
    static std::vector<std::shared_ptr<masina>> &getStoc();

    static std::shared_ptr<masina> cautaVIN(const std::string &);

    static std::vector<std::shared_ptr<masina>> cautaBrand(const std::string &);

    static std::vector<std::shared_ptr<suv>> cautaSUV();

    static std::vector<std::shared_ptr<sedan>> cautaSedan();

    static std::vector<std::shared_ptr<coupe>> cautaCoupe();

};

#endif //OOP_DEALERSHIP_HPP