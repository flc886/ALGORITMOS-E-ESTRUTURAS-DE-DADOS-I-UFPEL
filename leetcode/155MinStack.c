#include <stdlib.h>

typedef struct {
    int *dados;
    int *mins;
    int topo;
    int capacidade;
} MinStack;

MinStack* minStackCreate(void) {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->capacidade = 1000;
    obj->dados = malloc(obj->capacidade * sizeof(int));
    obj->mins = malloc(obj->capacidade * sizeof(int));
    obj->topo = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->dados[++obj->topo] = val;
    if(obj->topo == 0 || val < obj->mins[obj->topo - 1]) {
        obj->mins[obj->topo] = val;
    }
    else {
        obj->mins[obj->topo] = obj->mins[obj->topo - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->topo--;
}

int minStackTop(MinStack* obj) {
    return obj->dados[obj->topo];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->topo];
}

void minStackFree(MinStack* obj) {
    free(obj->dados);
    free(obj->mins);
    free(obj);
}
