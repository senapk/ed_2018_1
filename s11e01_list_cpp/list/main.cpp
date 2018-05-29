#include <iostream>
#include <vector>
#include <list>
#include <set> // TreeSet
#include <unordered_set> //HashSet
#include <algorithm>
using namespace std;

int main()
{

    vector<int> vet = {9, 4, 3, 2, 5, 6, 1};

    for(int i = 0; i < (int) vet.size(); i++)
        cout << vet[i] << " ";
    cout << endl;
    for(auto elem : vet)
        cout << elem << " ";
    cout << endl;

    //acesso sequencial
    list<int> lista = {9, 4, 3, 2, 5, 6, 1};
    for(auto elem : lista)
        cout << elem << " ";
    cout << endl;
    auto it = std::find(lista.begin(), lista.end(), 2);
    
    if(it == lista.end())
        cout << "2 nao existe" << endl;
	else
		cout << "2 existe" << endl;
	cout << *it << endl;
	
	unordered_set<int> conj;
	conj.insert(9);
	conj.insert(5);
	conj.insert(7);
	conj.insert(8);
	conj.insert(5);
	conj.insert(8);
	conj.insert(9);
	for(auto elem : conj)
		cout << elem << " ";
	
	
    return 0;
}
