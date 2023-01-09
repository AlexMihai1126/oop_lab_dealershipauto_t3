//
// Created by Alex on 07/12/2022.
//
#include "masina.hpp"

#ifndef OOP_COUPE_HPP
#define OOP_COUPE_HPP

class Coupe : public Masina {
    float acc_100; //timp 0-100
    bool isConvertible;
public:
    Coupe();

    Coupe(std::string, std::string, std::string, int, int, float, bool);

    [[maybe_unused]]void setAcc(float);

    [[maybe_unused]]void setConv(bool);

    [[maybe_unused]] virtual void setCoupe(std::string, std::string, std::string, int, int, float, bool);

    void print(std::ostream &) const override;

    void read(std::istream &) override;

    Coupe(const Coupe &copy);

    [[nodiscard]] float getAcc100() const;

    [[nodiscard]] bool getConvertible() const;

    Coupe &operator=(const Coupe &);

    void afisareMasina() const override;
};

#endif //OOP_COUPE_HPP
