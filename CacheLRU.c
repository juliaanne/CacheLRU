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
    hashMap->elementsCount=1;
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

int main(int argc, char *argv[]) {
    HASHMAP *hashMap = malloc(sizeof(HASHMAP));
    initHashMap(hashMap);
    printf("-- HashMap Inicializado --\n");

    long long int key = 20677346522;
    PERSON person;
    strcpy(person.nome, "Julia Anne");
    person.idade=22;
    if(put(hashMap, key, person)){
        printf("-- Person %s Inserido --\n", person.nome);
    } else printf("-- ERRO DE INSERÇÃO --\n");

    printf("%d\n", contains(hashMap,key));

    /*
    printf("%d\n",hashCode(20677346522));   10
    printf("%d\n",hashCode(88272078481));   1
    printf("%d\n",hashCode(53604310598));   6
    printf("%d\n",hashCode(85779623341));   13
    printf("%d\n",hashCode(19245264173));   13*/

    free(hashMap);
    return 0;
}
