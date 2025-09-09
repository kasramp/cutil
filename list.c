#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

struct List {
	void **data;
    size_t capacity;
    size_t size;
};

list* init()
{
    list* lst = malloc(sizeof(list));
    if (!lst) {
        return NULL;
    }
    lst->capacity = 16;
    lst->size = 0;
    lst->data = malloc(lst->capacity * sizeof(void*));
    if (!lst->data) {
        free(lst);
        return NULL;
    }
    return lst;
}

size_t get_size(list* lst)
{
    return lst->size;
}

bool add(list* lst, void* element)
{
    if (lst->size >= lst->capacity) {
        void** tmp = realloc(lst->data, lst->capacity * 2 * sizeof(void*));
        if (!tmp) {
            return false;
        }
        lst->data = tmp;
        lst->capacity = lst->capacity * 2;
    }
    lst->data[lst->size] = element;
    lst->size++;
    return true;
}

void* get_by_index(list* lst, size_t index)
{
    if (!lst || index >= lst->size) {
        return NULL;
    }
    return lst->data[index];
}

size_t get_index(list* lst, void* element)
{
    if (!lst) {
        return (size_t)-1;
    }
    for (size_t i = 0; i < lst->size; i++) {
        if (lst->data[i] == element) {
            return i;
        }
    }
    return (size_t)-1;
}

bool exists(list* lst, void* element)
{
    return get_index(lst, element) != (size_t)-1;
}

void delete_by_index(list* lst, size_t index)
{
    if (index >= lst->size) {
        return;
    }

    for (size_t i = index + 1; i < lst->size; i++) {
        lst->data[i - 1] = lst->data[i];
    }
    lst->size--;
}

void delete(list* lst, void* element)
{
    size_t index = get_index(lst, element);
    if (index == (size_t)-1) {
        return;
    }
    delete_by_index(lst, index);
}

void free_list(list* lst)
{
    free(lst->data);
    free(lst);
}

