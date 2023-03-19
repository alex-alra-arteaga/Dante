/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"

void error_handling_g(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        exit(84);
    if (!is_array_num(argv[1]) || !is_array_num(argv[2]))
        exit(84);
    if (my_getnbr(argv[1]) <= 0 || my_getnbr(argv[2]) <= 0)
        exit(84);
    if (argv[3] && my_strcmp(argv[3], "perfect") != 0 &&
        my_strcmp(argv[3], "imperfect") != 0)
        exit(84);
}
