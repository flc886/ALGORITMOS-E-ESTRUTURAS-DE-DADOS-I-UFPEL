#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
    int k;
} KthLargest;

int kthLargestAdd(KthLargest* obj, int val);

void subir(int *heap, int i) {
    while(i > 1) {
        int pai = i / 2;
        if(heap[pai] <= heap[i]) break;
        int aux = heap[pai];
        heap[pai] = heap[i];
        heap[i] = aux;
        i = pai;
    }
}

void descer(int *heap, int i, int size) {
    while(2 * i <= size) {
        int filho = 2 * i;
        if(filho + 1 <= size && heap[filho + 1] < heap[filho]) {
            filho++;
        }

        if(heap[i] <= heap[filho]) break;

        int aux = heap[i];
        heap[i] = heap[filho];
        heap[filho] = aux;
        i = filho;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = malloc(sizeof(KthLargest));
    obj->capacity = numsSize + k + 5;
    obj->heap = malloc((obj->capacity + 1) * sizeof(int));
    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size < obj->k) {
        obj->heap[++obj->size] = val;
        subir(obj->heap, obj->size);
    }
    else if(val > obj->heap[1]) {
        obj->heap[1] = val;
        descer(obj->heap, 1, obj->size);
    }

    return obj->heap[1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
