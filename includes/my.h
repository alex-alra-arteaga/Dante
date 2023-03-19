/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

    typedef struct linked_list {
        char **data;
        struct linked_list *next;
        struct linked_list *prev;
    } linked_list_t;

    typedef struct s_selec {
        char *comm;
        void (*selec_func)(char **, linked_list_t *, char **);
    } t_func;

    void *my_memcpy(void *dest, const void *src, size_t size);
    void my_putchar_stderr(char c);
    char *handles_num(char *arr, int number);
    char* handles_decimal_hex(double nb);
    char* cat_str(char* main_str, char* temp_str);
    char* get_octal(int num, int* arr, char* temp, char* format);
    int len_ulong_long(char const *str);
    char *my_revstr_ulong_long(char *str);
    int if_hexadecimal(char const *str, int cnt_1);
    int is_char_alpha(char c);
    int num_words(char const *str, int i, int cnt);
    char **my_str_to_word_array(char const *str);
    char **my_split(char const *str, char split);
    int string(char const *str);
    int change_sign(int sign, int number);
    int get_sign_before_int(int i, char const *str, int sign);
    int prevent_under_overflow(char *aux, int i, int number, int number1);
    char *strlowcase02(char *str);
    int compare_and_swap(int *array, int temp);
    char *same_strs (char *str, char const *to_find, int index);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_isneg(int n);
    int my_printf(char *format, ...);
    int my_is_prime(int nb);
    char **my_arrdup(char **src, int size);
    char *my_int_to_str(int num);
    void my_putchar(char c);
    char my_put_nbr(int nb);
    int change_sign(int sign, int number);
    int my_getnbr(char const *str);
    int get_sign_before_int(int i, char const *str, int sign);
    int prevent_under_overflow(char *aux, int i, int number, int number1);
    int my_putstr(char const *str);
    int my_putstr_stderr(char const *str);
    char *my_revstr(char *str);
    int my_showmem(char const *str, int size);
    int my_showstr(char const *str);
    void my_sort_int_array(int *array, int size);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strcmp (char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    bool is_num(char c);
    bool is_float(char *str);
    bool is_only_num(char *str);
    char *strcat_malloc(char *dest, char const *src);
    bool is_special_float(char *str, int nb);
    char *special_float(char *string, int nb);
    char *precision_int(char* string, int nb);
    void my_swapcontext(ucontext_t *a, ucontext_t *b);
    char **read_map(char *file);
    void get_pid(void);
    void my_cd(char **, linked_list_t *, char **);
    void my_env(char **, linked_list_t *, char **);
    void my_unsetenv(char **, linked_list_t *, char **);
    void my_setenv(char **, linked_list_t *, char **);
    void my_exit(char **, linked_list_t *, char **);
    int getenv_content(char **env, char *var);
    char *get_path(char *input);
    int my_arrlen(char **arr);
    linked_list_t *init_env(char **env);
    void setenv_values(char **path, linked_list_t *env_l);
    void signal_handling(int status);
    bool is_executable(char **input);
    int getenv_content(char **env, char *var);
    char *is_in_path(char **input, char **env);
    char *get_path(char *input);
    void input_loop(char **env);
    void trigger_command(char *path, char **input_split, char **env);
    bool is_select_function
    (char **input_split, char **env, linked_list_t *env_l);
    void execute_commands
    (char **input_split, char **env, linked_list_t *env_l, char *path);
    bool is_array_num(char *str);

#endif /* MY_H_ */
