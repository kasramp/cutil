#include <stdio.h>
#include <stdlib.h>

typedef struct pair
{
    int key;
    int value;
} Pair;

typedef struct entry
{
    Pair* pair;
    struct entry* next; 
} Entry;

typedef struct map
{
    Entry* table[32];
} Map;

int calculate_hash(int key)
{
    return key % 32;
}

void add_to_map(int key, int value, Map* map)
{
    int hash_code = calculate_hash(key);
    if (map->table[hash_code] == NULL)
    {
        Entry* entry = (Entry*) malloc(sizeof(Entry));
        Pair* pair = (Pair*) malloc(sizeof(Pair));
        pair->key = key;
        pair->value = value;
        entry->pair = pair;
        entry->next = NULL;
        map->table[hash_code] = entry;
    }
    else
    {
        Entry* existing_entry = map->table[hash_code];
        Entry* head = existing_entry;
        while(head->next != NULL)
        {
            if (head->pair->key == key)
            {
                head->pair->value = value;
                return;
            }
            head = head->next;
        }
        Entry* new_entry = (Entry*) malloc(sizeof(Entry));
        Pair* pair = (Pair*) malloc(sizeof(Pair));
        pair->key = key;
        pair->value = value;
        new_entry->pair = pair;
        new_entry->next = NULL;
        head->next = new_entry;
    }
}

int get_value(int key, Map* map)
{
    int hash_code = calculate_hash(key);
    Entry* entry = map->table[hash_code];
    Entry* head = entry;
    while(head != NULL)
    {
       Pair* pair = head->pair;
       if (pair == NULL) 
       {
           return -1;
       }
       if (pair->key == key)
       {
           return pair->value;
       }
       head = head->next;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    printf("HIII\n");
    Map* map = (Map*) malloc(sizeof(Map));
    add_to_map(10, 10, map);
    add_to_map(32, 32, map);
    add_to_map(0, 0, map);
    add_to_map(64, 64, map);
    add_to_map(32, -100, map);
    for(int i = 0; i<32; i++)
    {

        if(map->table[i] != NULL)
        {
            Entry* entry = map->table[i];
            Entry* temp = entry;
            int j = 1;
            while(temp != NULL)
            {
               printf("Hash table: %d, entry[%d] key:%d, entry[%d] value=%d\n", i,
                       j, temp->pair->key, j, temp->pair->value);
               temp = temp->next;
               j++;
            }
        }
    }
    printf("Value of 32 key is: %d\n", get_value(32, map));
    free(map);
}
