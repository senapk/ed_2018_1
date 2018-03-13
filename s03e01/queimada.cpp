#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


const int nc = 60;
const int nl = 20;

void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}


int queimar(vector<string> &mat, int l, int c){
	if(l < 0 || l >= nl)
		return 0;
	if(c < 0 || c >= nc)
		return 0;
	if(mat[l][c] != '#')
		return 0;
	mat[l][c] = 'o';

	mostrar(mat);
	
	queimar(mat, l, c + 1);
	queimar(mat, l, c - 1);
	queimar(mat, l - 1, c);
	queimar(mat, l + 1, c);
	
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
    vector<string> mat(nl, string(nc, ' '));
    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
    for(int i = 0; i < narvores; i++){
        mat[rand() % nl][rand() % nc] = '#';
    }

    mostrar(mat);
    int total = queimar(mat, 0, 0);
    cout << total << " arvores queimaram\n";

    return 0;
}

