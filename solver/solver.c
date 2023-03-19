/*
** EPITECH PROJECT, 2022
** dante
** File description:
** agming algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/solver.h"

char **open_read_n_splitfile(char **argv)
{
    char **map;
    struct stat path;
    stat(argv[1], &path);
    char *buff = malloc(sizeof(char) * (path.st_size + 1));
    int fd = open(argv[1], O_RDONLY);
    int rd = read(fd, buff, path.st_size + 1);
    buff[rd] = '\0';
    close(fd);
    map = my_split(buff, '\n');
    return map;
}

int **check_possibilities(int x, int y)
{
    int **val1 = malloc(sizeof(int *) * 6);
    for (int i = 0; i < 6; i++)
        val1[i] = malloc(sizeof(int) * 2);
    val1[0][0] = x;
    val1[0][1] = y + 1;
    val1[1][0] = x + 1;
    val1[1][1] = y;
    val1[2][0] = x - 1;
    val1[2][1] = y;
    val1[3][0] = x;
    val1[3][1] = y - 1;
    val1[4][0] = x;
    val1[4][1] = y + 1;
    val1[5][0] = x + 1;
    val1[5][1] = y;
    return val1;
}

bool are_there_neighbors(int x, int y, t_map *map)
{
    if ((y < map->height - 1) ? map->map[y + 1][x] == '*' : false)
        return true;
    if ((y - 1 >= 0) ? map->map[y - 1][x] == '*' : false)
        return true;
    if ((x < map->width - 1) ? map->map[y][x + 1] == '*' : false)
        return true;
    if ((x - 1 >= 0) ? map->map[y][x + 1] == '*' : false)
        return true;
    return false;
}

bool is_possible(int **checks, int rn, t_map *map)
{
    if (checks[rn][0] < map->width && checks[rn][0] >= 0 && checks[rn][1] <
    map->height && checks[rn][1] >= 0)
        return true;
    return false;
}

void print_path(t_map *map, int **stack)
{
    for (int i = 0; stack[i]; i++)
        map->initial_map[stack[i][1]][stack[i][0]] = 'o';
    for (int i = 0; map->initial_map[i]; i++) {
        my_putstr(map->initial_map[i]);
        my_putchar('\n');
    }
}
