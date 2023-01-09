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
    static std::vector<std::shared_ptr<Masina>> stoc;
    static int nr_masini;
public:
    dealer() = delete;

    static int getNrMasini();

    static void stergeMasina(const std::string &);

    static void
    adaugaMasina(const std::shared_ptr<Masina> &); //adauga o Masina - intreaba clasa si dupa introduce datele
    static std::vector<std::shared_ptr<Masina>> &getStoc();

    static std::shared_ptr<Masina> cautaVIN(const std::string &);

    static std::vector<std::shared_ptr<Masina>> cautaBrand(const std::string &);

    static std::vector<std::shared_ptr<Suv>> cautaSUV();

    static std::vector<std::shared_ptr<Sedan>> cautaSedan();

    static std::vector<std::shared_ptr<Coupe>> cautaCoupe();

};

#endif //OOP_DEALERSHIP_HPP