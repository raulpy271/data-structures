#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hash_table.h"

dict_t* alloc_dict() { 
    dict_t* table = malloc(sizeof (dict_t));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->itens[i] = (item_t){NULL, NULL, NULL};
    }
    return table;
};

bool is_null(item_t* item) {
    return item->value == NULL && item->key == NULL && item->next == NULL;
}

item_t* getempty(dict_t* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (is_null(&table->itens[i])) {
            return &table->itens[i];
        }
    }
    return NULL;
}

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

void* get(dict_t* table, char key[]) {
    int hash_index = hash(key, TABLE_SIZE);
    item_t* current = &(table->itens[hash_index]);
    while(
            !is_null(current) &&
            (strcmp(current->key, &(key[0])) != 0)
    ) {
        if (current->next != NULL) {
            current = current->next;
        } else {
            return NULL;
        }
    }
    if (is_null(current)) {
        return NULL;
    } else {
        return current->value;
    }
};

void set(dict_t* table, char key[], void* value) {
    int hash_index = hash(key, TABLE_SIZE);
    item_t* item_to_set = &(table->itens[hash_index]);
    bool have_colision = !is_null(item_to_set);
    if(!have_colision) {
        item_to_set->key = &(key[0]);
        item_to_set->value = value;
        item_to_set->next = NULL;
    } else {
        item_t* item_with_colision = item_to_set;
        while(item_with_colision->next != NULL) {
            if (strcmp(item_with_colision->key, &(key[0])) == 0) {
                item_with_colision->value = value;    
                return;
            }
            item_with_colision = item_with_colision->next;
        }
        if (strcmp(item_with_colision->key, &(key[0])) == 0) {
            item_with_colision->value = value;    
        } else {
            item_t* item_to_insert_after_colision = getempty(table);
            item_to_insert_after_colision->key = &(key[0]);
            item_to_insert_after_colision->value = value;
            item_to_insert_after_colision->next = NULL;
            item_with_colision->next = item_to_insert_after_colision;
        }
    }
};

int main() {
    dict_t* table = alloc_dict();
    set(table, "raul", (void *)0x00ff);
    printf("table[\"raul\"] = %p\n", get(table, "raul"));
    return 0;
}

