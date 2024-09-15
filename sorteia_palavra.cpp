#include <vector>
#include <ctime>
#include <cstdlib>
#include "sorteia_palavra.hpp"
#include "ler_arquivo.hpp"

std::string sorteia_palavra() {
    std::vector<std::string> lista_palavras = ler_arquivo();
    srand(time(NULL));
    int indice = rand() % lista_palavras.size();
    return lista_palavras[indice];
}