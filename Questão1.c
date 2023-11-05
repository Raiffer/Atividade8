#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int num;
    struct NO * prox;
}no;

no * inicio = NULL;

int maior(no * aux){
    if(aux != NULL){
        if (aux->prox == NULL)
            return aux->num;
        if (aux->num > maior(aux->prox))
            return aux->num;
        else if(aux->num < maior(aux->prox))
            return maior(aux->prox);
    }
}

void add(int num){
    no * novo = malloc(sizeof(no));
    novo->num = num;
    novo->prox = NULL;
    
    if (inicio == NULL)
        inicio = novo;
    else{
        novo->prox = inicio;
        inicio = novo;
    }
}

int main(){
    int x;
    
    add(3);
    add(4);
    add(2);
    add(5);
    add(99);
    add(32);
    add(1);
    add(7);
    add(102);
    add(10);
    add(235);
    add(76);
    add(0);
    add(132);
    add(54);
    
    no*aux = inicio;
    x = maior(aux);
    printf("%d", x);
    
    return 0;
}