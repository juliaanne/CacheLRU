#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define loadFactor 0.75
#define initialSize 8

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
    double currentLoadFactor;
} HASHMAP;

void *initHashMap(HASHMAP *hashMap){
    hashMap->bucketsCount=initialSize;
    hashMap->elementsCount=0;
    hashMap->currentLoadFactor=(float) hashMap->elementsCount/(float) hashMap->bucketsCount;

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

    if(current==NULL) return 0; // Bucket vazio
    if(current->key==key) return 1;

    while(1){
        if(current->key==key){
            // Se contém, devo atualizar para mais recente
            if(current->next==NULL) { hashMap->buckets[code].last = current->prev; }
            else { current->next->prev=current->prev; }
            current->prev->next=current->next;
            current->prev=NULL;
            hashMap->buckets[code].first->prev=current;
            current->next=hashMap->buckets[code].first;
            hashMap->buckets[code].first=current;
            return 1;
        }
        if(current->next==NULL) break;
        current = current->next;
    }

    return 0;
}

int put(HASHMAP *hashMap, long long int key, PERSON person){
    ENTRY *entry = malloc(sizeof(ENTRY));
    int code = hashCode(key);

    if(contains(hashMap, key)){
        printf("Contido em HashMap->buckets[%d]\n", code);
        return 0;
    }

    // Atualizando valores
    hashMap->elementsCount+=1;

    if(hashMap->buckets[code].first != NULL && (float) hashMap->elementsCount/(float) hashMap->bucketsCount > loadFactor){
        // NÃO TEM MAIS ESPAÇO, PRECISO REMOVER ANTES DE INSERIR
        printf("\n(!!!) Será removido %s para que %s possa ser inserido\n\n", hashMap->buckets[code].last->person.nome, person.nome);
        if(hashMap->buckets[code].last->prev==NULL){
            // O último é o primeiro
            free(hashMap->buckets[code].last);
            hashMap->buckets[code].last=NULL;
            hashMap->buckets[code].first=NULL;
        }else{
            // Existe uma ou mais entries
            hashMap->buckets[code].last = hashMap->buckets[code].last->prev;
            hashMap->buckets[code].last->next->prev=NULL;
            free(hashMap->buckets[code].last->next);
            hashMap->buckets[code].last->next=NULL;
        }
        hashMap->elementsCount--;
    }

    // INSERINDO
    entry->key=key;
    entry->person=person;
    entry->prev=NULL;

    if(hashMap->buckets[code].first == NULL){
        // Bucket VAZIO
        entry->next=NULL;
        hashMap->buckets[code].first=entry;
        hashMap->buckets[code].last=entry;
    } else {
        // Bucket com uma ou mais entries
        entry->next=hashMap->buckets[code].first;
        hashMap->buckets[code].first->prev=entry;
        hashMap->buckets[code].first=entry;
    }

    hashMap->currentLoadFactor= (float) hashMap->elementsCount/(float) hashMap->bucketsCount;
    if(hashMap->currentLoadFactor>loadFactor)
        printf("\n(!!!) ESTOUROU LOADFACTOR %f\n\n", hashMap->currentLoadFactor);

    return 1;
}

void populando(HASHMAP *hashMap){
    long long int key1 = 20677346522; //2
    long long int key2 = 88272078481; //1
    long long int key3 = 53604310598; //6
    long long int key4 = 85779623341; //5
    long long int key5 = 19245264173; //5
    long long int key6 = 53687972224; //0
    long long int key7 = 82725890870; //6 - Não aumentará o loadFactor, pois removerá a key3
    long long int key8 = 75661233191; //7 - Aumentará o loadFactor mas não removerá


    PERSON person1;
    strcpy(person1.nome, "Julia Anne");
    person1.idade=22;
    put(hashMap, key1, person1)? printf("-- %s Inserido\n", person1.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person2;
    strcpy(person2.nome, "Eliza Alves");
    person2.idade=15;
    put(hashMap, key2, person2)? printf("-- %s Inserido\n", person2.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person3;
    strcpy(person3.nome, "Ed de Souza");
    person3.idade=55;
    put(hashMap, key3, person3)? printf("-- %s Inserido\n", person3.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person4;
    strcpy(person4.nome, "Afonso Carvalho");
    person4.idade=22;
    put(hashMap, key4, person4)? printf("-- %s Inserido\n", person4.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person5;
    strcpy(person5.nome, "Carina Camacchi");
    person5.idade=27;
    put(hashMap, key5, person5)? printf("-- %s Inserido\n", person5.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person6;
    strcpy(person6.nome, "João Carvalho");
    person6.idade=46;
    put(hashMap, key6, person6)? printf("-- %s Inserido --\n", person6.nome): printf("-- ERRO DE INSERÇÃO\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person7;
    strcpy(person7.nome, "Amanda Medeiros");
    person7.idade=48;
    put(hashMap, key7, person7)? printf("-- %s Inserido --\n", person7.nome): printf("-- ERRO DE INSERÇÃO --\n");
    //printf("%f\n", hashMap->currentLoadFactor);

    PERSON person8;
    strcpy(person8.nome, "Alice Oliveira");
    person8.idade=18;
    put(hashMap, key8, person8)? printf("-- Person %s Inserido --\n", person8.nome): printf("-- ERRO DE INSERÇÃO --\n");
    //printf("%f\n", hashMap->currentLoadFactor);
}

int main(int argc, char *argv[]) {
    HASHMAP *hashMap = malloc(sizeof(HASHMAP));
    initHashMap(hashMap);
    //printf("-- HashMap Inicializado com LOADFACTOR = %f\n", hashMap->currentLoadFactor);

    populando(hashMap);
    //printf("-- HashMap Populado\n");

    free(hashMap);
    return 0;
}
