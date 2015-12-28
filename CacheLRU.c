#include <stdio.h>
#include <stdlib.h>

#define loadFactor 0.75

typedef struct {
    char nome[40];
    long int CPF;
} PERSON;

typedef struct {
    char key[40];
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
    int bucketsCount;
    int elementsCount;
    double currentLoadFactor;
} HASHMAP;

void initHashMap(HASHMAP *hashMap){
    LINKEDLIST *buckets;

    buckets = malloc(sizeof(LINKEDLIST));

    hashMap->buckets= *(LINKEDLIST *) buckets;
    hashMap->bucketsCount=1;
    hashMap->elementsCount=0;
    hashMap->currentLoadFactor=hashMap->elementsCount/hashMap->bucketsCount;

    free(buckets);
}


/*void *put(HASHMAP *hashMap, char key[40], long int value){
    //ToDo: Test if Contains(); Se sim, retorna; Se não, insere.

    //ToDo: Colocar na primeira posição,
    PERSON person;
    ENTRY entry;
    hashMap->buckets.entry

    person.nome = key[40];
    person.CPF = value;

    //ToDo: Inseriu! Ultrapassou valor de rehash? Rehash; Retorna;
    return hashMap;
}*/


int main(int argc, char *argv[]) {
    HASHMAP *hashMap;

    hashMap = malloc(sizeof(HASHMAP));
    initHashMap(hashMap);

    printf("hashMap.bucketsCount: %d\n", hashMap->bucketsCount);
    printf("hashMap.elementsCount: %d\n", hashMap->elementsCount);
    printf("hashMap.loadFactor: %f\n", hashMap->currentLoadFactor);

    printf("-- HashMap Inicializado\n");

    free(hashMap);
    return 0;
}
