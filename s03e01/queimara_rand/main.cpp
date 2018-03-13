#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


const int nc = 60;
const int nl = 20;

struct Par{
    int l, c;
    //construtor
    Par(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Par> getNeib(Par p){
    vector<Par> v;
    v.push_back(Par(p.l, p.c + 1));
    v.push_back(Par(p.l, p.c - 1));
    v.push_back(Par(p.l + 1, p.c));
    v.push_back(Par(p.l - 1, p.c));
    return v;
}

void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}


vector<Par> embaralhar(vector<Par> vet){
    for(int i = 0; i < (int) vet.size(); i++){
        int aleat = rand() % vet.size();
//        int aux = vet[i];
//        vet[i] = vet[aleat];
//        vet[aleat] = aux;
        std::swap(vet[i], vet[aleat]);
    }
    return vet;
}

//int queimar(vector<string> &mat, int l, int c, int nivel)
int queimar(vector<string> &mat, int l, int c){
    if(l < 0 || l >= nl)
        return 0;
    if(c < 0 || c >= nc)
        return 0;
    if(mat[l][c] != '#')
        return 0;

    mat[l][c] = '0';

    mostrar(mat);

//    vector<int> vet = {3, 4, 2, 1, 6};
//    vector<int> v2 = embaralhar(vet);
//    vector<int> v3 = std::random_shuffle(
//                begin(vet), end(vet));

    //for range
    for(Par p : embaralhar(getNeib(Par(l, c))))
        queimar(mat, p.l, p.c);
        //queimar(mat, p.l, p.c, nivel + 1);

    return 0;
}


int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '
    vector<string> mat(nl, string(nc, '#'));
//    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
//    for(int i = 0; i < narvores; i++){
//        mat[rand() % nl][rand() % nc] = '#';
//    }

    mostrar(mat);
    int total = queimar(mat, 0, 0);
    cout << total << " arvores queimaram\n";

    return 0;
}
