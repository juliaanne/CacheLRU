typedef struct {
    char nome[40];
    int CPF;
} Person;

typedef struct {
    int key;
    int *next;
    Person person;
} Entry;

typedef struct {
    int *first;
    Entry entry;
    int *last;
} LinkedList;

typedef struct {
    LinkedList buckets;
    int currentSize;
    int initialSize;
    double loadFactor;
    double sizeToRehash; // initialSize * loadFactor
} HashMap;


//ToDo: Put deverá implementar o rehash;

int main(int argc, char *argv[]) {


}