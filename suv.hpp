//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"

#ifndef OOP_SUV_HPP
#define OOP_SUV_HPP

class suv : public masina {
    float garda_la_sol;
    int capacitate_tractare;
public:
    suv();

    suv(std::string, std::string, std::string, int, int, float, int);

    [[maybe_unused]]void setGardaSol(float);

    [[maybe_unused]]void setCapT(int);

    [[maybe_unused]] virtual void setSuv(std::string, std::string, std::string, int, int, float, int);

    suv(const suv &copy);

    void print(std::ostream &) const override;

    void read(std::istream &) override;

    [[nodiscard]] float getGardaLaSol() const;

    [[nodiscard]] int getCapacitateTractare() const;

    suv &operator=(const suv &);

    void afisareMasina() const override;
};

#endif //OOP_SUV_HPP
