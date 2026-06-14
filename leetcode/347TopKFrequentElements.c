#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} Pair;

int comparar(const void *a, const void *b) {
    Pair *x = (Pair*) a;
    Pair *y = (Pair*) b;

    if(x->freq < y->freq) return 1;
    if(x->freq > y->freq) return -1;
    return 0;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Pair *pares = malloc(numsSize * sizeof(Pair));
    int qtd = 0;

    for(int i = 0; i < numsSize; i++) {
        int valor = nums[i];
        int achou = -1;

        for(int j = 0; j < qtd; j++) {
            if(pares[j].val == valor) {
                achou = j;
                break;
            }
        }

        if(achou == -1) {
            pares[qtd].val = valor;
            pares[qtd].freq = 1;
            qtd++;
        }
        else {
            pares[achou].freq++;
        }
    }

    qsort(pares, qtd, sizeof(Pair), comparar);

    int *resposta = malloc(k * sizeof(int));
    for(int i = 0; i < k; i++){
        resposta[i] = pares[i].val;
    }

    *returnSize = k;
    free(pares);
    return resposta;
}
