#include <iostream>
#include <string>
#include <map>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
string PALAVRA_SECRETA;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute);
bool nao_acertou();
bool nao_enforcou();
void imprime_cabecalho();
void imprime_erros();
void imprime_palavra();
void captura_chutes();
void imprime_final();
vector<string> ler_arquivo();
void adicionar_palavra();
void sorteia_palavra();

int main (){
    sorteia_palavra();
    while(nao_acertou() && nao_enforcou()){
        imprime_cabecalho();
        imprime_erros();
        imprime_palavra();
        captura_chutes();
        Sleep(1000);
        system("CLEAR");
    }
    imprime_final();
    return 0;
}

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){
        if(chute == letra){
            return true;
        }
    }
    return false;
};

bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << "Você já chutou as letras: ";
}

void imprime_erros(){
    for(char letra : chutes_errados){
    cout << letra << " ";
    }
    cout << "\n\n";
}

void imprime_palavra(){
    for(char letra : PALAVRA_SECRETA){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << "\n\n";
}

void captura_chutes(){
    char chute;
    cout << "Chute uma letra da palavra secreta: ";
    cin >> chute;
    chutou[chute] = true;
    cout << endl;
    if(letra_existe(chute)){
        cout << "A letra " << chute << " está na palavra secreta" << endl;
    }else{
        cout << "A letra " << chute << " NÃO está na palavra secreta" << endl;
        chutes_errados.push_back(chute);
    }
}

void imprime_final(){
    if(!nao_acertou()){
        char resposta;
        cout << "\n\nParabéns! Você acertou a palavra secreta " << PALAVRA_SECRETA << endl;
        cout << "Você deseja adicionar uma palavra ao banco[S/N]? ";
        cin >> resposta;
        if(resposta == 'S' || resposta == 's'){
            adicionar_palavra();
        }
    }else{
        cout << "\n\nQue pena, você foi enforcado =/\nA palavra secreta era: " << PALAVRA_SECRETA;
    }
}

vector<string> ler_arquivo(){
    ifstream arquivo;
    int qtd_palavas = 0;
    vector<string> lista_palavras;
    string palavra_lida;
    arquivo.open("palavras_secretas.txt");
    if(arquivo.is_open()){
        arquivo >> qtd_palavas;
        for(int i = 0; i < qtd_palavas; i++){
            arquivo >> palavra_lida;
            lista_palavras.push_back(palavra_lida);
        }
    }else{
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
    arquivo.close();
    return lista_palavras;
}

void adicionar_palavra(){
    ofstream arquivo;
    vector<string> lista_palavras;
    string nova_palavra;
    lista_palavras = ler_arquivo();
    cout << "\n\nDigite a palavra que quer adicionar ao banco de palavras: ";
    cin >> nova_palavra;
    lista_palavras.push_back(nova_palavra);
    arquivo.open("palavras_secretas.txt");
    if(arquivo.is_open()){
        arquivo << lista_palavras.size() << endl;
        for(int i = 0; i < lista_palavras.size(); i++){
            arquivo << lista_palavras[i] << endl;
        }
    }else{
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
    arquivo.close();
}

void sorteia_palavra(){
    vector<string> lista_palavras = ler_arquivo();
    srand(time(NULL));
    int indice = rand() % lista_palavras.size();
    PALAVRA_SECRETA = lista_palavras[indice];
}