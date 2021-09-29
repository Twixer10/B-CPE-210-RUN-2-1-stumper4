/*
** EPITECH PROJECT, 2021
** libC - Starter
** File description:
** This file was automatically generated by libC starter command.
*/

#include "./include/stumper.h"

int start_option(movies_t **list, char *request)
{
    char **req = my_strtok(request, ' ');

    (my_strncmp(req[0], "get", 3) == 0 ?get(list, request):0);
    (my_strncmp(req[0], "show", 4) == 0 ? show_manager(list, my_getnbr(req[1]), my_getnbr(req[2])):0);
    (my_strncmp(req[0], "sort", 4) == 0 ? sort(list, request):0);
    delete_nodes(list);
    return 0;
}

int main(int ac, char **av)
{
    int f = 0;
    char **list;
    char *tmp;
    movies_t *l;
    
    if (ac != 3)
        return 84;
    if ((f = open(av[1], O_RDONLY)) == -1)
        return (my_error("ERROR: Open file", 84));
    else {
        tmp = open_file(av[1], f);
        list = my_strtok(tmp, '\n');
        l = create_node(list[0]);
        for (int i = 1; list[i]; i++)
            push_last_in_list(&l, list[i]); 
    }
    return (start_option(&l, av[2]));
}
