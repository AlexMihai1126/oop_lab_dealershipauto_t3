//
// Created by Alex on 07/12/2022.
//
#include <exception>
#include "IOStreamW.hpp"

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP

class YearOutOfRange : public std::exception, public IOStreamW {
public:
    YearOutOfRange() = default;

    [[nodiscard]] const char *what() const noexcept override;

    void print(std::ostream &) const override;

};

class MonthOutOfRange : public std::exception, public IOStreamW {
public:
    MonthOutOfRange() = default;

    [[nodiscard]] const char *what() const noexcept override;

    void print(std::ostream &) const override;

};

class NotFound : public std::exception, public IOStreamW {
public:
    NotFound() = default;

    [[nodiscard]] const char *what() const noexcept override;

    void print(std::ostream &) const override;

};

class WrongDataBool : public std::exception, public IOStreamW {
public:
    WrongDataBool() = default;

    [[nodiscard]] const char *what() const noexcept override;

    void print(std::ostream &) const override;

};

#endif //OOP_EXCEPTIONS_HPP
