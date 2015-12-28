#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define loadFactor 0.75
#define initialSize 16

typedef struct _P{
    char nome[40];
    int idade;
} PERSON;

typedef struct _E{
    long long int key; //CPF
    struct _E *prev;
    struct _E *next;
    PERSON person;
} ENTRY;

typedef struct _LL{
    ENTRY *first;
    ENTRY *last;
} LINKEDLIST;

typedef struct _HM{
    LINKEDLIST buckets[initialSize];
    int bucketsCount;
    int elementsCount;
    float currentLoadFactor;
} HASHMAP;

void *initHashMap(HASHMAP *hashMap){
    hashMap->bucketsCount=initialSize;
    hashMap->elementsCount=0;
    hashMap->currentLoadFactor=hashMap->elementsCount/hashMap->bucketsCount;

    return hashMap;
}

int hashCode(long long int key){
    int code = key % initialSize;
    //printf("%d\n", code);
    return code;
}

int contains(HASHMAP *hashMap, long long int key){
    int code = hashCode(key);
    ENTRY *current = malloc(sizeof(ENTRY));
    current = hashMap->buckets[code].first;

    if(current==NULL) return 0;

    while(1){
        if(current->key==key){
            // Se contém, devo atualizar para mais recente
            hashMap->buckets[code].first->prev=current;
            current->next=hashMap->buckets[code].first;
            current->prev=NULL;
            hashMap->buckets[code].first=current;
            return 1;
        }
        if(current->next==NULL) break;
        current = current->next;
    }

    return 0;
}


int put(HASHMAP *hashMap, long long int key, PERSON person){

    int code = hashCode(key);

    ENTRY *entry = malloc(sizeof(ENTRY));
    entry->key=key;
    entry->next=NULL;
    entry->person=person;
    hashMap->buckets[code].first=entry;
    hashMap->buckets[code].last=NULL;

    return 1;
}

void populando(HASHMAP *hashMap){
    long long int key1 = 20677346522; // 10
    long long int key2 = 88272078481; // 1
    long long int key3 = 53604310598; // 6
    long long int key4 = 85779623341; // 13
    long long int key5 = 19245264173; // 13

    PERSON person1;
    strcpy(person1.nome, "Julia Anne");
    person1.idade=22;
    put(hashMap, key1, person1)? printf("-- Person %s Inserido --\n", person1.nome): printf("-- ERRO DE INSERÇÃO --\n");

    PERSON person2;
    strcpy(person2.nome, "Eliza Alves");
    person2.idade=15;
    put(hashMap, key2, person2)? printf("-- Person %s Inserido --\n", person2.nome): printf("-- ERRO DE INSERÇÃO --\n");

    PERSON person3;
    strcpy(person3.nome, "Ed de Souza");
    person3.idade=55;
    put(hashMap, key3, person3)? printf("-- Person %s Inserido --\n", person3.nome): printf("-- ERRO DE INSERÇÃO --\n");

    PERSON person4;
    strcpy(person4.nome, "Afonso Carvalho");
    person4.idade=22;
    put(hashMap, key4, person4)? printf("-- Person %s Inserido --\n", person4.nome): printf("-- ERRO DE INSERÇÃO --\n");

    PERSON person5;
    strcpy(person5.nome, "Carina Camacchi");
    person5.idade=27;
    put(hashMap, key5, person5)? printf("-- Person %s Inserido --\n", person5.nome): printf("-- ERRO DE INSERÇÃO --\n");

}


int main(int argc, char *argv[]) {
    HASHMAP *hashMap = malloc(sizeof(HASHMAP));
    initHashMap(hashMap);
    printf("-- HashMap Inicializado --\n");

    populando(hashMap);
    printf("-- HashMap Populado --\n");

    printf("Antes de consultar\n%lld\n", hashMap->buckets[13].first->key);
    printf("%d\n", contains(hashMap,85779623341));
    printf("Após consultar\n%lld\n", hashMap->buckets[13].first->key);

    free(hashMap);
    return 0;
}

