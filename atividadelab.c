#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int num_fil;
    int code;
    char cargo;
    int slr;
    struct funcionario* prox;
} fun;

typedef struct filial {
    int num;
    char *nome;
    int grt;
    int vnd;
    struct filial* prox;
    fun* proxf;
} fil;

int numf = 0;

fil* inicio = NULL;

void add_fil(int num, char *nome) {
    if (numf < 4) {
        fil* novo = malloc(sizeof(fil));
        novo->num = num;
        novo->nome = strdup(nome);
        novo->grt = 0;
        novo->vnd = 0;
        numf++;

        if (inicio == NULL)
            inicio = novo;
        else {
            novo->prox = inicio;
            inicio = novo;
        }
    } else {
        printf("Número máximo de filiais excedido.\n");
    }
}

void add_fun(int num_fil, int code, char cargo, int slr) {
    fun* novo = malloc(sizeof(fun));
    fil* aux = inicio;
    
    while (aux != NULL && aux->num != num_fil) {
        aux = aux->prox;
    }
    
    if (aux == NULL) {
        printf("Filial não encontrada.\n");
        free(novo);
    } else {
        fun* aus = aux->proxf;
        while (aus != NULL) {
            if (aus->code == code) {
                printf("Código já utilizado.\n");
                free(novo);
                return;
            }
            aus = aus->prox;
        }
        
        novo->num_fil = num_fil;
        novo->code = code;
        
        if (cargo == 'G') {
            if (aux->grt >= 1) {
                printf("Número máximo de gerentes excedido.\n");
                free(novo);
                return;
            }
            novo->cargo = 'G';
            aux->grt++;
        } else if (cargo == 'V') {
            if (aux->vnd >= 4) {
                printf("Número máximo de vendedores excedido.\n");
                free(novo);
                return;
            }
            novo->cargo = 'V';
            aux->vnd++;
        }
        
        novo->slr = slr;
        novo->prox = NULL;
        
        if (aux->proxf == NULL)
            aux->proxf = novo;
        else {
            novo->prox = aux->proxf;
            aux->proxf = novo;
        }
    }
}

void tabela(){
    fil* aux = inicio;
    fun* aju = inicio->proxf;
    int 
    while(aux != NULL){
        while(aju != NULL){
            
        }
    }
}

int main() {
    while (1) {
        int x = 0;
        printf("O que deseja fazer?\n");
        printf("1 - Adicionar Filial.\n");
        printf("2 - Adicionar Funcionário.\n");
        printf("3 - Visualizar.\n");
        printf("0 - Sair.\n");
        printf("Comando: ");
        scanf("%d", &x);
        if (x == 0) {
            printf("Finalizando...\n");
            break;
        } else if (x == 1) {
            int num;
            char nome[50];
            printf("Digite o Número da Filial: ");
            scanf("%d", &num);
            printf("Digite o nome da Filial: ");
            scanf("%s", nome); 
            add_fil(num, nome);
        } else if (x == 2) {
            int num_fil, code, slr;
            char cargo;
            printf("Digite o Número da Filial: ");
            scanf("%d", &num_fil);
            printf("Digite o código do funcionário: ");
            scanf("%d", &code);
            printf("Digite o cargo (G para gerente, V para vendedor): ");
            scanf(" %c", &cargo);  
            printf("Digite o salário: ");
            scanf("%d", &slr);
            add_fun(num_fil, code, cargo, slr);
        }
        printf("\n");
    }

    return 0;
}
