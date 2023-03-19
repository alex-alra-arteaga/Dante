/*
** EPITECH PROJECT, 2022
** dante
** File description:
** agming algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/solver.h"

bool solver_algorithm(t_map *map, int **stack)
{
    int rn = rand() % 6; static int x = 0; static int y = 0;
    static int top = -1; int **checks = check_possibilities(x, y);
        if (are_there_neighbors(x, y, map)) {
            while (!is_possible(checks, rn, map) || map->map[checks[rn][1]]
            [checks[rn][0]] != '*')
                rn = rand() % 6;
            int item[2] = {checks[rn][0], checks[rn][1]};
            push(item, map, ++top, stack);
            map->map[checks[rn][1]][checks[rn][0]] = 'o';
            x = checks[rn][0]; y = checks[rn][1];
            (x == map->width - 1 && y == map->height - 1) ?
                print_path(map, stack), exit(0) : 0;
        } else {
            while (top != -1 && !are_there_neighbors(stack[top][0], stack[top]
            [1], map))
                pop(top--, stack);
            (top == - 1) ? printf("no solution found"), exit(84) : 0;
            x = stack[top][0]; y = stack[top][1];
        }
        return false;
}

t_map *init_t_map(char **map_arr)
{
    t_map *map = malloc(sizeof(t_map));
    map->width = my_strlen(map_arr[0]);
    map->height = my_arrlen(map_arr);
    map->map = map_arr;
    map->map[0][0] = 'o';
    map->initial_map = my_arrdup(map_arr, map->height);
        return map;
}

void solver(t_map *map)
{
    int **stack = malloc(sizeof(int *) * (map->width * map->height));
    srand(true);
    while (true)
        solver_algorithm(map, stack);
}

int main(int argc, char **argv)
{
    if (error_handling(argc, argv))
        return (84);
    char **map_arr = open_read_n_splitfile(argv);
    if (!map_arr || !map_arr[0])
        return (84);
    t_map *map = init_t_map(map_arr);
    solver(map);
    return (0);
}
