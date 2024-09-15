#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "adicionar_palavra.hpp"
#include "ler_arquivo.hpp"

void adicionar_palavra() {
    std::ofstream arquivo;
    std::vector<std::string> lista_palavras;
    std::string nova_palavra;
    lista_palavras = ler_arquivo();
    std::cout << "\n\nDigite a palavra que quer adicionar ao banco de palavras: ";
    std::cin >> nova_palavra;
    lista_palavras.push_back(nova_palavra);
    arquivo.open("palavras_secretas.txt");
    if (arquivo.is_open()) {
        arquivo << lista_palavras.size() << std::endl;
        for (int i = 0; i < lista_palavras.size(); i++) {
            arquivo << lista_palavras[i] << std::endl;
        }
    }
    else {
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        exit(0);
    }
    arquivo.close();
}