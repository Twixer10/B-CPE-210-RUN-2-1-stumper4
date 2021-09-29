/*
** EPITECH PROJECT, 2021
** STUMPER
** File description:
** node_manager
*/

#include "./include/stumper.h"

movies_t *create_node(char *str)
{
    char **field = my_strtok(str, ',');
    movies_t *node = malloc(sizeof(movies_t));

    node->id_movie = field[0];
    node->title = field[1];
    node->synposis = field[2];
    node->id_director = field[3];
    node->director = field[4];
    node->id_type = field[5];
    node->type = field[6];
    node->next = NULL;
    return (node);
}

void push_last_in_list(movies_t **list, char *str)
{
    movies_t *node = create_node(str);
    movies_t *tmp = *list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void free_tab(char **tab)
{
    for (int x = 0; tab[x]; x++)
        free(tab[x]);
    free(tab);
}

void print_node(movies_t *node)
{
    my_printf("%s;%s;%s;%s;%s;%s;%s\n",
              node->id_movie, node->title, node->synposis, node->id_director,
              node->director, node->id_type, node->type);
        
}

void delete_nodes(movies_t **nodes)
{
    movies_t *tmp = *nodes;
        
    while (tmp->next != NULL) {
        free(tmp->id_movie);
        free(tmp->title);
        free(tmp->synposis);
        free(tmp->id_director);
        free(tmp->director);
        free(tmp->id_type);
        free(tmp->type);
        free(tmp);
        tmp = tmp->next;
    }
    free(tmp);
}
