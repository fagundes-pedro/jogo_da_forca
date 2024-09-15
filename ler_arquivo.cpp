#include <iostream>
#include <fstream>
#include "ler_arquivo.hpp"

std::vector<std::string> ler_arquivo() {
    std::ifstream arquivo;
    int qtd_palavas = 0;
    std::vector<std::string> lista_palavras;
    std::string palavra_lida;
    arquivo.open("palavras_secretas.txt");
    if (arquivo.is_open()) {
        arquivo >> qtd_palavas;
        for (int i = 0; i < qtd_palavas; i++) {
            arquivo >> palavra_lida;
            lista_palavras.push_back(palavra_lida);
        }
    }
    else {
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        exit(0);
    }
    arquivo.close();
    return lista_palavras;
}