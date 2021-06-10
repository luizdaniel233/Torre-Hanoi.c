typedef struct disco Disco;
struct disco{
    Disco *next; //ponteiro para o proximo disco
    char tamDisco; //tamanho do disco
};

typedef struct pino Pino;
struct pino{
    Disco *topo; //ponteiro para o topo da pilha
    char numDiscos; //quantidade de discos
};

Pino** criarPinos(int n);
int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);
Pino* criarPino();
Disco* criarDisco(int tam);
Disco* pop(Pino *pino);
void push(Pino *pino, Disco *disco);
void excluirPino(Pino *pino);
