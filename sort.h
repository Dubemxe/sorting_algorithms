#include <stddef.h>

#ifndef SORT_H
#define SORT_H

/* Structure for doubly linked list */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Prototypes */

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int high, int low);
void lomuto_sort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
#endif
