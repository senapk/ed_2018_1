#include <cstdio>
#include <vector>
using namespace std;

void quick(vector<int>& vet, int C, int F){
    if(C >= F)
        return;
    int pivo = vet[C]; 
    int i = C;
    int j = F;   
    while(i <= j){
        while (vet[i] < pivo) i = i + 1;
        while (vet[j] > pivo) j = j - 1;
        if(i <= j) swap(vet[i++], vet[j--]);
    }
    quick(vet, C, j);
    quick(vet, i, F);   
}

int main(){
    vector<int> vet {3, 4, 2, 5, 6, 7, 8, 1, 2, 9, 0, 1, 3};
    quick(vet, 0, vet.size() - 1);
    for(auto x : vet) printf("%d ", x);
    puts("");
    return 0;
}