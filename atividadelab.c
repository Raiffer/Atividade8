#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario{
    int num_fil;
    int code;
    char * cargo;
    int slr;
    struct fun*prox;
}fun;

typedef struct filial{
    int num;
    char*nome;
    int grt;
    int vnd;
    struct filial*prox;
    struct fun*proxf;
}fil;

int numf = 0

fil * incio = NULL;

void add_fil(int num, char*nome){
    
    if(numf < 4){
        
        fil*novo = malloc(sizeof(fil));
        novo->num=num;
        novo->nome=nome;
        novo->grt=NULL;
        novo->vnd=NULL;
        numf++;
        
    }else if(numf >= 4){
        printf("Numero maximo de filiais exedido.\n");
    }
}

void add(int num_fil, int code, char*cargo, int slr){
    
    fun*novo=malloc(sizeof(fun));
    novo->num_fil=num_fil;
    
    fil*aux=incio;
    do{
        if (aux == NULL){
            break;
        }
        aux=aux->prox;
    }while(aux->num != num_fil);
    
    if(aux==NULL){
        printf("Filial nao encontrada.\n");
    }
}










