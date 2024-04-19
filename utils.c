/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:52:13 by muyucego          #+#    #+#             */
/*   Updated: 2024/04/19 16:34:54 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	argv_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	else if (s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int	argv_atoi(char *str, t_stack *stack, char **argv, int check)
{
	unsigned long long		result;
	unsigned int			i;
	int						sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!(is_num(str)))
		free_argv(argv, stack, check);
	if (str[i] == '-' && ++i)
		sign = sign * -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + ((str[i++]) - 48);
		if ((result > 2147483648 && sign == -1)
			|| (result > 2147483647 && sign == 1))
			free_argv(argv, stack, check);
	}
	return (result * sign);
}

void	check_args(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == ' ')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_repeat(t_stack *stack, int size, char **argv, int check)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack ->a[i] == stack ->a[j])
				return (free_argv(argv, stack, check), exit(0));
			j++;
		}
		i++;
		j = i + 1;
	}
}
