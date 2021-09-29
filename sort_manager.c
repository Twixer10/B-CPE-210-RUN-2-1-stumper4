/*
** EPITECH PROJECT, 2021
** sort
** File description:
** sort
*/

#include "./include/stumper.h"

void get_max(char *tmp, int *max)
{
    int i = my_getnbr(tmp);

    if (*(max) < i)
        *(max) = i;
}

void try_it(int a, int b, movies_t *node)
{
    if (a == b)
        print_node(node);
}

void sorting(movies_t **list, char *param, int max)
{
    movies_t *node;

    for (int k = 1; k <= max; k++) {
        node = *list;
        while (node->next != NULL) {
            (my_strncmp(param, "id_movie", 8) == 0 ?
             try_it(my_getnbr(node->id_movie), k, node):0);
            (my_strncmp(param, "id_director", 11) == 0 ?
             try_it(my_getnbr(node->id_director), k, node):0);
            (my_strncmp(param, "id_type", 7) == 0 ?
             try_it(my_getnbr(node->id_type), k, node):0);
            node = node->next;
        }
        (my_strncmp(param, "id_movie", 8) == 0 ?
         try_it(my_getnbr(node->id_movie), k, node):0);
        (my_strncmp(param, "id_director", 11) == 0 ?
         try_it(my_getnbr(node->id_director), k, node):0);
        (my_strncmp(param, "id_type", 7) == 0 ? try_it(my_getnbr(node->id_type),
                                                       k, node):0);
    }
}

void sort(movies_t **list, char *req)
{
    int max = 0;
    movies_t *node = *list;
    char **r = my_strtok(req, ' ');

    while (node->next != NULL) {
        (my_strncmp(r[1], "id_movie", 8) == 0 ?
         get_max(node->id_movie, &max):0);
        (my_strncmp(r[1], "id_director", 11) == 0 ?
         get_max(node->id_director, &max):0);
        (my_strncmp(r[1], "id_type", 7) == 0 ? get_max(node->id_type, &max):0);
        node = node->next;
    }
    (my_strncmp(r[1], "id_movie", 8) == 0 ? get_max(node->id_movie, &max):0);
    (my_strncmp(r[1], "id_director", 11) == 0 ?
     get_max(node->id_director, &max):0);
    (my_strncmp(r[1], "id_type", 7) == 0 ? get_max(node->id_type, &max):0);
    sorting(list, r[1], max);
    free_tab(r);
}
