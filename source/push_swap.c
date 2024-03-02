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

int	main(int ac, char **av) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
	t_stack_node	*a; //To store a pointer to stack `a`
	t_stack_node	*b; //To store a pointer to stack `b`

	a = NULL; //Set both pointers to NULL to avoid undefined behaviour
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0])) //Check for incorrect argument counts or if the 2 argument is `0`
		return (1);
	else if (ac == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
		av = split(av[1], ' '); //Call split() to extract each substring
	init_stack_a(&a, av + 1); //Initiate stack `a`, which also handles errors

	        // Libera a memória alocada para cada substring
        int i = 0;
        while (av[i]) {
            free(av[i]);
            i++;
        }
        // Libera a memória alocada para o array de substrings
        free(av);
	if (!stack_sorted(a)) //Check if the stack is not sorted
	{
		if (stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_3(&a);
		else
			sort_stacks(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	}
	free_stack(&a); //Clean up the stack
	return (0);
}