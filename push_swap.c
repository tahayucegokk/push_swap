/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:48:13 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 16:56:08 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	push_swap(char **argv, int check)
{
	t_stack	*stack;
	int		size;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return ;
	size = argv_strlen(argv);
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return (free(stack));
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
		return (free(stack->a), free(stack), exit(0));
	stack->size_b = 0;
	while (++i < size)
		stack->a[i] = argv_atoi(argv[i], stack, argv, check);
	check_repeat(stack, size, argv, check);
	if (!check_sort(stack->a, size, 0))
		ft_sort(stack, size);
	free(stack->a);
	free(stack->b);
	free(stack);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv++;
		argv = ft_split(*argv, ' ');
		if (!argv)
			return (1);
		push_swap(argv, 1);
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	else
		push_swap(++argv, 0);
	return (0);
}
