
typedef struct Stack stk_t;
struct Stack {
    void* element;
    struct Stack* before;
};

stk_t* init();

void push(stk_t*, void*);

void* pop(stk_t*);

void* top(stk_t*);

int is_null(stk_t*);

