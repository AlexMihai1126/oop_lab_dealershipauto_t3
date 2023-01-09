//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"

#ifndef OOP_SEDAN_HPP
#define OOP_SEDAN_HPP

class Sedan : public Masina {
    int clasa; // 1-compact,2-executive, 3-luxury
public:
    Sedan();

    Sedan(std::string, std::string, std::string, int, int, int);

    [[maybe_unused]]virtual void setSedan(std::string, std::string, std::string, int, int, int);

    [[maybe_unused]]void setClasa(int);

    Sedan &operator=(const Sedan &);

    void print(std::ostream &) const override;

    void read(std::istream &) override;

    Sedan(const Sedan &copy);

    [[nodiscard]] int getClasa() const;

    void afisareMasina() const override;
};

#endif //OOP_SEDAN_HPP
