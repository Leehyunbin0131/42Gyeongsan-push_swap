/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stacks)
{
	free(stacks->a);
	free(stacks->b);
}

int	is_sorted(int *a, int top)
{
	int	i;

	i = 0;
	while (i < top - 1)
	{
		if (a[i] <= a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min_range(int *stack, int top, int start, int range)
{
	int	i;
	int	end;
	int	min;

	if (top <= 0 || start < 0 || start >= top)
		return (0);
	end = start + range;
	if (end >= top)
		end = top - 1;
	min = stack[start];
	i = start + 1;
	while (i <= end)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	find_value_index(int *stack, int top, int value)
{
	int	i;

	i = 0;
	while (i < top)
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
