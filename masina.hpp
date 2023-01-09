//
// Created by Alex on 07/12/2022.
//
#include <string>
#include "IOStreamR.hpp"
#include "IOStreamW.hpp"
#include "IDGenerator.hpp"

#ifndef OOP_MASINA_HPP
#define OOP_MASINA_HPP

class masina : public IOStreamR, public IOStreamW {
    std::string marca;
    std::string model;
    std::string vin;
    int an_fab;
    int luna_fab;
    int id;
public:
    masina();

    masina(std::string, std::string, std::string, int, int);

    masina(const masina &copy);

    [[maybe_unused]] virtual void setMarca(std::string);

    [[maybe_unused]] virtual void setModel(std::string);

    [[maybe_unused]] virtual void setVin(std::string);

    [[maybe_unused]] virtual void setAnFab(int);

    [[maybe_unused]] virtual void setLunaFab(int);

    [[maybe_unused]] virtual void setID(int);

    [[nodiscard]] std::string getMarca() const;

    [[nodiscard]] std::string getModel() const;

    [[nodiscard]] std::string getVin() const;

    [[nodiscard]] int getAnFab() const;

    [[nodiscard]] int getLunaFab() const;

    [[nodiscard]] int getIDMasina() const;

    [[maybe_unused]] virtual void afisareMasina() const = 0;

    masina &operator=(const masina &);

    virtual ~masina();
};

#endif //OOP_MASINA_HPP
