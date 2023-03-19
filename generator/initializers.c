/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/generator.h"
#include <ctype.h>
#include <time.h>

char **init_perfect_map(t_map_g *map)
{
    map->map = malloc(sizeof(char *) * (map->height + 1));
    for (int i = 0; i != map->height; i++)
        map->map[i] = malloc(sizeof(char) * (map->width + 1));
    for (int i = 0; i != map->height; i++)
        insert_cell_struct(i, map);
    map->map[0][0] = 'o';
    return map->map;
}

char **init_imperfect_map(t_map_g *map)
{
    srand(time(NULL));
    int rn_x = rand() % map->width;
    int rn_y = rand() % map->height;
    int max = rn_x * rn_y;
    map->map = malloc(sizeof(char *) * (map->height + 1));
    for (int i = 0; i != map->height; i++)
        map->map[i] = malloc(sizeof(char) * (map->width + 1));
    for (int i = 0; i != map->height; i++)
        insert_cell_struct(i, map);
    for (int i = 0; i != max; i++) {
        if (rn_y % 2 == 0 && rn_x % 2 == 0 &&
        rn_x < map->width - 12 && rn_y < map->height - 12)
            map->map[rn_y][rn_x] = 'X';
        else
            map->map[rn_y][rn_x] = '*';
        rn_x = rand() % map->width;
        rn_y = rand() % map->height;
    }
    map->map[0][0] = 'o';
    return map->map;
}

t_map_g *init_t_map_g(char **argv)
{
    t_map_g *map = malloc(sizeof(t_map_g));
    map->width = my_getnbr(argv[1]);
    map->height = my_getnbr(argv[2]);
    if ((argv[3] && (argv[3][0] == 'i')) || !argv[3])
        map->perfect = false;
    else
        map->perfect = true;
    if (map->perfect)
        map->map = init_perfect_map(map);
    else
        map->map = init_imperfect_map(map);
    return map;
}
