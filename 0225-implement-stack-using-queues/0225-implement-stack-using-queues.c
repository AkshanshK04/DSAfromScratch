
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));

    obj->capacity = 10000;
    obj->arr = malloc(obj->capacity * sizeof(int));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;

    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->arr[obj->rear++] = x;
    obj->size++;

    for (int i = 0; i < obj->size - 1; i++) 
    {
        obj->arr[obj->rear++] = obj->arr[obj->front++];
    }
}

int myStackPop(MyStack* obj) {
    obj->size--;
    return obj->arr[obj->front++];
}

int myStackTop(MyStack* obj) {
    return obj->arr[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->arr);
    free(obj);
}
