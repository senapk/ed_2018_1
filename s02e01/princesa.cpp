#include <stdio.h>
#include <iostream>
#include <list>

void pop_front(int vet[], int * qtd){
	for(int i = 0; i < *qtd - 1; i++)
		vet[i] = vet[i + 1];
	*qtd -= 1;
}

void push_back(int vet[], int * qtd, int value){
	vet[*qtd] = value;
	*qtd += 1;
}

void rodar(std::list<int> &lista){
	lista.push_back(lista.front());
	lista.pop_front();
}

int main(){
	int qtd = 0;
	scanf("%i", &qtd);
	
	int primeiro = 0;
	std::cin >> primeiro;
	
	std::list<int> lista;
	for(int i = 1; i <= qtd; i++)
		lista.push_back(i);

	while(lista.front() != primeiro)
		rodar(lista);
	
	while(lista.size() > 1){
		rodar(lista);
		lista.pop_front();
	}
}
