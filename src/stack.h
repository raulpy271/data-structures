
/*
 * This datatype represent a stack. The stack is implemented using a linked list where each element are a pointer to your content.
 */
typedef struct Stack stk_t;
struct Stack {
    void* element;
    struct Stack* before;
};

/*
 * This function create a null stack. A null stack is a stack where the field `before` is `NULL`, so there is no element before a null stack, it's number of element is zero.
 */
stk_t* init();

int is_null(stk_t*);

/*
 * This function put elements in the top of the stack. Since the stack has not element limit, every time which `push` is called the `malloc` function is called too, as it will allocate the structure of the new element. The process of deallocating this memory is done when the pop function is called, so you don't need to worry about freeing the memory of your stack.
 */
void push(stk_t*, void*);

/*
 * Remove a element from top and return it. Besides, it will free the space of the structure of this element from the memory.
 */
void* pop(stk_t*);

/*
 * Returns the top of the stack, but without remove it.
 */
void* top(stk_t*);

