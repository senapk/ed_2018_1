#include <cstdio>

const char * vogais = "aeiouAEIOU";

bool isVogal(char c){
    for(int i = 0; i < 10; i++)
        if(vogais[i] == c){
            printf("%c", c);
            return true;
        }
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

