/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** sumper
*/

#include "./my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct movies_h
{
    char *id_movie;
    char *title;
    char * synposis;
    char *id_director;
    char *director;
    char *id_type;
    char *type;
    struct movies_h *next;
} movies_t;

movies_t *create_node(char *field);
void push_last_in_list(movies_t **list, char *str);
void print_list(movies_t **list);
void print_node(movies_t *node);
void get(movies_t **nodes, char *req);
void show_manager(movies_t **list, int pos, int nb);
void sort(movies_t **list, char *req);
void delete_nodes(movies_t **nodes);
void free_tab(char **tab);
