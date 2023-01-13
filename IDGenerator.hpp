//
// Created by Alex on 09/01/2023.
//

#ifndef OOP_IDGENERATOR_HPP
#define OOP_IDGENERATOR_HPP
class IDGen{
    static int id;
    static IDGen* unic;
    IDGen(){
        id=0;
    }
public:
    IDGen(const IDGen&) = delete;
    IDGen& operator=(const IDGen&)=delete;
    static IDGen & getIDGen();
    static int getID();
};
#endif //OOP_IDGENERATOR_HPP
