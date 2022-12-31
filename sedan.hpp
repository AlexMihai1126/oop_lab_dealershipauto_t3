//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"

#ifndef OOP_SEDAN_HPP
#define OOP_SEDAN_HPP

class sedan : public masina {
    int clasa; // 1-compact,2-executive, 3-luxury
public:
    sedan();

    sedan(std::string, std::string, std::string, int, int, int);

    [[maybe_unused]]virtual void setSedan(std::string, std::string, std::string, int, int, int);

    [[maybe_unused]]void setClasa(int);

    sedan &operator=(const sedan &);

    void print(std::ostream &) const override;

    void read(std::istream &) override;

    sedan(const sedan &copy);

    [[nodiscard]] int getClasa() const;

    void afisareMasina() const override;
};

#endif //OOP_SEDAN_HPP
