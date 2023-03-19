/*
** EPITECH PROJECT, 2022
** dante
** File description:
** agming algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/solver.h"
#include "../includes/generator.h"

bool error_handling (int argc, char **argv)
{
    struct stat path;

    if (argc != 2)
        return true;
    stat(argv[1], &path);
    if (!S_ISREG(path.st_mode))
        exit(84);
    return false;
}
