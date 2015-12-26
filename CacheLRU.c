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

void *initHashMap(HASHMAP *hashMap, int initialSize, double loadFactor){
    double sizeToRehash = initialSize * loadFactor;
    LINKEDLIST *buckets;

    buckets = malloc(sizeof(LINKEDLIST)*initialSize);

    hashMap->buckets= *(LINKEDLIST *) buckets;
    hashMap->currentSize=0;
    hashMap->initialSize=initialSize;
    hashMap->loadFactor=loadFactor;
    hashMap->sizeToRehash=sizeToRehash;

    return hashMap;
}

//ToDo: Put deverá implementar o rehash


int main(int argc, char *argv[]) {
    int initialSize;
    double loadFactor;
    HASHMAP *hashMap;

    if(argc<3){
        printf("Usage: %s <initialSize> <loadFactor> \n", argv[0]);
        printf("InitialSize - default: 16 \nloadFactor - default: 0.75\n");
        exit(EXIT_FAILURE);
    }

    initialSize = atoi(argv[1]);
    loadFactor = atof(argv[2]);

    hashMap = malloc(sizeof(HASHMAP));
    initHashMap(hashMap, initialSize, loadFactor);

    printf("hashMap.currentSize: %d\nhashMap.initialSize: %d\nhashMap.loadFactor: %f\nhashMap.sizeToRehash: %f\n",
           hashMap->currentSize, hashMap->initialSize, hashMap->loadFactor, hashMap->sizeToRehash
    );

    printf("-- HashMap Inicializado\n");

    free(hashMap);
    return 0;
}