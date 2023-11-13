
#include <stdlib.h>
#include <stdio.h>
#include "dsets.h"

dsets_t* alloc_dsets() {
    dsets_t* dsets = malloc(sizeof (dsets_t));
    dsets->set = NULL;
    dsets->next = NULL;
    return dsets;
}

void free_dsets(dsets_t* dsets) {
    if (EMPTY_DSETS(dsets)) {
        free(dsets);
    } else {
        while (dsets) {
            dsets_t* to_remove = dsets;
            dsets = dsets->next;
            free_dset(to_remove->set);
            free(to_remove);
        }
    }
}

void free_dset(dset_t* dset) {
    dset_member_t* member = dset->head;
    free(dset);
    while (member) {
        dset_member_t* to_free = member;
        member = member->next;
        free(to_free);
    }
}

dset_member_t* alloc_dset_member(void* member) {
    dset_member_t* dset_member = malloc(sizeof (dset_member_t));
    dset_member->member = member;
    dset_member->dset = NULL;
    dset_member->next = NULL;
    return member;
}

dset_member_t* make_set(dsets_t* dsets, void* member) {
    printf("Criando set\n");
    dset_member_t* dset_member = malloc(sizeof (dset_member_t));
    dset_t* dset = malloc(sizeof (dset_t));
    dset->head = dset_member;
    dset->tail  = dset_member;
    dset_member->member = member;
    dset_member->next = NULL;
    dset_member->dset = (void*) dset;
    dsets_t* node = dsets;
    if (!EMPTY_DSETS(dsets)) {
        printf("Criando set em dsets existentes\n");
        dsets_t* last_node = dsets;
        while (last_node->next) {
            last_node = last_node->next;
        }
        node = malloc(sizeof (dsets_t));
        last_node->next = node;
        node->next = NULL;
    }
    node->set = dset;
    return dset_member;
}

dset_member_t* find_set(dset_member_t* member) {
    return ((dset_t*) member->dset)->head;
}

void union_set(dsets_t** dsets, dset_member_t* member1, dset_member_t* member2) {
    dsets_t* to_remove = NULL;
    dsets_t* next_to_remove = *dsets;
    if (next_to_remove->set == member2->dset) {
        if (next_to_remove->next) {
            to_remove = next_to_remove;
            *dsets = next_to_remove->next;
            printf("to remove: %p\n", to_remove);
            free(to_remove);
        } else {
            // ERROR: Só há apenas um conjunto na lista de conjuntos
            return;
        }
    } else {
        while (next_to_remove->next->set != member2->dset) {
            next_to_remove = next_to_remove->next;
        }
        to_remove = next_to_remove->next;
        next_to_remove->next = to_remove->next;
        printf("to remove: %p\n", to_remove);
        free(to_remove);
    }
}


