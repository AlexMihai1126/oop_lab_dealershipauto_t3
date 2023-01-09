//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"

#ifndef OOP_SUV_HPP
#define OOP_SUV_HPP

class Suv : public Masina {
    float garda_la_sol;
    int capacitate_tractare;
public:
    Suv();

    Suv(std::string, std::string, std::string, int, int, float, int);

    [[maybe_unused]]void setGardaSol(float);

    [[maybe_unused]]void setCapT(int);

    [[maybe_unused]] virtual void setSuv(std::string, std::string, std::string, int, int, float, int);

    Suv(const Suv &copy);

    void print(std::ostream &) const override;

    void read(std::istream &) override;

    [[nodiscard]] float getGardaLaSol() const;

    [[nodiscard]] int getCapacitateTractare() const;

    Suv &operator=(const Suv &);

    void afisareMasina() const override;
};

#endif //OOP_SUV_HPP
