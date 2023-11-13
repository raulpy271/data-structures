
#ifndef DSETS_H_
#define DSETS_H_

#define EMPTY_DSETS(dset) ((!dset->set) && (!dset->next))

typedef struct _dset_member_t dset_member_t;
typedef struct _dset_t dset_t;

typedef struct _dset_member_t {
    void* member;
    dset_t* dset;
    dset_member_t* next;
} dset_member_t;

typedef struct _dset_t {
    dset_member_t* head;
    dset_member_t* tail;
} dset_t;

typedef struct dsets_t {
    dset_t* set;
    struct dsets_t* next;
} dsets_t;

dsets_t* alloc_dsets();
dset_member_t* alloc_dset_member(void* member);
void free_dsets(dsets_t* dsets);
void free_dset(dset_t* dset);
dset_member_t* make_set(dsets_t* dsets, dset_member_t* dset_member);
dset_member_t* find_set(dset_member_t* member);
void union_set(dsets_t** dsets, dset_member_t* member1, dset_member_t* member2);

#endif // DSETS_H_
