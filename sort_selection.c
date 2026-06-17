/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 18:16:00 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/30 18:16:00 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_min_to_top(t_stack *stacks)
{
	int	min;
	int	index;

	min = find_min_range(stacks->a, stacks->top_a, 0, stacks->top_a);
	index = find_value_index(stacks->a, stacks->top_a, min);
	while (stacks->a[stacks->top_a - 1] != min)
	{
		if (index >= stacks->top_a / 2)
			print_instruction(ra(stacks->a, stacks->top_a));
		else
			print_instruction(rra(stacks->a, stacks->top_a));
	}
}

static void	push_min_values(t_stack *stacks, int count)
{
	int	n;

	n = 0;
	while (n < count)
	{
		rotate_min_to_top(stacks);
		print_instruction(pb(stacks->a, &stacks->top_a,
				stacks->b, &stacks->top_b));
		n++;
	}
}

void	sort_selection(t_stack *stacks)
{
	int	count;

	count = stacks->top_a;
	push_min_values(stacks, count);
	while ((count - 1) > 0)
	{
		print_instruction(pa(stacks->a, &stacks->top_a,
				stacks->b, &stacks->top_b));
		count--;
	}
}
