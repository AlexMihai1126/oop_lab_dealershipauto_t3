//
// Created by Alex on 09/01/2023.
//
#include "IDGenerator.hpp"

int IDGen::id;
IDGen*::IDGen::unic= nullptr; //initializez cu null, va primi adresa dupa aplelarea functiei de getIDGen

int IDGen::getID() {
    id++;
    return id;
}
