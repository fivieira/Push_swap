#include "../includes/push_swap.h"

void free_split_result(char **split_result) {
    char **current_word = split_result;
    while (*current_word) {
        free(*current_word); // Libera a memória alocada para cada palavra individual
        current_word++;
    }
    free(split_result); // Libera a memória alocada para o array de strings
}

int	main(int argc, char **argv) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
	t_stack_node	*a; //To store a pointer to stack `a`
	t_stack_node	*b; //To store a pointer to stack `b`

	a = NULL; //Set both pointers to NULL to avoid undefined behaviour
	b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0])) {
        return 1; // Tratar caso de argumentos inválidos
    } else if (argc == 2) {
        argv = split(argv[1], ' '); // Dividir os argumentos se necessário
        if (!argv) {
            return 1; // Tratar erro de alocação de memória
        }
        init_stack_a(&a, argv + 1); // Inicializar a pilha 'a' com os argumentos
        free_split_result(argv); // Liberar memória alocada para os resultados do split
    } else {
        init_stack_a(&a, argv + 1); // Inicializar a pilha 'a' com os argumentos
    }
	if (!stack_sorted(a)) //Check if the stack is not sorted
	{
		if (stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_three(&a);
		else
			sort_stacks(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	}
	free_stack(&a); //Clean up the stack
	return (0);
}
