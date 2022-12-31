#include <iostream>
#include "dealership.hpp"
#include "cautare.hpp"
#include "carTypes.hpp"

using namespace std;

int main() {
    int intrare = 10, timeout = 0;
    while (intrare && timeout <= 5) {
        cout << "Optiunea 1: introdu o masina." << endl;
        cout << "Optiunea 2: sterge o masina dupa VIN." << endl;
        cout << "Optiunea 3: cauta." << endl;
        cout << "Optiunea 4: afiseaza nr de masini si detaliile lor." << endl;
        cout << "Iesire: tasta 0" << endl;
        cin >> intrare;
        switch (intrare) {
            case 0: {
                cout << "Iesire din program.";
                return 0;
            }
            case 1: {
                std::cout << "S - Suv, B - Sedan, C - Coupe" << std::endl;
                std::string input;
                cin.sync();
                std::getline(cin, input);
                if (input == "S" || input == "s") {
                    std::cout << "Se va introduce un SUV" << std::endl;
                    std::string marca_;
                    std::string model_;
                    std::string vin_;
                    int an_fab;
                    int luna_fab;
                    float garda_sol;
                    int cap_tr;
                    std::cout << "Marca: ";
                    std::cin.sync();
                    std::getline(std::cin, marca_);
                    std::cout << "Model: ";
                    std::cin.sync();
                    std::getline(std::cin, model_);
                    std::cout << "Vin: ";
                    std::cin.sync();
                    std::getline(std::cin, vin_);
                    try {
                        std::cout << "An de fabricatie: ";
                        std::cin.sync();
                        std::cin >> an_fab;
                        if (an_fab < 2000) throw YearOutOfRange();
                    }
                    catch (const YearOutOfRange &e) {
                        std::cout << e << std::endl;
                        break;
                    }

                    try {
                        std::cout << "Luna de fabricatie: ";
                        std::cin.sync();
                        std::cin >> luna_fab;
                        if (luna_fab < 1 || luna_fab > 12) throw MonthOutOfRange();
                    }
                    catch (const MonthOutOfRange &e) {
                        std::cout << e << std::endl;
                        break;
                    }
                    std::cout << "Garda la sol: ";
                    std::cin >> garda_sol;
                    std::cout << "Capacitate de tractare: ";
                    std::cin >> cap_tr;
                    auto suv_add = std::make_shared<suv>(marca_, model_, vin_, an_fab, luna_fab, garda_sol, cap_tr);
                    dealer::adaugaMasina(suv_add);
                } else {
                    if (input == "B" || input == "b") {
                        std::cout << "Se va introduce un Sedan" << std::endl;
                        std::string marca_;
                        std::string model_;
                        std::string vin_;
                        int an_fab;
                        int luna_fab;
                        int clasa;
                        std::cout << "Marca: ";
                        std::cin.sync();
                        std::getline(std::cin, marca_);
                        std::cout << "Model: ";
                        std::cin.sync();
                        std::getline(std::cin, model_);
                        std::cout << "Vin: ";
                        std::cin.sync();
                        std::getline(std::cin, vin_);
                        try {
                            std::cout << "An de fabricatie: ";
                            std::cin.sync();
                            std::cin >> an_fab;
                            if (an_fab < 2000) throw YearOutOfRange();
                        }
                        catch (const YearOutOfRange &e) {
                            std::cout << e << std::endl;
                            break;
                        }

                        try {
                            std::cout << "Luna de fabricatie: ";
                            std::cin.sync();
                            std::cin >> luna_fab;
                            if (luna_fab < 1 || luna_fab > 12) throw MonthOutOfRange();
                        }
                        catch (const MonthOutOfRange &e) {
                            std::cout << e << std::endl;
                            break;
                        }
                        std::cout << "Clasa: 1-compact, 2-luxury sau 3-executive: ";
                        std::cin.sync();
                        std::cin >> clasa;
                        auto sedan_add = std::make_shared<sedan>(marca_, model_, vin_, an_fab, luna_fab, clasa);
                        dealer::adaugaMasina(sedan_add);
                    } else {
                        if (input == "C" || input == "c") {
                            std::cout << "Se va introduce un Coupe" << std::endl;
                            std::string marca_;
                            std::string model_;
                            std::string vin_;
                            int an_fab;
                            int luna_fab;
                            float acc;
                            bool conv;
                            int conv_in;
                            std::cout << "Marca: ";
                            std::cin.sync();
                            std::getline(std::cin, marca_);
                            std::cout << "Model: ";
                            std::cin.sync();
                            std::getline(std::cin, model_);
                            std::cout << "Vin: ";
                            std::cin.sync();
                            std::getline(std::cin, vin_);
                            try {
                                std::cout << "An de fabricatie: ";
                                std::cin.sync();
                                std::cin >> an_fab;
                                if (an_fab < 2000) throw YearOutOfRange();
                            }
                            catch (const YearOutOfRange &e) {
                                std::cout << e << std::endl;
                                break;
                            }

                            try {
                                std::cout << "Luna de fabricatie: ";
                                std::cin.sync();
                                std::cin >> luna_fab;
                                if (luna_fab < 1 || luna_fab > 12) throw MonthOutOfRange();
                            }
                            catch (const MonthOutOfRange &e) {
                                std::cout << e << std::endl;
                                break;
                            }
                            std::cout << "Acceleratie 0-100: ";
                            std::cin.sync();
                            std::cin >> acc;
                            try {
                                std::cout << "Este convertible? (1-True/0-False)";
                                std::cin.sync();
                                std::cin >> conv_in;
                                if (!(conv_in == 1 || conv_in == 0)) throw WrongDataBool();
                                else {
                                    if (conv_in == 0) conv = false;
                                    if (conv_in == 1) conv = true;
                                }
                            }
                            catch (const WrongDataBool &e) {
                                std::cout << e << std::endl;
                                break;
                            }
                            auto coupe_add = std::make_shared<coupe>(marca_, model_, vin_, an_fab, luna_fab, acc, conv);
                            dealer::adaugaMasina(coupe_add);
                        } else {
                            std::cout << "Nu s-a introdus o optiune corecta." << std::endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Introdu VIN-ul masinii pe care doresti sa o stergi:";
                std::string vin_del;
                std::cin.sync();
                std::getline(cin, vin_del);
                try {
                    dealer::stergeMasina(vin_del);
                }
                catch (const NotFound &e) {
                    std::cout << e << std::endl;
                    break;
                }
                break;
            }
            case 3: {
                std::cout << "S - Suv, B - Sedan, C - Coupe, V - Vin, M - Marca" << std::endl;
                std::string in;
                std::cin.sync();
                std::getline(cin, in);
                if (in == "S" || in == "s") {
                    try {
                        cautare((int)carType::SUV);
                    }
                    catch (const NotFound &e) {
                        std::cout << e << std::endl;
                        break;
                    }
                } else {
                    if (in == "B" || in == "b") {
                        try {
                            cautare((int)carType::Sedan);
                        }
                        catch (const NotFound &e) {
                            std::cout << e << std::endl;
                            break;
                        }
                    } else {
                        if (in == "C" || in == "c") {
                            try {
                                cautare((int)carType::Coupe);
                            }
                            catch (const NotFound &e) {
                                std::cout << e << std::endl;
                                break;
                            }
                        } else {
                            if (in == "V" || in == "v") {
                                try {
                                    cautare(4);
                                }
                                catch (const NotFound &e) {
                                    std::cout << e << std::endl;
                                    break;
                                }
                            } else {
                                if (in == "M" || in == "m") {
                                    try {
                                        cautare(5);
                                    }
                                    catch (const NotFound &e) {
                                        std::cout << e << std::endl;
                                        break;
                                    }

                                } else {
                                    std::cout << "Nu s-a introdus o optiune valida." << std::endl;
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case 4: {
                std::cout<<"Numar de masini: "<<dealer::getNrMasini()<<std::endl;
                for (const auto &obj: dealer::getStoc()) {
                    std::cout << *obj;
                }
                break;
            }
            default: {
                cout << "Optiune invalida." << endl;
                timeout++; //dupa un anumit numar de incercari esuate, programul se va opri automat
                break;
            }
        }
    }
    return 0;
}
