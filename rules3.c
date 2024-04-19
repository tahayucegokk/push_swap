/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:11:54 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 17:26:50 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_stack	*s)
{
	int	tmp;

	tmp = 0;
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	write(1, "ss\n", 3);
}

void	rr(t_stack	*s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[i];
	while (++i < s->size_a)
		s->a[i - 1] = s->a[i];
	s->a[i - 1] = tmp;
	i = 0;
	tmp = s->b[i];
	while (++i < s->size_b)
		s->b[i - 1] = s->b[i];
	s->b[i - 1] = tmp;
	write(1, "rr\n", 3);
}

void	rrr(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size_b > 0)
	{
		i = s->size_a - 1;
		tmp = s->a[i];
		while (i)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
		s->a[i] = tmp;
		i = s->size_b - 1;
		tmp = s->b[i];
		while (i--)
			s->b[i] = s->b[i - 1];
		s->b[i] = tmp;
		write(1, "rrr\n", 4);
	}
}
