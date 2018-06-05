#include <iostream>
using namespace std;

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

/*

  tree -> imponho ordenacao - chaves ou elementos devem ser ordenaveis
                              mapa      set
  hash -> não imponho ordenacao - preciso saber calcular o hash
                              das chaves ou dos elementos
                                  mapa          set


*/

#include <vector>
#include <list>
#include <algorithm>

struct HashLista{
    vector<list<Elem>> * vet;
    int qtdElem = 0;
    HashLista(int size){
        vet = new vector<list<Elem>>(size);
    }

    bool insert(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        //se fator de carga > maximo
        resize(new );
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it != lista.end())
            return false;
        lista.push_back(elem);
        return true;
    }

    //cria um novo vetor de listas com tamant new_vet_size
    //e REINSERE todos os elementos no novo vetor
    void resize(int new_vet_size){
        auto vet_old = this->vet;
        this->vet = new vector<list<Elem>>(new_vet_size);
        for(auto& lista : *vet_old)
            for(auto& elem : lista)
                this->insert(elem);
        delete vet_old;

    }

    bool busca(Elem elem) {
        int base = elem.key % vet->size();
        auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        return (it == lista.end());
    }

    bool remocao(Elem elem) {
        int base = elem.key % vet->size();
        auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        lista.erase(it);
        return true;
    }
};


int main()
{

    return 0;
}






