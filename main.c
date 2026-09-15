#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[])
{
    list* lst = init();
    int x = -10;
    add(lst, &x);
    for (int i = 0; i < 100; i++) {
        int* p = malloc(sizeof(int));
        *p = i;
        add(lst, p);
    }
    for (size_t i = 0; i < get_size(lst); i++) {
        int* p = (int*) get_by_index(lst, i);
        printf("%d\n", *p);
    }
    printf("Size: %zu\n", get_size(lst));
    return 0;
}

