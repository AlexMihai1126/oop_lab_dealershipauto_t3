//
// Created by Alex on 10/01/2023.
//

#ifndef OOP_COUNT_HPP
#define OOP_COUNT_HPP
#include <vector>
#include <memory>
#include "masina.hpp"
#include "exceptions.hpp"
template<class T, class S>
void countN(std::vector<T> v, const S val){
    int nr=0;
    for(){
    }
    if(nr==0) std::cout<<"Nu s-a gasit elementul "<<val<<"."<<std::endl;
    else std::cout<<"Numarul de elemente"<<val<<" este de: "<<nr<<"."<<std::endl;
} //functie template

template<>
void countN(const std::vector<std::shared_ptr<Masina>> v, const std::string val){
    int nr=0;
    if(nr==0) std::cout<<"Nu s-a gasit nicio masina cu brand-ul"<<val<<"."<<std::endl;
    else std::cout<<"Numarul de masini care au brand-ul "<<val<<" este de: "<<nr<<"."<<std::endl;
} //specializare
#endif //OOP_COUNT_HPP
