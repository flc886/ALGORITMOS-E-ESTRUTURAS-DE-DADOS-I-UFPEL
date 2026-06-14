#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *stack1;
    int *stack2;
    int top1;
    int top2;
    int size;
} MyQueue;

MyQueue* myQueueCreate(void) {
    MyQueue *obj = malloc(sizeof(MyQueue));
    obj->size = 100;
    obj->stack1 = malloc(obj->size * sizeof(int));
    obj->stack2 = malloc(obj->size * sizeof(int));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->top1 + 1 == obj->size) {
        return;
    }

    obj->stack1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1) {
        while(obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }

    return obj->stack2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2 == -1) {
        while(obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }

    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}
