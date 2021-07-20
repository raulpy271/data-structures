
typedef void* item;

struct array {
    int MAX_LIMIT;
    int length;
    int size_item;
    item first_item;
};

typedef struct array array;

array* make_arr(item source_arr, size_t size_arr, size_t size_item);

item get(array*, int);

array* map(array*, item(*func)(item));

void iter(array*, void(*func)(item item_of_array, int index_of_item));

