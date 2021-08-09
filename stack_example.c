#include <stdio.h>
#include "src/stack.h"

int main() {
    char text1[] = "Hello ";
    char text2[] = "World!\n"; 
    stk_t* stk = init();
    push(stk, &text2);
    push(stk, &text1);
    printf("%s", (char*)pop(stk));
    printf("%s", (char*)pop(stk));
    return 0;
}

