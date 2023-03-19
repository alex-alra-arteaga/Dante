/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/generator.h"
#include <time.h>

void maze_algorithm(t_map_g *map, int **stack)
{
    int rn = rand() % 4; static int x = 0; static int y = 0;
    int **checks = check_possibilities_g(); static int top = -1;
    if (are_neighbors(x, y, map)) {
        while (!is_possible_x(x, checks, rn, map) ||
        !is_possible_y(y, checks, rn, map) ||
        map->map[y + checks[rn][1]][x + checks[rn][0]] != '*')
            rn = rand() % 4;
        int item[2] = {x + checks[rn][0], y + checks[rn][1]};
        stack = push_g(item, map, ++top, stack);
        map->map[y + (checks[rn][1] / 2)][x + (checks[rn][0] / 2)] = '*';
        map->map[y + checks[rn][1]][x + checks[rn][0]] = 'o';
        x += checks[rn][0]; y += checks[rn][1];
    } else {
        while (top != -1 && !are_neighbors(stack[top][0], stack[top][1], map))
            stack = pop_g(top--, stack);
        if (top == -1)
            return;
        x = stack[top][0]; y = stack[top][1];
    }
    maze_algorithm(map, stack);
}

void create_paths(t_map_g *map)
{
    int rn_x = (rand() % (map->width - map->width / 2)) + map->width / 2;
    int rn_y = (rand() % (map->height -map->height / 2)) + map->height / 2;
    int max = rn_x * rn_y;

    for (int i = 0; i != map->height; i++)
        for (int j = 0; j != map->width; j++)
            (map->map[i][j] == 'o') ? map->map[i][j] = '*' : 0;
    if (map->width % 2 == 0) {
        map->map[map->height - 1][map->width - 1] = '*';
        if (map->height % 2 == 0)
            map->map[map->height - 1][map->width - 2] = '*';
    }
    for (int i = 0; i != map->height; i++) {
        for (int j = 0; j != map->width; j++)
            printf("%c", map->map[i][j]);
        (map->height == i + 1) ? 0 : printf("%c", '\n');
    }
    for (int i = 0; i != max && !map->perfect; i++)
        if (rn_y % 2 == 0 && rn_x % 2 == 0)
            map->map[rn_y][rn_x] = '*';
}

void generator(char **argv)
{
    t_map_g *map = init_t_map_g(argv);
    int **stack = malloc(sizeof(int *) * (map->width * map->height));
    srand(time(NULL));
    maze_algorithm(map, stack);
    create_paths(map);
}

int main(int argc, char **argv)
{
    error_handling_g(argc, argv);
    generator(argv);
    return (0);
}
