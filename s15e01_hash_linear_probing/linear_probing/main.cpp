#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

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

struct HashLinear{ //linear probing
    pair<Elem, Marcador> * vet;
    int capacity;
    int size;
    HashLinear(int capacity){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = VAZIO;
        }
    }

    bool insert(Elem elem){
        auto it = find(elem.key);
        if(it == nullptr)
            return false;
        pos = calcula a posicao base;
        enquanto pos != vazio ou deletado
            pos = (pos + 1) % capacity;
        pos.elem = elem
        pos.marcador = CHEIO
        size ++;

    }

    bool remove(int key){
        it = find(key)
        if nao eh nulo
            it.marcador = DELETADO;
        size--;
    }

    pair<Elem, Marcador> * find(int key){
        pos = calcula a posicao base;
        enquanto(vet na pos nao for vazio nem key)
            anda
        if(vet na pos eh vazio)
            return nulo
        return elem
    }

    void resize(int capacity){
        auto vet_old = vet;
        vet = new pair<...>[capacity];
        for(auto i = 0; ...)
            vet[i].marcador = VAZIO;
        for(auto& elem : vet_old)
            insert(elem)
        delete vet_old
    }

}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
