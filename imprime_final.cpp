#include <iostream>
#include "imprime_final.hpp"
#include "adicionar_palavra.hpp"

void imprime_final(std::string palavra_secreta, bool nao_acertou){
    if (!nao_acertou) {
        char resposta;
        std::cout << "\n\nParabens! Voce acertou a palavra secreta " << palavra_secreta << std::endl;
        std::cout << "Voce deseja adicionar uma palavra ao banco[S/N]? ";
        std::cin >> resposta;
        std::cout << "\n\n";
        if (resposta == 'S' || resposta == 's') {
            adicionar_palavra();
        }
    }
    else {
        std::cout << "\n\nQue pena, voce foi enforcado =/\nA palavra secreta era: " << palavra_secreta << "\n\n";
    }
}