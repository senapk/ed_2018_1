#include <iostream>
#include <map>//arvore TreeMap
#include <unordered_map> //arvore HashMap

#include <set> //arvore TreeSet
#include <unordered_set>//hash HashSet
using namespace std;

struct Elem {
    int key;

    Elem(int key = 0){
        this->key = key;
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
    vector<list<Elem>> vet;
    HashLista(int size):
        vet(size){
    }

    bool insert(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it != lista.end())
            return false;
        lista.push_back(elem);
        return true;
    }

    bool busca(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        return (it == lista.end());
    }

    bool remocao(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        lista.erase(it);
        return true;
    }

}


int main()
{

    return 0;
}






