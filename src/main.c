/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:21 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/12 15:44:47 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_validate(char *arg)
{
	int	i;
	int	num;

	if (!arg || !(arg[0]))
		return (0);
	num = 0;
	i = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-' && arg[i] != ' ')
			return (0);
		if (arg[i] == '-' && (arg[i + 1] < '0' || arg[i + 1] > '9'))
			return (0);
		if (arg[i] == '-' && i != 0 && arg[i - 1] != ' ')
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			num++;
		i++;
	}
	if (num <= 0)
		return (0);
	return (1);
}

int	double_check(t_node *stack, int lsize)
{
	int	i;
	int	num;
	int	j;

	i = 0;
	j = 0;
	while (i++ < lsize)
	{
		num = stack->val;
		while (++j < lsize)
		{
			stack = stack->next;
			if (stack->val == num)
				return (1);
		}
		j = 0;
	}
	return (0);
}

void	state_init(t_state *pstate)
{
	pstate->stack_b = NULL;
	pstate->stack_a = NULL;
	pstate->argstr = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	t_state	pstate;

	state_init(&pstate);
	i = 0;
	if (argc == 1)
		exit(0);
	while (++i < argc)
	{
		if (!arg_validate(argv[i]))
			ft_errprint("Error\n");
	}
	pstate.argstr = ft_argjoin(argv, argc);
	i = listsize((&pstate)->argstr);
	pstate.stack_a = ft_split_to_stack(&pstate, (&pstate)->argstr, NULL, i);
	if (double_check(pstate.stack_a, i))
		clear_exit("Error\n", &pstate, NULL);
	if (check_order(pstate.stack_a, i))
		exit(0);
	free((&pstate)->argstr);
	(&pstate)->argstr = NULL;
	numbers_simplify(&(&pstate)->stack_a, i);
	if (i < 4)
	{
		triple_sort(&(&pstate)->stack_a, 2);
		clear_exit(NULL, &pstate, NULL);
	}
	if (i == 5)
	{
		five_sort(&(&pstate)->stack_a, &(&pstate)->stack_b, i);
		clear_exit(NULL, &pstate, NULL);
	}
	sorting(&(&pstate)->stack_a, &(&pstate)->stack_b, i, 0);
	clear_exit(NULL, &pstate, NULL);
	return (0);
}