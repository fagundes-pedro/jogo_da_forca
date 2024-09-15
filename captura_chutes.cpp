#include <iostream>
#include "captura_chutes.hpp"
#include "letra_existe.hpp"

void captura_chutes(std::vector<char>* chutes_errados, std::map<char, bool>* chutou, std::string palavra_secreta){
    char chute;
    std::cout << "Chute uma letra da palavra secreta: ";
    std::cin >> chute;
    (*chutou)[chute] = true;
    std::cout << std::endl;
    if (letra_existe(chute, palavra_secreta)) {
        std::cout << "A letra " << chute << " esta na palavra secreta" << std::endl;
    }
    else {
        std::cout << "A letra " << chute << " NAO esta na palavra secreta" << std::endl;
        chutes_errados->push_back(chute);
    }
}