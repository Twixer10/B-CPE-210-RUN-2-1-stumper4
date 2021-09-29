/*
** EPITECH PROJECT, 2021
** open_file
** File description:
** open a given file
*/

#include "./include/stumper.h"

char *open_file(char *path, int fd)
{
    struct stat size;
    char *buff = NULL;
    
    stat(path, &size);
    buff = malloc(sizeof(char) * (size.st_size + 1));
    read(fd, buff, size.st_size);
    close(fd);
    return buff;
}


