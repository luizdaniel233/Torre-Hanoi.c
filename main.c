#include <stdio.h>
#include <stdlib.h>
#include "TorreDeHanoi.h"

int checaVitoria(Pino **pinos, int numPinos, int numDiscos) {
    int i, k, em_ordem;
    for (i = 1; i < numPinos; i++) {
        Pino *pino_atual = pinos[i];
        if (pino_atual->numDiscos == numDiscos) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int i, n = 2, m = 2;
    int pino_origem = 2, pino_destino = 2;
    int total_jogadas = 0;

    while (n < 3 || n > 5) {
        printf("Insira a quantidade de pinos: [3...5] ");
        scanf("%d", &n);
        if (n < 3 || n > 5) {
            printf("Entrada invalida\n");
        }
    }

    while (m < 3 || m > 5) {
        printf("Insira a quantidade de discos: [3...5] ");
        scanf("%d", &m);
        if (m < 3 || m > 5) {
            printf("Entrada invalida\n");
        }
    }

    Pino** pinos = criarPinos(n);

    for (i = m; i > 0; i--) {
        Disco *novo_disco = criarDisco(i);
        push(pinos[0], novo_disco);
    }

    while (!checaVitoria(pinos, n, m)) {
        imprimir(pinos, n, m);
        printf("Insira os pinos de origem e destino: ");
        scanf("%d %d", &pino_origem, &pino_destino);
        if (pino_origem > n || pino_destino > n || !moverDisco(pinos, pino_origem-1, pino_destino-1)) {
            printf("Movimento invalido.\n");
        } else {
            total_jogadas = total_jogadas + 1;
        }
    }

    imprimir(pinos, n, m);
    printf("PARABENS VOCE CONSEGUIU\n");
    printf("TOTAL DE JOGADAS: %d\n", total_jogadas);
    /*
    for (i = 0; i < n; i++) {
        excluirPino(pinos[i]);
        free(pinos);
    }
    */
   free(pinos);
    return 0;
}
