#include "../includes/push_swap.h"

static long	ft_atol(const char *s) //Define a function that converts every string into a long value
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n) //Define a function that searches for the last node to append to the linked list
{
	t_stack_node	*node; // Para armazenar um ponteiro para o novo nó a ser criado com o valor `n`
	t_stack_node	*last_node; // Para armazenar um ponteiro para o último nó atual da pilha

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); // Aloca memória para o novo nó
	if (!node)
		return ;

	node->nbr = n; // Define o valor do número
	node->cheapest = false; // Inicializa o campo `cheapest` como false
	node->above_median = false; // Inicializa o campo `above_median` como false

	node->next = NULL; // Define o ponteiro next do novo nó como NULL, pois ele será o último nó na lista
	if (!(*stack)) // Verifica se a pilha está vazia ou atualmente apontando para NULL, indicando que um primeiro nó precisa ser encontrado
	{
		*stack = node; // Se estiver vazia, atualiza o ponteiro *stack para apontar para o nó, efetivamente tornando-o a nova cabeça da lista encadeada
		node->prev = NULL; // Define o ponteiro anterior do nó cabeça como NULL, pois é o primeiro nó
	}
	else // Se a pilha não estiver vazia, significa que existem nós existentes na lista encadeada
	{
		last_node = find_last(*stack); // Neste caso, encontra o último nó
		last_node->next = node; // Anexa o novo nó ao último nó
		node->prev = last_node; // Atualiza o ponteiro anterior do novo nó e completa a anexação
	}
	
}

void	init_stack_a(t_stack_node **a, char **argv) //Define a function that initiates stack `a` by handling any errors and appending required nodes to complete a stack
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN) //Check for overflow
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a); 
		append_node(a, (int)n); //If no errors, append the node to the linked list by, taking a pointer to stack `a`, create a new node and assign `n` to that new node
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack) //Define a function that searches for the cheapest node, that is set by bool
{
    if (!stack)
        return (NULL);

    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}