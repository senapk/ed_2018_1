#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm> //random_shuffle

using namespace std;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat, vector<Par> pilha, Par inicio, Par fim){
    mat_draw(mat);
    for(Par par : pilha)
        mat_focus(par, 'c');
    if(pilha.size() > 0)
        mat_focus(pilha.back(), 'k');
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
}


vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
//    vizinhos.push_back(Par(par.l - 1, par.c - 1));
//    vizinhos.push_back(Par(par.l - 1, par.c + 1));
//    vizinhos.push_back(Par(par.l + 1, par.c + 1));
//    vizinhos.push_back(Par(par.l + 1, par.c - 1));
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

bool findPath(matchar& mat, Par inicio, Par final){
    vector<Par> pilha;
    pilha.push_back(inicio);
    mat.get(inicio) = EMBUSCA;

    while(pilha.size() != 0){
        Par topo = pilha.back();
        if(topo == final){
            showMat(mat, pilha, inicio, final);
            ed_show();
            return true;
        }
        vector<Par> viz_abertos;
        showMat(mat, pilha, inicio, final);
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO){
                viz_abertos.push_back(par);
                mat_focus(par, 'r');
            }
        }
        ed_show();
        if(viz_abertos.size() == 0){
            pilha.pop_back();
            showMat(mat, pilha, inicio, final);
            ed_show();
        }else{
            Par escolhido = viz_abertos[rand() % viz_abertos.size()];
            mat.get(escolhido) = EMBUSCA;
            pilha.push_back(escolhido);
            showMat(mat, pilha, inicio, final);
            ed_show();
        }
    }
    showMat(mat, pilha, inicio, final);
    ed_show();
    return false;
}

#include <cstdlib>
#include <ctime>
int main(){
    srand(time(NULL));
    matchar mat(10, 15, PAREDE);
    furar(mat, Par(1, 1));//chama a função recursiva
    mat_draw(mat);
    ed_show();
    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");
    mat_draw(mat);
    ed_show();

    findPath(mat, inicio, final);
    ed_lock();//impede que termine abruptamente
    return 0;
}


