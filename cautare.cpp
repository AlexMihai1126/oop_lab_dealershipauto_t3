//
// Created by Alex on 11/12/2022.
//
#include "cautare.hpp"
#include "dealership.hpp"
#include <string>

void cautare(int type) {
    switch (type) {
        case 1: {
            try {
                for (const auto &masina: Dealer::cautaCoupe()) {
                    std::cout << *masina << std::endl;
                }
            }
            catch (const NotFound &err) {
                std::cout << err << std::endl;
            }
            break;
        }
        case 2: {
            try {
                for (const auto &masina: Dealer::cautaSUV()) {
                    std::cout << *masina << std::endl;
                }
            }
            catch (const NotFound &err) {
                std::cout << err << std::endl;
            }
            break;
        }
        case 3: {
            try {
                for (const auto &masina: Dealer::cautaSedan()) {
                    std::cout << *masina << std::endl;
                }
            }
            catch (const NotFound &err) {
                std::cout << err << std::endl;
            }
            break;
        }
        case 4: {
            try {
                std::string keyword;
                std::cout << "Introdu VIN de cautat: " << std::endl;
                std::getline(std::cin, keyword);
                std::cout << *Dealer::cautaVIN(keyword);
            }
            catch (const NotFound &err) {
                std::cout << err << std::endl;
            }
            break;
        }
        case 5: {
            try {
                std::string brand;
                int nr_rez = 0;
                std::cout << "Introdu brand-ul de cautat: ";
                std::getline(std::cin, brand);
                for (const auto &masina: Dealer::cautaBrand(brand)) {
                    nr_rez++;
                    std::cout << "Rezultat nr " << nr_rez << ":" << std::endl;
                    std::cout << *masina << std::endl;
                }
            }
            catch (const NotFound &err) {
                std::cout << err << std::endl;
            }
            break;
        }
        default: {
            std::cout << "Nu s-a ales o optiune corecta." << std::endl;
            break;
        }
    }
}