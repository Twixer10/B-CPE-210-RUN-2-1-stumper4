/*
** EPITECH PROJECT, 2021
** show
** File description:
** display all of movies with an interval
*/
#include "./include/stumper.h"

void show_manager(movies_t **list, int pos, int nb)
{
    movies_t *node = *list;
    int i = 0;

    while (node->next != NULL) {
        i++;
        if (i >= pos && i <= nb)
            print_node(node);
        node = node->next;
    }
    if (i >= pos && i <= nb)
        print_node(node);
}
