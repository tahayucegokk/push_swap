/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:00:28 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 17:17:04 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_divide(t_stack *stack, int size)
{
	int	pivot_a;
	int	pivot_b;
	int	items;

	items = size;
	median(&pivot_a, stack->a, size);
	while (size != (items + 1) / 2)
	{
		if (stack->a[0] < pivot_a && (size--))
		{
			pb(stack);
		}
		else
		{
			median(&pivot_b, stack->b, stack->size_b);
			if ((stack->b[0] <= pivot_b) && (stack->size_b > 2))
				rr(stack);
			else
				ra(stack);
		}
	}
	quicksort_a(stack, (items + 1) / 2, 0);
	quicksort_b(stack, items / 2, 0);
	return (1);
}

int	quicksort_a(t_stack *stack, int size, int count)
{
	int	pivot_a;
	int	items;

	if (check_sort(stack->a, size, 0) == 1)
		return (1);
	if (size == 2)
		return (basic_sort_a(stack));
	else if (size == 3 && stack->size_a == 3)
		return (sort_three(stack));
	else if (size == 3)
		return (basic_sort_both(stack, size));
	median(&pivot_a, stack->a, size);
	items = size;
	while (size != (items + 1) / 2)
	{
		if (stack->a[0] < pivot_a && (size--))
			pb(stack);
		else if (++count)
			ra(stack);
	}
	while ((items + 1) / 2 != stack->size_a && count--)
		rra(stack);
	return (quicksort_a(stack, (items + 1) / 2, 0),
		quicksort_b(stack, items / 2, 0));
}

int	quicksort_b(t_stack *stack, int size, int count)
{
	int	pivot_b;
	int	items;

	if (!count && check_sort(stack->b, size, 1) == 1)
		while (size--)
			pa(stack);
	if (size <= 3)
		return (basic_sort_b(stack, size));
	median(&pivot_b, stack->b, size);
	items = size;
	while (size != items / 2)
	{
		if (stack->b[0] >= pivot_b && (size--))
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack);
	return (quicksort_a(stack, (items + 1) / 2, 0),
		quicksort_b(stack, items / 2, 0));
	return (1);
}
