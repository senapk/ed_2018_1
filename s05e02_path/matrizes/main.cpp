#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm> //random_shuffle

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat, Par inicio, Par fim, Par atual){
    mat_draw(mat);
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
    mat_focus(atual, 'y');
    ed_show();
}


vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

void furar(matchar &mat, Par par){
    if(!mat.equals(par, PAREDE) || countOpen(mat, par) > 1)
        return;
    mat.get(par) = ABERTO;
    for(Par vizinho : shuffle(getNeib(par)))
        furar(mat, vizinho);
}

bool findPath(matchar& mat, Par inicio, Par final, Par atual){
    if(atual == final){
        mat.get(atual) = CAMINHO;
        showMat(mat, inicio, final, atual);
        return true;
    }
    if(!mat.is_inside(atual))
        return false;
    if(mat.get(atual) != ABERTO)
        return false;
    mat.get(atual) = EMBUSCA;
    showMat(mat, inicio, final, atual);

    for(Par vizinho : shuffle(getNeib(atual))){
        if(findPath(mat, inicio, final, vizinho)){
            mat.get(atual) = CAMINHO;
            showMat(mat, inicio, final, atual);
            return true;
        }
    }
    mat.get(atual) = ABATIDO;
    showMat(mat, inicio, final, atual);
    return false;
}

#include <cstdlib>
#include <ctime>
int main(){
    srand(time(NULL));
    matchar mat(15, 20, PAREDE);
    furar(mat, Par(1, 1));//chama a função recursiva
    mat_draw(mat);
    ed_show();
    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");
    mat_draw(mat);
    ed_show();

    findPath(mat, inicio, final, inicio);

    ed_lock();//impede que termine abruptamente
    return 0;
}


