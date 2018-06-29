# Questão 0
Seja uma lista com N elementos. Cada vez que encontrar dois elementos iguais, some e coloque no fim da lista.

        Exemplo: 1 4 2 4 8 1 16 //1
            4 2 4 8 16 2 //achou o 4
            2 8 16 2 8 //achou o 2
            8 16 8 4 //achou o 4
            16 4 16
            32 4 //fim
Faça um função que receba um list<int> e opere sobre a lista, teste seu código.

```c++
#include <iostream>
#include <list>
using namespace std;

bool matar(list<int>& l){
    for(auto i = l.begin(); i != std::prev(l.end()); i++)
        for(auto j = std::next(i); j != l.end(); j++)
            if(*i == *j){
                l.push_back(2 * (*i));
                l.erase(i);
                l.erase(j);
                return true;
            }
    return false;
}

int main(){
    list<i> l {2, 2, 4 , 3, 1, 4, 8};
    while(matar(l)){
        for(auto e : l)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}
```

---
# Questão 1

1. (1 ponto) Faça a função de embaralhar vetor que recebe um vetor e retorna um vetor embaralhado.

        vector<int> embaralhar(vector<int> vet);

```c++
#include <cstdio>
#include <vector>
#include <cstdlib> //rand
using namespace std;
vector<int> embaralhar(vector<int> vet){
    for(uint i = 0; i < vet.size(); i++)
        std::swap(vet[i], vet[rand() % vet.size()]);
    return vet;
}
int main(){
    for(auto x : embaralhar({1, 2, 3, 4, 5, 6, 7, 8, 9}))
        printf("%d ", x);
    puts("");
    return 0;
}
```

---

# Questão 2

Seja uma matriz que representa árvores onde os 1s são arvores e os zeros espaços vazios. Alguém do mal, colocou fogo em todas as árvores que ficam na primeira coluna da matriz, faça um código recursivo que informe se alguma árvore da ultima coluna será queimada a partir do fogo que foi tocado nas árvores da primeira coluna.

```c++
#include <iostream>
#define NL 5
#define NC 5
#define OPEN 0
#define TREE 1
#define BURN 2
bool queimar(int mat[NL][NC], int c, int l){
    if((c < 0) || (c >= NC) || (l < 0) || (l >= NL))
        return false;
    if(mat[l][c] != TREE)
        return false;
    mat[l][c] = BURN;
    if(c == NC - 1) //ultima coluna
        return true;
    bool result =  queimar(mat, c - 1, l) || queimar(mat, c + 1, l) || 
                   queimar(mat, c, l - 1) || queimar(mat, c, l + 1);
    if(result)
        std::cout << "(l:" << l << ",c:" << c << ")";
    return result; 
}

int main(){
    int mat[NL][NC] = { {0, 0, 1, 0, 1}, 
                        {0, 1, 0, 1, 1},
                        {1, 0, 1, 1, 0},
                        {0, 1, 1, 0, 0},
                        {1, 1, 0, 0, 0}};

    //esse laço vai imprimir o caminho inverso até o comeco
    //(l:1,c:3)(l:2,c:3)(l:2,c:2)(l:3,c:2)(l:3,c:1)(l:4,c:1)(l:4,c:0)
    for(int l = 0; l < NL; l++)
        queimar(mat, 0, l);
    return 0;
}
```

---
# Questão 3
Faça uma função recursiva que conta quantas vogais seu nome possui.

```c++
#include <cstdio>
const char * vogais = "aeiouAEIOU";

bool isVogal(char c){
    for(int i = 0; i < 10; i++)
        if(vogais[i] == c)
            return true;
    return false;
}

int contar(const char * c){
    if((*c) == '\0') 
        return 0;
    return (isVogal(*c) ? 1 : 0) + contar(c + 1);
}

int main(){
    printf("%d vogais\n", contar("E um paralelepipedU"));//9
    return 0;
}
```

---
# Questão 4
Escreva o pseudocodigo para encontrar um caminho entre dois pontos do labirinto utilizando pilha.

```c++
bool encontrar_caminho(matriz, inicio, destino):
    inicie a pilha com inicio;
    while (pilha não estiver vazia):
        if(topo da pilha == destino):
            return true;
        else:
            if existem vizinhos abertos para a posicao topo:
                escolha um deles
                marque
                empilhe
            else
                desempilhe
    return false
```

---
# Questão 5
Faça o método reserve do vector. 

```c++
void reserve(int capacity){
    int * backup = this->data;
    if(capacity < this->size)
        this->size = capacity;
    this->capacity = capacity;
    this->data = new int[capacity];
    for(int i = 0; i < this->size; i++)
        this->data[i] = backup[i];
    delete backup;
}
```

---
# Questão 6

Faça o método recursivo para remover todos os elementos com um mesmo valor da lista. A lista é simples, sem cabeça ou rabo de marcação.

```c++
Node * remove_all(Node * node, int value){
    if(node == nullptr)
        return false;
    //deve chamar a recursão antes
    node->next = remove_all(node->next, value);
    if(node->value != value)
        return node;
    auto aux = node->next;
    delete node;
    return aux;
}


```

---
# Questão 7
Ordenação, faça o código do quicksort

```c++
void quick(vector<int>& vet, int C, int F){
    if(C >= F)
        return;
    int pivo = vet[i]; 
    int i = C;
    int j = F;   
    while(i <= j){
        while (vetor[i] < pivo) i = i + 1;
        while (vetor[j] > pivo) j = j - 1;
        if(i <= j) std::swap(i++, j--);
    }
    quick(vetor, C, j);
    quick(vetor, i, F);   
}

```

---
# Questão 8
Hash: faça o pseudocódigo da busca, inserção e remoção utilizando marcação para informar que um elemento foi removido.

```python

int find(int key){
    int ind = key % size;
    while((vet[ind].flag != VAZIO) && (vet[ind].key != key))
        ind = (ind + 1) % size;
    return ind;
}

bool remover(int key){
    int pos = find(key);
    if(vet[pos].flag == VAZIO)
        return false;
    vet[pos].flag = REMOVIDO;
    return true;
}

bool inserir(int key, int value){
    if(vet[pos].flag != VAZIO)
        return false;
    int ind = key % size;
    while((vet[ind].flag != VAZIO) && (vet[ind].flag != REMOVIDO))
        ind = (ind + 1) % size;
    vet[ind] = (Item){key, value, PREENCHIDO};
    return true;
}

```

---
# Questão 9
Faça o método clone para clonar uma árvore a partir de outra.
```c++
Node * clone(Node * node){
    if(node == nullptr) return nullptr;
    return new Node(node->value, clone(node->left), clone(node->right));
}
```

---
# Questão 10

Quando deve-se utilizar vector, list, hash e árvore. Quando cada estrutura deve ser utilizada?

- vector: quando há necessidade de acesso aleatório.
- list: quando há necessidade de inserção ou remoção no início ou no meio da lista.
- hash: armazena chave valor com acesso rápido, porém maior consumo de memória que a árvore.
- tree: impõe ordenação nos dados. 