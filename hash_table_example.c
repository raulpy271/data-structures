#include <stdio.h>

#include "src/hash_table.h"

int main() {
    dict_t* table = alloc_dict();
    set(table, "raul", (void *)0x01);
    set(table, "maria", (void *)0x02);

    printf("table[\"raul\"] = %p\n", get(table, "raul"));
    printf("table[\"maria\"] = %p\n", get(table, "maria"));
    printf("table[\"joao\"] = %p\n", get(table, "joao"));
    printf("table[\"ze\"] = %p\n", get(table, "ze"));
    return 0;
}

