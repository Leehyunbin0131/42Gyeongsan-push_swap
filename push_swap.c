/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:05:56 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 21:01:06 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prep_args(int ac, char **av, int start, t_nums *nums)
{
	if (ac - start == 1)
	{
		nums->args = ft_split(av[start], ' ');
		nums->split = 1;
		if (!nums->args)
			return (0);
		nums->count = arr_len(nums->args);
		if (nums->count == 0)
		{
			free_split(nums->args);
			return (0);
		}
		return (1);
	}
	nums->split = 0;
	nums->count = ac - start;
	nums->args = &av[start];
	return (1);
}

static int	run_push_swap(t_stack *stacks, t_nums *nums)
{
	if (!init_stk(stacks, nums->args, nums->count))
		return (0);
	stacks->disorder = calc_disorder(stacks->a, stacks->top_a);
	if (nums->split)
		free_split(nums->args);
	if (!is_sorted(stacks->a, stacks->top_a))
	{
		if (stacks->s_type == SIMPLE)
			sort_simple(stacks);
		if (stacks->s_type == MEDIUM)
			sort_simple(stacks);
		if (stacks->s_type == COMPLEX)
			sort_simple(stacks);
		if (stacks->s_type == ADAPTIVE)
		{
			if (stacks->disorder < 0.2)
				sort_simple(stacks);
			if (stacks->disorder < 0.5)
				sort_simple(stacks);
			if (stacks->disorder >= 0.5)
				sort_simple(stacks);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stacks;
	t_nums	nums;
	int		start;

	start = arg_start(&stacks, ac, av);
	if (!start)
		return (0);
	if (!prep_args(ac, av, start, &nums))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!run_push_swap(&stacks, &nums))
	{
		if (nums.split)
			free_split(nums.args);
		write(2, "Error\n", 6);
		return (0);
	}
	if (stacks.bench)
		print_bench(&stacks);
	free_stacks(&stacks);
	return (0);
}
