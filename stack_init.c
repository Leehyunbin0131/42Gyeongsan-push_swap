/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 00:00:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

int	fill_a(char **args, int count, int *stack)
{
	int	i;
	int	current_index;

	i = 0;
	current_index = count - 1;
	while (i < count)
	{
		stack[current_index] = ps_atoi(args[i]);
		current_index--;
		i++;
	}
	return (count);
}

void	fill_b(int size, int *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = 0;
		i++;
	}
}

int	init_stk(t_stack *stacks, char **args, int count)
{
	if (count <= 0 || !check_nums(args, count))
		return (0);
	if (!alloc_stk(stacks, count))
		return (0);
	stacks->top_a = fill_a(args, count, stacks->a);
	if (has_dup(stacks->a, stacks->top_a))
	{
		free(stacks->a);
		free(stacks->b);
		return (0);
	}
	fill_b(count, stacks->b);
	stacks->top_b = 0;
	return (1);
}
