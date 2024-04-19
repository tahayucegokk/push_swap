/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:21:38 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 16:35:08 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	basic_sort_a(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
	{
		if (stack->b[0] < stack->b[1])
			ss(stack);
		else
			sa(stack);
	}
	return (1);
}

int	basic_sort_both(t_stack *stack, int size)
{
	while (size != 3 || !(stack->a[0] < stack->a[1]
			&& stack->a[1] < stack->a[2]))
	{
		if (stack->a[0] > stack->a[1])
		{
			if (stack->b[0] < stack->b[1])
				ss(stack);
			else
				sa(stack);
		}
		else if (size == 3 && !(stack->a[2] > stack->a[0]
				&& stack->a[2] > stack->a[1]))
			size = push(stack, size, 0);
		else
		{
			size++;
			pa(stack);
		}
	}
	return (1);
}

int	basic_sort_b(t_stack *stack, int size)
{
	if (size == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		pa(stack);
		pa(stack);
	}
	else if (size == 3)
	{
		while (size || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (size == 1 && stack->a[0] > stack->a[1])
				sa(stack);
			else if (size == 1 || (size >= 2 && stack->b[0] > stack->b[1])
				|| (size == 3 && stack->b[0] > stack->b[2]))
				size = push(stack, size, 1);
			else
				sb(stack);
		}
	}
	return (1);
}
