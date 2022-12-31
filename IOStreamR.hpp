//
// Created by Alex on 10/12/2022.
//
#include <iostream>

#ifndef OOP_IOSTREAMR_HPP
#define OOP_IOSTREAMR_HPP

class IOStreamR {
protected:
    friend std::istream &operator>>(std::istream &, IOStreamR &);

    virtual void read(std::istream &) = 0;

    virtual ~IOStreamR();
};

#endif //OOP_IOSTREAMR_HPP
