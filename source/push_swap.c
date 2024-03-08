/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/7 15:12:57 by fivieira          #+#    #+#             */
/*   Updated: 2023/12/14 15:51:23 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_split_result(char **split_result) {
    int i = 0;
    while (split_result[i]) {
        free(split_result[i]);
        i++;
    }
    free(split_result);
}

int	main(int ac, char **av) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    if (ac == 1 || (ac == 2 && !av[1][0])) {
        // Verifica se não há argumentos ou se o único argumento é vazio
        return (1);
    } else if (ac == 2) {
        // Trata o caso em que há apenas um argumento (sem aspas)
        char *arg = av[1];
        char **split_result = split(arg, ' '); // Chama a função split para extrair cada substring
        init_stack_a(&a, split_result); // Inicializa a pilha "a" com as substrings

        // Libera a memória alocada para o array de substrings
        free_split_result(split_result);
    } else {
        // Trata o caso em que há mais de um argumento
        init_stack_a(&a, av + 1); // Inicializa a pilha "a" com os argumentos
    }

    if (!stack_sorted(a)) {
        if (stack_len(a) == 2) {
            sa(&a, false);
        } else if (stack_len(a) == 3) {
            sort_3(&a);
        } else {
            sort_stacks(&a, &b);
        }
    }

    free_stack(&a); // Libera a memória alocada para a pilha "a"
    return (0);
}