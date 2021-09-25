#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "hash_table.h"

dict_t* alloc_dict() { 
    dict_t* table = malloc(sizeof (dict_t));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->itens[i] = (item_t){NULL, NULL, NULL};
    }
    return table;
};

item_t* getempty(dict_t* table);

double frac(double x) {
    return x - floor(x);
}

int int_from_key(char* key) {
    int result = 0;
    for (char* current = key; (*current) != '\0'; current++) {
        result += (int)*current;
    }
    return result;
}

int hash(char key[], size_t table_size) {
    float c = 0.6180339887;
    int key_in_int = int_from_key(&(key[0]));
    return (int) floor(table_size * frac(c * key_in_int));
}

void* get(dict_t* table, char key[]);

void set(dict_t* table, char key[], void* value);

int main() {
    dict_t* table = alloc_dict();
    free(table);
    printf("%d \n", hash("blb", 100));
    return 0;
}

