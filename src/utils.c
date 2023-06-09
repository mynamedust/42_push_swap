/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:12:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 17:34:04 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
