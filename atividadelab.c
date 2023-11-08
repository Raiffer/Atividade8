#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario{
    int num_fil;
    int code;
    char * cargo;
    int slr;
    struct funcionario*prox;
}fun;

typedef struct filial{
    int num;
    char*nome;
    int grt;
    int vnd;
    struct filial*prox;
    fun*proxf;
}fil;

int numf = 0;

fil * inicio = NULL;

void add_fil(int num, char*nome){
    
    if(numf < 4){
        
        fil*novo = malloc(sizeof(fil));
        novo->num=num;
        novo->nome=nome;
        novo->grt=0;
        novo->vnd=0;
        numf++;
        
        if(inicio == NULL)
            inicio = novo;
        else{
            novo->prox=inicio;
            inicio=novo;
        }
        
    }else if(numf >= 4){
        printf("Numero maximo de filiais exedido.\n");
    }
}

void add_fun(int num_fil, int code, char*cargo, int slr){
    
    fun*novo=malloc(sizeof(fun));

    fil*aux=inicio;
    do{
        if (aux == NULL){
            break;
        }
        aux=aux->prox;
    }while(aux->num != num_fil);
    
    novo->num_fil=num_fil;
    
    if(aux==NULL){
        printf("Filial nao encontrada.\n");
        free(novo);
    }else{
        
        fun * aus = aux->proxf;
        while(aus != NULL){
            if (aus->code == code){
                break;
            }
            aus=aus->prox;
        }
        if (aus->code = code){
            
            printf("Codigo ja utilizado.\n");
            free(novo);
        }else{
            novo->code=code;
        
            if (aux->grt >= 1 || cargo== "G"){
                
                printf("Numero maximo de gerentes exedido.\n");
                free(novo);
                
            }else if(aux->vnd >= 4 || cargo== "V"){
                
                printf("Numero maximo de vendedores exedido.\n");
                free(novo);
                
            }else{
                
                if(cargo == "G"){
                
                    novo->cargo = cargo;
                    aux->grt++;
                
                }else if(cargo == "V"){
                
                    novo->cargo = cargo;
                    aux->vnd++;
                
                }
            
                novo->slr = slr;
                novo->prox = NULL;
            
                if (aux->proxf == NULL)
                    aux->proxf = novo;
                else{
                    novo->prox = aux->proxf;
                    aux->proxf = novo;
                }
            }  
        }

    }
}

int main(){
    while(1){
        int x = 0;
        printf("O que deseja fazer?\n");
        printf("1 - Adcionar Filial.\n");
        printf("2 - Adcionar Funcionario.\n");
        printf("3 - Visualizar.\n");
        printf("0 - Sair.\n");
        printf("Comando: ");
        scanf("%d", &x);
        if (x == 0){
            
            printf("Finalizando...\n");
            break;
            
        }else if(x == 1){
            
            int num;
            char * nome;
            printf("Digite o Numero da Filial: ");
            scanf("%d", &num);
            printf("Digite o nome da Filial: ");
            scanf("%s", &nome);
            
            add_fil(num, nome);
        }
        printf("\n");
    }
}








