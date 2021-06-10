#include <stdio.h>
#include <stdlib.h>
#include "TorreDeHanoi.h"

// typedef struct disco Disco;
// struct disco{
//     Disco *next; //ponteiro para o proximo disco
//     char tamDisco; //tamanho do disco
// };

// typedef struct pino Pino;
// struct pino{
//     Disco *topo; //ponteiro para o topo da pilha
//     char numDiscos; //quantidade de discos
// };

Pino** criarPinos(int n) {
    int i;
    
    Pino** pinos = malloc(sizeof(Pino*) * n);
    for (i = 0; i < n; i++) {
        pinos[i] = criarPino();
    }

    return pinos;
}
int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino) {
    if (pinoOrigem < 0 || pinoOrigem > 4) return 0;
    if (pinoDestino < 0 || pinoDestino > 4) return 0;
    if (pinos[pinoOrigem]->numDiscos == 0) return 0;
    if (pinos[pinoDestino]->numDiscos != 0) {
        if (pinos[pinoOrigem]->topo->tamDisco > pinos[pinoDestino]->topo->tamDisco) {
            return 0;
        }
    }
    Disco *disco_movido = pop(pinos[pinoOrigem]);
    push(pinos[pinoDestino], disco_movido);
    return 1;
}
void imprimir(Pino **pinos, int numPinos, int numDiscos) {
    printf("\n");

    int i, j;
    for (i = 0; i < numPinos; i++) {
        Pino *pino_atual = pinos[i];
        for (j = 0; j < numDiscos - pino_atual->numDiscos; j++) {
            printf("%*s\n", numDiscos+2, "|");
        }
        Disco *disco_atual = pino_atual->topo;
        while (disco_atual != NULL) {
            for (j = 0; j < (numDiscos+1) - disco_atual->tamDisco; j++) {
                printf(" ");
            }
            for (j = 0; j < disco_atual->tamDisco; j++) {
                printf("_");
            }
            printf("|");
            for (j = 0; j < disco_atual->tamDisco; j++) {
                printf("_");
            }
            printf("\n");
            disco_atual = disco_atual->next;
        }
        for (j = 0; j < 2*numDiscos + 3; j++) {
            if (j == numDiscos+1) {
                printf("|");
            } else  {
                printf("_");
            }
        }
        printf("\n\n");
        printf("%*d", numDiscos+2, i+1);
        printf("\n\n");
    }
}
Pino* criarPino() {
    Pino *novo_pino = malloc(sizeof(Pino));
    novo_pino->numDiscos = 0;
    novo_pino->topo = NULL;
    return novo_pino;
}
Disco* criarDisco(int tam) {
    Disco *novo_disco = malloc(sizeof(Disco));
    novo_disco->tamDisco = tam;
    novo_disco->next = NULL;
    return novo_disco;
}
Disco* pop(Pino *pino) {
    Disco *disco_pop = pino->topo;
    pino->topo = pino->topo->next;
    pino->numDiscos = pino->numDiscos - 1;
    return disco_pop;
}
void push(Pino *pino, Disco *disco) {
    disco->next = pino->topo;
    pino->topo = disco;
    pino->numDiscos = pino->numDiscos + 1;
}
void excluirPino(Pino *pino) {
    while (pino->topo != NULL) {
        Disco *i = pino->topo->next;
        free(pino->topo);
        pino->topo = i;
    }

    free(pino);
}
