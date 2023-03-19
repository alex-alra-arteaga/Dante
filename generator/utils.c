/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/generator.h"

void insert_cell_struct(int i, t_map_g *map)
{
    for (int j = 0; j != map->width; j++) {
        if (i % 2 == 0 && j % 2 == 0)
            map->map[i][j] = '*';
        else
            map->map[i][j] = 'X';
    }
}

bool are_neighbors(int x, int y, t_map_g *map)
{
    if ((y + 2 < map->height - 1) ? map->map[y + 2][x] == '*' : false)
        return true;
    if ((y - 2 >= 0) ? map->map[y - 2][x] == '*' : false)
        return true;
    if ((x + 2 < map->width - 1) ? map->map[y][x + 2] == '*' : false)
        return true;
    if ((x - 2 >= 0) ? map->map[y][x - 2] == '*' : false)
        return true;
    return false;
}

bool is_possible_x(int x, int **checks, int rn, t_map_g *map)
{
    if (checks[rn][0] + x < map->width && checks[rn][0] + x >= 0)
        return true;
    return false;
}

bool is_possible_y(int y, int **checks, int rn, t_map_g *map)
{
    if (checks[rn][1] + y < map->height && checks[rn][1] + y >= 0)
        return true;
    return false;
}

int **check_possibilities_g(void)
{
    int **val1 = malloc(sizeof(int *) * 4);
    for (int i = 0; i < 4; i++)
        val1[i] = malloc(sizeof(int) * 2);
    val1[0][0] = 0;
    val1[0][1] = 2;
    val1[1][0] = 2;
    val1[1][1] = 0;
    val1[2][0] = -2;
    val1[2][1] = 0;
    val1[3][0] = 0;
    val1[3][1] = -2;
    return val1;
}
