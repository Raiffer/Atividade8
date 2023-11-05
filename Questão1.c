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

int media(no * aux){
    if(aux != NULL){
        if(aux == inicio)
            return((aux->num + media(aux->prox))/15);
        else if(aux->prox != NULL)
            return(aux->num + media(aux->prox));
        else 
            return aux->num;
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
    int x, y;
        
    add(1);
    add(2);
    add(3);
    add(5);
    add(4);
    add(7);
    add(9);
    add(6);
    add(8);
    add(10);
    add(12);
    add(11);
    add(14);
    add(13);
    add(15);
    
    no*aux = inicio;
    x = maior(aux);
    y = media(aux);
    printf("Maior Valor: %d\n", x);
    printf("Média: %d", y);
    
    return 0;
}