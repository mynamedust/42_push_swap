/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:23:02 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/03 21:21:44 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *command, t_node *stack)
{
	int	swap;

	if (stack && stack->next)
	{
		swap = stack->val;
		stack->val = stack->next->val;
		stack->next->val = swap;
	}
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	s_swap(t_node *stack_a, t_node *stack_b)
{
	swap(NULL, stack_a);
	swap(NULL, stack_b);
	ft_putstr("ss\n");
}

void	push_util(t_node **swap, t_node **to)
{
	if (*to)
		(*swap)->next = (*to);
	if (*to == NULL)
	{
		*to = *swap;
		(*to)->next = *to;
		(*to)->prev = *to;
	}
	if ((*to)->next && (*to)->prev)
	{
		(*swap)->prev = (*to)->prev;
		(*to)->prev->next = *swap;
		if ((*to)->prev->prev == (*to)->prev)
			(*to)->prev->prev = *swap;
		(*swap)->next->prev = *swap;
	}
	*to = *swap;
}

void	push(char *command, t_node **from, t_node **to)
{
	t_node *swap;

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
	ft_putstr(command);
	ft_putstr("\n");
}

void	rotate(char *command, t_node **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	ft_putstr(command);
	ft_putstr("\n");
}

void	rotate_reverse(char *command, t_node **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
	ft_putstr(command);
	ft_putstr("\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(NULL, stack_a);
	rotate(NULL, stack_b);
	ft_putstr("rr\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rotate_reverse(NULL, stack_a);
	rotate_reverse(NULL, stack_b);
	ft_putstr("rrr\n");
}