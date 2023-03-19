/*
** EPITECH PROJECT, 2022
** dante
** File description:
** Generator algorithm for mazes
*/

#include "../includes/my.h"
#include "../includes/generator.h"

int **push_g(int *item, t_map_g *m, int top, int **stack)
{
    if (top == m->height * m->width - 1) {
        printf("Stack Overflow\n");
        exit(2);
    }
    stack[top] = malloc(sizeof(int) * 2);
    stack[top][0] = item[0];
    stack[top][1] = item[1];
    return stack;
}

int **pop_g(int top, int **stack)
{
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    stack[top] = NULL;
    return stack;
}
