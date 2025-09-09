#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct List list;

list* init();
size_t get_size(list* lst);
bool add(list* lst, void* element);
void* get_by_index(list* lst, size_t index);
size_t get_index(list* lst, void* element);
bool exists(list* lst, void* element);
void delete_by_index(list* lst, size_t index);
void delete(list* lst, void* element);
void free_list(list* lst);
#endif

