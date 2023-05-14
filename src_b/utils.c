/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:12:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 17:31:10 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_errprint(char *message)
{
	if (!message)
		return ;
	while (*message)
	{
		write(2, message, 1);
		message++;
	}
	exit(1);
}

void	clear_stack(t_node **stack)
{
	t_node	*start;
	int		i;

	if (*stack == NULL)
		return ;
	i = 1;
	start = *stack;
	while (start->prev && start->prev != *stack)
	{
		i++;
		start = start->prev;
	}
	while (i-- > 0)
	{
		start = (*stack)->prev;
		free(*stack);
		*stack = NULL;
		*stack = start;
	}
	return ;
}

void	clear_exit(char *error, t_state *st, char *str)
{
	if (st->stack_a)
		clear_stack(&st->stack_a);
	if (st->stack_a)
		clear_stack(&st->stack_b);
	if (str)
		free(str);
	if (st->argstr)
		free(st->argstr);
	if (error)
		ft_errprint(error);
	exit(0);
}

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
