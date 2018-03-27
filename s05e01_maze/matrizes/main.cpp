#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

//MAPA DE CORES
//r red
//g green
//b blue
//m magenta
//c cyan -
//y yellow
//w white
//k black

const char PAREDE = 'k';
const char FURADO = 'w';
const char RETORNO = 'c';
const char MARCADOR = 'r';
const char ATENCAO = 'y';

vector<Par> pegar_vizinhos(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int contar_vizinhos_furados(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : pegar_vizinhos(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

#include <algorithm>
void furar(matchar &mat, Par par){
    //PONTOS DE PARADA
    if(!mat.is_inside(par))//se estiver fora da matriz
        return;
    mat_draw(mat);//desenha a matriz
    mat_focus(par, ATENCAO);//faz uma bolinha em par
    ed_show();//mostra na tela

    if(mat.get(par) != PAREDE)//se nao for arvore
        return;

    if(contar_vizinhos_furados(mat, par) > 1)
        return;

    //ACAO
    mat.get(par) = FURADO;

    //DESENHO
    mat_draw(mat);//desenha a matriz
    mat_focus(par, MARCADOR);//faz uma bolinha em par
    ed_show();//mostra na tela

    //RECURSAO
    vector<Par> vizinhos = pegar_vizinhos(par);
    std::random_shuffle(begin(vizinhos), end(vizinhos));

    for(Par vizinho : vizinhos)
        furar(mat, vizinho);

    //ACAO APOS A RECURSAO
    mat.get(par) = RETORNO;

    //DESENHO
    mat_draw(mat);//desenha a matriz
    mat_focus(par, MARCADOR);//faz uma bolinha em par
    ed_show();//mostra na tela
}

#include <cstdlib>
#include <ctime>
int main(){
    srand(time(NULL));
    //cria uma matriz de caracteres de 15 linhas por 20 colunas, e preenche todos os elementos
    //com 'y'
    matchar mat(15, 20, PAREDE);

    furar(mat, Par(1, 1));//chama a função recursiva

    ed_lock();//impede que termine abruptamente

    return 0;
}


