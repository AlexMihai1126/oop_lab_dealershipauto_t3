//
// Created by Alex on 10/12/2022.
//
#include "IOStreamR.hpp"

std::istream &operator>>(std::istream &is, IOStreamR &obj) {
    obj.read(is);
    return is;
}

IOStreamR::~IOStreamR() = default;