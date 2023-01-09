//
// Created by Alex on 07/12/2022.
//
#include "exceptions.hpp"
#include <string>

const char *YearOutOfRange::what() const noexcept {
    return "Anul trebuie sa fie mai mare ca 2000.";
}

void YearOutOfRange::print(std::ostream &os) const {
    os << this->what();
}

const char *MonthOutOfRange::what() const noexcept {
    return "Luna trebuie sa fie intre 1 si 12.";
}

void MonthOutOfRange::print(std::ostream &os) const {
    os << this->what();
}

const char *NotFound::what() const noexcept {
    return "Nu s-a gasit nicio Masina.";
}

void NotFound::print(std::ostream &os) const {
    os << this->what();
}

const char *WrongDataBool::what() const noexcept {
    return "Valoarea poate fi doar 1 sau 0.";
}

void WrongDataBool::print(std::ostream &os) const {
    os << this->what();
}
