/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:23:02 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 17:00:56 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *command, t_node **stack)
{
	int	swap;

	if (*stack && (*stack)->next)
	{
		swap = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = swap;
	}
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	push(char *command, t_node **from, t_node **to)
{
	t_node	*swap;

	if (*from == NULL)
		return ;
	swap = *from;
	if (swap->next && swap->prev && swap->next != swap)
	{
		*from = (*from)->next;
		(*from)->prev = swap->prev;
		(*from)->prev->next = *from;
	}
	else
		*from = NULL;
	push_util(&swap, to);
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	rotate(char *command, t_node **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	rr(char *command, t_node **stack_a, t_node **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	rrr(char *command, t_node **stack_a, t_node **stack_b)
{
	rotate_reverse(NULL, stack_a);
	rotate_reverse(NULL, stack_b);
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}
