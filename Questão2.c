#include <stdlib.h>
#include <stdio.h>

typedef struct NO{
    int chave;
    struct NO * esq;
    struct NO * dir;
}No;

No * raiz = NULL;
void pre(No *pt){
    printf("%d\n", pt->chave);
    if (pt->esq != NULL){
        pre(pt->esq);
    }
    if (pt->dir != NULL){
        pre(pt->dir);
    }
}

void pos(No *pt){
    if (pt->esq != NULL){
        pos(pt->esq);
    }
    if (pt->dir != NULL){
        pos(pt->dir);
    }
    printf("%d\n", pt->chave);
}

int maior(No * aux){
    if(aux != NULL){
        if (aux->dir == NULL)
            return aux->chave;
        if (aux->chave > maior(aux->dir))
            return aux->chave;
        else if(aux->chave < maior(aux->dir))
            return maior(aux->dir);
    }
}

float media(No * aux){
    if(aux != NULL){
        if(aux == raiz)
            return((aux->chave + media(aux->dir) + media(aux->esq))/15);
        else
            return(aux->chave + media(aux->dir) + media(aux->esq));
    }
    return 0;
}

void add(int chave){
    No * aux = raiz;
    No * novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;

    if (raiz == NULL){
        raiz = novo;
    }else{
        while (1) {
            if (chave < aux->chave){
                if (aux->esq == NULL) {
                    aux->esq = novo;
                    break;
                }
                aux = aux->esq;
            } else if (chave > aux->chave){
                if (aux->dir == NULL) {
                    aux->dir = novo;
                    break; 
                }
                aux = aux->dir;
            } else {
                free(novo); 
                break; 
            }
        }
    }
}


int main()
{
    add(10);
    add(16);
    add(2);
    add(8);
    add(4);
    add(19);
    add(48);
    add(145);
    add(47);
    add(14);
    add(84);
    add(43);
    add(12);
    add(48);
    pre(raiz);
    pos(raiz);
    No * aux = raiz;
    int x = maior(aux);
    float y = media(aux);
    printf("maior valor: %d\n", x);
    printf("media: %.2f", y);
    
    
    return 0;
}
