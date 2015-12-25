#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int CPF;
} PERSON;

typedef struct {
    int key;
    int *next;
    PERSON person;
} ENTRY;

typedef struct {
    int *first;
    ENTRY entry;
    int *last;
} LINKEDLIST;

typedef struct {
    LINKEDLIST buckets;
    int currentSize;
    int initialSize;
    double loadFactor;
    double sizeToRehash; // initialSize * loadFactor
} HASHMAP;

HASHMAP initHashMap(int initialSize, double loadFactor){
    HASHMAP hashMap;
    double sizeToRehash = initialSize * loadFactor;
    int currentSize = 0;
    LINKEDLIST buckets;

    hashMap.buckets=buckets;
    hashMap.currentSize=currentSize;
    hashMap.initialSize=initialSize;
    hashMap.loadFactor=loadFactor;
    hashMap.sizeToRehash=sizeToRehash;

    return hashMap;
}

//ToDo: Put deverá implementar o rehash


int main(int argc, char *argv[]) {
    int initialSize;
    double loadFactor;
    HASHMAP hashMap;

    if(argc<3){
        printf("Usage: %s <initialSize> <loadFactor> \n", argv[0]);
        printf("InitialSize - default: 16 \nloadFactor - default: 0.75\n");
        exit(EXIT_FAILURE);
    }

    initialSize = atoi(argv[1]);
    loadFactor = atof(argv[2]);

    hashMap = initHashMap(initialSize, loadFactor);

    printf("hashMap.currentSize: %d\nhashMap.initialSize: %d\nhashMap.loadFactor: %f\nhashMap.sizeToRehash: %f\n",
           hashMap.currentSize, hashMap.initialSize, hashMap.loadFactor, hashMap.sizeToRehash
    );

    printf("-- HashMap Inicializado\n");

    return 0;
}