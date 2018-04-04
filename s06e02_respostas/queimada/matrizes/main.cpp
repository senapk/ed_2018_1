#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


const int nc = 40;
const int nl = 20;

vector<Par> VDESL = {Par(0, -1), Par(-1, 0), Par(0, 1), Par(1, 0)};

template <typename T>
vector<T> shuffle(vector<T> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

template <typename T>
T somar(T x, T y){
    return x + y;
}

void mostrar(matchar& mat, matriz<int>& matint){
    mat_draw(mat);
    mat_draw(matint);
    ed_show();
}

int queimar(matriz<char> &mat, matriz<int> &matint, Par par, int level){
    int l = par.l;
    int c = par.c;

    if(l < 0 || l >= nl)
        return 0;
    if(c < 0 || c >= nc)
        return 0;
    if(mat.get(l, c) != 'g')
        return 0;

    //mat[l][c] = '0' + level;
    mat.get(l, c) = 'r';
    matint.get(l, c) = level;
    mostrar(mat, matint);

    int cont = 1;
    for(Par d : shuffle(VDESL)){
        cont += queimar(mat, matint, par + d, level + 1);
    }

    //mat[l][c] = '.';
    mat.get(l, c) = 'c';
    mostrar(mat, matint);
    return cont;
}


int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '

    matchar mat(nl, nc, 'w');
    matriz<int> matint(nl, nc, -1);

    //vector<string> mat(nl, string(nc, ' '));

    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
    for(int i = 0; i < narvores; i++){
        mat.get(rand() % nl, rand() % nc) = 'g';
    }

    mostrar(mat, matint);
    int total = queimar(mat, matint, Par(0, 0), 0);

    cout << total << " arvores queimaram\n";
    string saida;
    cin >> saida;
    return 0;
}

