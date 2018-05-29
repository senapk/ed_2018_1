#include <iostream>
#include <list>
using namespace std;

template <class T>
ostream& operator<<(ostream& os, const list<T*>& lista){
    os << "[ ";
    for(const auto& elem : lista)
        os << *elem << " ";
    os << "]";
    return os;
}

void wait(){
    getchar();
}

void stop(){
    cout << "sair? y/n ";
    string s;
    while(s != "y"){
        cin >> s;
    }
}

void remover_1_e_ir_matando()
{
    list<int*> lista;
    int qtd = 15;
    int max = 10;

    //preencher a lista com 15 elementos entre 0 e 9
    for(int i = 0; i < qtd; i++)
        lista.push_back(new int(rand() % max));

    //a cada interação remova 1 de cada elemento
    //se o elemento for 0 remova o elemento da lista
    //até que a lista esteja vazia
    while(!lista.empty()){
        for(auto it = lista.begin(); it != lista.end();){
            if((**it) == 0){
                delete *it;
                it = lista.erase(it);
            }else{
                **it -= 1;
                it++;
            }
        }
        for(auto elem : lista)
            cout << *elem <<  " ";
        wait();
    }

    stop();
}

void cupido(){
    list<int*> lista;

    //preencher a lista com 15 elementos entre 0 e 9
    for(auto x : {1, 2, -1, 1, 4, 3, -3, 3, -2, -2})
        lista.push_back(new int(x));

    //Entrada - [1 2 -1 1 4 3 -3 3 -2 -2];
    //Saída   - [1 4 3 -2];

    for(auto i = lista.begin(); i != prev(lista.end()); ){
        cout << (**i) << endl;
        cout << lista;
        bool achei = false;
        for(auto j = next(i); j != lista.end(); j++){
            if((**i) == -(**j)){
                delete *i;
                delete *j;
                lista.erase(j);//j está na frente, deve ser removido primeiro
                i = lista.erase(i);
                achei = true;
                break;
            }
        }
        if(!achei)
            i++;

        wait();
    }

    stop();
}

int main(){
    //remover_1_e_ir_matando();
    cupido();
}



















