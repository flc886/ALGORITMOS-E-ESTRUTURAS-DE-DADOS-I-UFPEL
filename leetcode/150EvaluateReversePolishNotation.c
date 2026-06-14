#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize){
    int *pilha = malloc(tokensSize * sizeof(int));
    int topo = -1;

    for(int i = 0; i < tokensSize; i++){
        char *t = tokens[i];

        if(strcmp(t, "+") == 0){
            int b = pilha[topo--];
            int a = pilha[topo--];
            pilha[++topo] = a + b;
        }
        else if(strcmp(t, "-") == 0){
            int b = pilha[topo--];
            int a = pilha[topo--];
            pilha[++topo] = a - b;
        }
        else if(strcmp(t, "*") == 0){
            int b = pilha[topo--];
            int a = pilha[topo--];
            pilha[++topo] = a * b;
        }
        else if(strcmp(t, "/") == 0){
            int b = pilha[topo--];
            int a = pilha[topo--];
            pilha[++topo] = a / b;
        }
        else {
            pilha[++topo] = atoi(t);
        }
    }

    int resposta = pilha[topo];
    free(pilha);
    return resposta;
}
