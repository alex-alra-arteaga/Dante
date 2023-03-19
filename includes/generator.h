/*
** EPITECH PROJECT, 2022
** generator.h
** File description:
** Contains the structures of function of generator folder
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    typedef struct s_map {
        int width;
        int height;
        bool perfect;
        char **map;
    }t_map_g;

    int **pop_g(int top, int **val);
    int **push_g(int *item, t_map_g *m, int top, int **val);
    char **init_perfect_map(t_map_g *map);
    char **init_imperfect_map(t_map_g *map);
    t_map_g *init_t_map_g(char **argv);
    void error_handling_g(int argc, char **argv);
    bool is_possible_y(int y, int **checks, int rn, t_map_g *map);
    bool are_neighbors(int x, int y, t_map_g *map);
    bool is_possible_x(int x, int **checks, int rn, t_map_g *map);
    void insert_cell_struct(int i, t_map_g *map);
    int **check_possibilities_g(void);

#endif
