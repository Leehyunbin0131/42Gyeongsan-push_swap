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

int	fill_a(char **args, int count, int *stack)
{
	int	i;
	int	current_index;
	int	nbr;

	i = 0;
	current_index = count - 1;
	while (i < count)
	{
		if (!parse_nbr(args[i], &nbr))
			return (0);
		stack[current_index] = nbr;
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
	if (count <= 0)
		return (0);
	if (!alloc_stk(stacks, count))
		return (0);
	stacks->top_a = fill_a(args, count, stacks->a);
	if (!stacks->top_a)
	{
		free(stacks->a);
		free(stacks->b);
		return (0);
	}
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
