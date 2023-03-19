/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** Contains the structures of function of generator folder
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

    #include <time.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    typedef struct map {
        int width;
        int height;
        bool perfect;
        char **map;
        char **initial_map;
    }t_map;

    char **open_read_n_splitfile(char **argv);
    int **pop(int top, int **val);
    int **push(int *item, t_map *m, int top, int **val);
    bool error_handling(int argc, char **argv);
    int **check_possibilities(int x, int y);
    bool are_there_neighbors(int x, int y, t_map *map);
    bool is_possible(int **checks, int rn, t_map *map);
    void print_path(t_map * map, int **stack);
    bool solver_algorithm(t_map *map, int **stack);
    t_map *init_t_map(char **map_arr);

#endif
