/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:33:54 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 17:22:25 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	state_init(t_state *pstate)
{
	pstate->stack_b = NULL;
	pstate->stack_a = NULL;
	pstate->argstr = NULL;
}

void	do_command(char *c, t_node **stack_a, t_node **stack_b, t_state *st)
{
	if (c[0] == 's' && c[1] == 'a' && c[2] == '\n')
		swap(NULL, stack_a);
	else if (c[0] == 's' && c[1] == 'b' && c[2] == '\n')
		swap(NULL, stack_b);
	else if (c[0] == 's' && c[1] == 's' && c[2] == '\n')
		s_swap(NULL, stack_a, stack_b);
	else if (c[0] == 'p' && c[1] == 'a' && c[2] == '\n')
		push(NULL, stack_b, stack_a);
	else if (c[0] == 'p' && c[1] == 'b' && c[2] == '\n')
		push(NULL, stack_a, stack_b);
	else if (c[0] == 'r' && c[1] == 'a' && c[2] == '\n')
		rotate(NULL, stack_a);
	else if (c[0] == 'r' && c[1] == 'b' && c[2] == '\n')
		rotate(NULL, stack_b);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'a' && c[3] == '\n')
		rotate_reverse(NULL, stack_a);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'b' && c[3] == '\n')
		rotate_reverse(NULL, stack_a);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == '\0')
		rr(NULL, stack_a, stack_b);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'r' && c[3] == '\n')
		rrr(NULL, stack_a, stack_b);
	else
		clear_exit("Error\n", st, NULL);
}

void	handle_operations(t_state *pstate, t_node **stack_a, t_node	**stack_b)
{
	char	*c;

	c = get_next_line(0);
	while (c != NULL)
	{
		do_command(c, stack_a, stack_b, pstate);
		c = get_next_line(0);
	}
}

void	print_result(int result)
{
	if (result)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	int		i;
	t_state	pstate;

	i = 0;
	if (argc <= 1)
		exit (0);
	state_init(&pstate);
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
	free((&pstate)->argstr);
	(&pstate)->argstr = NULL;
	numbers_simplify(&(&pstate)->stack_a, i);
	handle_operations(&pstate, &(&pstate)->stack_a, &(&pstate)->stack_b);
	print_result(check_order(pstate.stack_a, i) && pstate.stack_b == NULL);
	clear_exit(NULL, &pstate, NULL);
	return (0);
}
