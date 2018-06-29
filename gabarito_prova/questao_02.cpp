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

    //esse laco vai imprimir o caminho inverso até o comeco
    //(l:1,c:3)(l:2,c:3)(l:2,c:2)(l:3,c:2)(l:3,c:1)(l:4,c:1)(l:4,c:0)
    for(int l = 0; l < NL; l++)
        queimar(mat, 0, l);
    return 0;
}