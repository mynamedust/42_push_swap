/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:23:02 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/02 19:40:22 by almeliky         ###   ########.fr       */
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

void	push(char *command, t_node **from, t_node **to)
{
	t_node *swap;

	if (*from == NULL)
		return ;
	swap = *from;
	*from = (*from)->next;
	(*from)->prev = swap->prev;
	(*from)->prev->next = *from;
	swap->next = *to;
	if (*to != NULL)
	{
		(*to)->prev->next = swap;
		swap->prev = (*to)->prev;
	}
	*to = swap;
	ft_putstr(command);
	ft_putstr("\n");
}
