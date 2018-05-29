#include <iostream>
#include <ctime>
#include <cstdlib> //rand
#include "libs/ed_sort.h"

using namespace std;

//cores rgbcymkw
//red, green, blue, cyan, yellow, magenta, black, white

void swap_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){ 
            view_show(vet, {i, j}, "yg");
            if(vet[j] < vet[i]){
                std::swap(vet[i], vet[j]);
                view_show(vet, {i, j}, "yg");
            }
        }
    }
}

void selection_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        int imenor = i;
        view_set_faixa(i, vet.size() - 1);
        for(int j = i + 1; j < (int) vet.size(); j++){
            view_show(vet, {i, j, imenor}, "ygr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor}, "ygr");
            }
        }
        std::swap(vet[imenor], vet[i]);
    }
}

void reverse_minimum_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; ultimo--){
        int imaior = ultimo;
        for(int j = 0; j < ultimo; j++){
            view_show(vet, {j, imaior, ultimo}, "ygr");
            if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {j, imaior, ultimo}, "ygr");
            }
        }
        std::swap(vet[imaior], vet[ultimo]);
    }
}

void palma_sort(vector<int>& vet){
    int ultimo = vet.size() - 1;
    for(int i = 0; i <= ultimo; i++, ultimo--){
        int imaior = i;
        int imenor = i;
        view_set_faixa(i, ultimo);
        for(int j = i; j <= ultimo; j++){
            view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            if(vet[j] < vet[imenor]){
                imenor = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
            else if(vet[j] > vet[imaior]){
                imaior = j;
                view_show(vet, {i, j, imenor, imaior, ultimo}, "rgyyr");
            }
        }
        std::swap(vet[imenor], vet[i]);
        if(imaior == i)
            imaior = imenor;
        std::swap(vet[imaior], vet[ultimo]);
        view_show(vet, {i, imenor, imaior, ultimo}, "ryyr");
    }
}

void bubble_sort(vector<int>& vet){
    for(int i = vet.size(); i > 0; i--){
        for(int j = 0; j < i - 1; j++){
            view_show(vet, {i, j, j + 1}, "rgy");
            if(vet[j] > vet[j + 1]){
                std::swap(vet[j], vet[j + 1]);
                view_show(vet, {i, j, j + 1}, "rgy");
            }
        }

    }
}

void insertion_sort(vector<int>& vet){
    for(int i = 1; i < (int) vet.size(); i++){
        for(int j = i; j > 0; j--){
            view_show(vet, {i, j, j - 1}, "rgy");
            if(vet[j] < vet[j - 1]){
                std::swap(vet[j], vet[j - 1]);
                view_show(vet, {i, j, j - 1}, "ryg");
            }else{
                break;
            }
        }

    }
}

//intervalos fechados [C, F]
#define qshow view_show(vet, {C, F, i, j}, "rgby")
void quick_sort(vector<int> & vet, int C, int F){
    if(C >= F)
        return;
    int pivo = vet[C];
    int i = C;
    int j = F;
    while(i <= j){
        while(vet[i] < pivo)
            i++;
        while(vet[j] > pivo)
            j--;
        if(i <= j)
            std::swap(vet[i++], vet[j--]);
    }
    quick_sort(vet, C, j);
    quick_sort(vet, i, F);
}

void merge(vector<int>& vet, int a, int b, int c){
    int i = a;
    int j = b;
    vector<int> vaux;
    vaux.reserve(c - a);
    while((i < b) && (j < c)){ //comparar particoes
        if(vet[i] < vet[j])
            vaux.push_back(vet[i++]);
        else
            vaux.push_back(vet[j++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    while(i < b){
        vaux.push_back(vet[i++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    while(j < c){
        vaux.push_back(vet[j++]);
        view_show(vet, {a, b, c, i, j}, "rgbyc");
    }
    for(int i = 0; i < (int) vaux.size(); i++){
        vet[a + i] = vaux[i];
        view_show(vet, {a + i}, "r");
    }
}

//particao [C, F[
void mergesort(vector<int>& vet, int a, int c){
    if(c == a + 1)
        return;
    int b = (a + c)/2;
    mergesort(vet, a, b);
    mergesort(vet, b, c);
    merge(vet, a, b, c);
}

void test_sort(vector<int>& vet){
    for(int i = 0; i < (int) vet.size() - 1; i++){
        if(vet[i] <= vet[i + 1])
            view_show(vet, {i, i + 1}, "gg");
        else{
            view_show(vet, {i, i + 1}, "rr");
            view_lock();
        }
    }
}

int main(){
    srand(time(NULL));

    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

//    view_set_dot();
    view_set_bar();
//    view_set_faixa(0, qtd - 1);

    //swap_sort(vet);
    //selection_sort(vet);
    //palma_sort(vet);
    //bubble_sort(vet);
    //insertion_sort(vet);
    //quick_sort(vet, 0, vet.size() - 1);
    mergesort(vet, 0, vet.size());
//    reverse_minimum_sort(vet);

    test_sort(vet);
    view_lock();
    return 0;
}





















