#include <iostream>

using namespace std;

//essa variavel global só é vizivel nesse arquivo
static int value_arquivo;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    //todos os vetores que eu criar terão a mesmo
    //bloco de memoria
    static int value_classe;


    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            this->reserve(2 * this->_capacidade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        static int dummy = 0;
        return this->_data[indice];
    }

    int& front(){
        static int dummy = 0;
        if(this->_size > 0)
            return this->_data[0];
        return dummy;
    }

    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        static int dummy = 0;
        if(_size != 0)
            return &this->_data[0];
        return nullptr;
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return _size;
    }
    int capacity(){
        return _capacidade;
    }

    void reserve(int capacity){
        int * backup_data = this->_data;
        this->_data = new int(capacity);
        this->_capacidade = capacity;
        if(this->_size > capacity)
            this->_size = capacity;
        for(int i = 0; i < this->_size; i++)
            this->_data[i] = backup_data[i];
        delete [] backup_data;
    }
};

#include <vector>
int main()
{

    Vector v;
    v.front() = 5;
    cout << v.front();
    cout << "Hello World!" << endl;
    return 0;
}










