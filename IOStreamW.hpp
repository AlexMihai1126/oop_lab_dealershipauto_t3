//
// Created by Alex on 10/12/2022.
//
#include <iostream>

#ifndef OOP_IOSTREAMW_HPP
#define OOP_IOSTREAMW_HPP

class IOStreamW {
protected:
    virtual void print(std::ostream &) const = 0;

    friend std::ostream &operator<<(std::ostream &, const IOStreamW &);

    virtual ~IOStreamW();
};

#endif //OOP_IOSTREAMW_HPP
