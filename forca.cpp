#include <string>
#include <map>
#include <Windows.h>
#include <vector>
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "imprime_final.hpp"
#include "captura_chutes.hpp"
#include "sorteia_palavra.hpp"
#include "nao_acertou.hpp"

using namespace std;

int main (){
    string palavra_secreta = sorteia_palavra();
    vector<char> chutes_errados;
    map<char, bool> chutou;

    while(nao_acertou(palavra_secreta, chutou) && (chutes_errados.size() < 5)){
        imprime_cabecalho();
        imprime_erros(chutes_errados);
        imprime_palavra(palavra_secreta, chutou);
        captura_chutes(&chutes_errados, &chutou, palavra_secreta);
        Sleep(1000);
        system("CLS");
    }
    imprime_final(palavra_secreta, nao_acertou(palavra_secreta, chutou));
    return 0;
}