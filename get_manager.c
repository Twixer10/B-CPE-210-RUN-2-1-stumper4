/*
** EPITECH PROJECT, 2021
** get maanager
** File description:
** get option
*/

#include "./include/stumper.h"

int str_contains(char *str, char *neddl, movies_t *node)
{
    int i = 0;

    for (int k = 0; str[k]; k++) {
        if (str[k] != neddl[i++])
            i = 0;
        else if (i == my_strlen(neddl)) {
            print_node(node);
            return 0;
        }
    }
    return -1;
}

void get_option(movies_t *node, char *col, char *neddl)
{
    (my_strncmp(col, "id_movie", 8) == 0 ? (str_contains(node->id_movie, neddl, node)):0);
    (my_strncmp(col, "title", 5) == 0 ?(str_contains(node->title, neddl, node)):0);
    (my_strncmp(col, "synposis", 8) == 0 ?(str_contains(node->synposis, neddl, node)):0);
    (my_strncmp(col, "id_director", 11) == 0 ?(str_contains(node->id_director, neddl, node)):0);
    (my_strncmp(col, "director", 8) == 0 ?(str_contains(node->director, neddl, node)):0);
    (my_strncmp(col, "id_type", 7) == 0 ?(str_contains(node->id_type, neddl, node)):0);
    (my_strncmp(col, "type", 4) == 0 ?(str_contains(node->type, neddl, node)):0);
}

void get(movies_t **list, char *req)
{
    char **request = my_strtok(req, ' ');
    movies_t *tmp = *list;

    while (tmp->next != NULL) {
        get_option(tmp, request[1], request[2]);
        tmp = tmp->next;
    }
    get_option(tmp, request[1], request[2]);
    free_tab(request);
}
