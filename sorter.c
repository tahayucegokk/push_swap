/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:22:35 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 17:22:54 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	check_sort(int *stack, int size, int flag)
{
	int	i;

	i = 0;
	while ((flag == 0) && (++i < size))
	{
		if (stack[i - 1] > stack[i])
			return (0);
	}
	while ((flag == 1) && (++i < size))
	{
		if (stack[i - 1] < stack[i])
			return (0);
	}
	return (1);
}

int	ft_sort(t_stack *stack, int size)
{
	if (size == 2)
		sa(stack);
	else if (size == 3)
		sort_three(stack);
	else
		ft_divide(stack, size);
	return (1);
}

int	median(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = -1;
	while (++i < size)
		tmp[i] = stack_a[i];
	sort_int_temp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}
