//
// Created by Alex on 10/12/2022.
//
#include "IOStreamW.hpp"

std::ostream &operator<<(std::ostream &os, const IOStreamW &obj) {
    obj.print(os);
    return os;
}

IOStreamW::~IOStreamW() = default;