/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_range(char *str)
{
	int		sign;
	char	*limit;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (sign == 1)
		limit = "2147483647";
	else
		limit = "2147483648";
	if (ft_strlen(str) > ft_strlen(limit))
		return (0);
	if (ft_strlen(str) == ft_strlen(limit) && ft_strcmp(str, limit) > 0)
		return (0);
	return (1);
}

static int	valid_nbr(char *str)
{
	if (!str || !str[0])
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!str[0])
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	check_nums(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!valid_nbr(args[i]))
			return (0);
		if (!in_range(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_dup(int *stack, int top)
{
	int	i;
	int	j;

	i = 0;
	while (i < top - 1)
	{
		j = i + 1;
		while (j < top)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	alloc_stk(t_stack *stacks, int size)
{
	stacks->a = (int *)malloc(sizeof(int) * size);
	if (!stacks->a)
		return (0);
	stacks->b = (int *)malloc(sizeof(int) * size);
	if (!stacks->b)
	{
		free(stacks->a);
		return (0);
	}
	return (1);
}
