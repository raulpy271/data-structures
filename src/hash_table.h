#include <stddef.h>

#define TABLE_SIZE 100

typedef struct HashTable dict_t;
typedef struct Item item_t;

struct Item {
    char* key;
    void* value;
    item_t* next;
};

struct HashTable {
    item_t itens[TABLE_SIZE];
};

dict_t* alloc_dict();

item_t* getempty(dict_t* table);

int int_from_key(char key[]);

int hash(char key[], size_t table_size);

void* get(dict_t* table, char key[]);

void set(dict_t* table, char key[], void* value);
