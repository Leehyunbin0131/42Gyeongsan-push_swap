/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:05:56 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 19:35:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_sort(t_stack *stacks, char **av, int i)
{
	if (!ft_strcmp(av[i], "--simple"))
		stacks->s_tyep = SIMPLE;
	else if (!ft_strcmp(av[i], "--medium"))
		stacks->s_tyep = MEDIUM;
	else if (!ft_strcmp(av[i], "--complex"))
		stacks->s_tyep = COMPLEX;
	else if (!ft_strcmp(av[i], "--adaptive"))
		stacks->s_tyep = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	arg_start(t_stack *stacks, int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (0);
	stacks->bench = 0;
	stacks->s_tyep = ADAPTIVE;
	i = 1;
	if (av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strcmp(av[i], "--bench"))
		{
			stacks->bench = 1;
			i++;
		}
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (!set_sort(stacks, av, i))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			i++;
		}
	}
	return (i);
}

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
	if (nums->split)
		free_split(nums->args);
	if (!is_sorted(stacks->a, stacks->top_a))
		sort_selection(stacks);
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
	free_stacks(&stacks);
	return (0);
}
