//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//using namespace std;


//const int nc = 60;
//const int nl = 20;

//void mostrar(vector<string>& mat){
//    cout << string(50, '\n');
//    for(string s : mat)
//        cout << s << endl;
//    getchar();
//}

//int queimar(vector<string> &mat, int l, int c, int level){
//    if(l < 0 || l >= nl)
//        return 0;
//    if(c < 0 || c >= nc)
//        return 0;
//    if(mat[l][c] != '#')
//        return 0;
//    mat[l][c] = '0' + level;
//    mostrar(mat);

//    int cont = 1;
//    int next = (level + 1) % 10;
//    cont += queimar(mat, l, c + 1, next);
//    cont += queimar(mat, l, c - 1, next);
//    cont += queimar(mat, l - 1, c, next);
//    cont += queimar(mat, l + 1, c, next);

//    mat[l][c] = '.';
//    mostrar(mat);
//    return cont;
//}


//int main()
//{
//    srand(time(NULL));
//    //os containers tem uma construção padrao
//    //container<tipo> nome(qtd, elemento_default)
//    //cria um vetor de string
//    //com nl elementos da string default
//    //a string default sao 30 char ' '
//    vector<string> mat(nl, string(nc, ' '));
//    int narvores = nl * nc * 1.5;
//    //insere varias arvores em lugares aleatorios
//    //muitas serao superpostas
//    for(int i = 0; i < narvores; i++){
//        mat[rand() % nl][rand() % nc] = '#';
//    }

//    mostrar(mat);
//    int total = queimar(mat, 0, 0, 0);
//    cout << total << " arvores queimaram\n";
//    string saida;
//    cin >> saida;
//    return 0;
//}

