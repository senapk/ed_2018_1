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

