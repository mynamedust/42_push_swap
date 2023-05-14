/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:59:05 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/14 17:00:32 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	s_swap(char *command, t_node **stack_a, t_node **stack_b)
{
	swap(NULL, stack_a);
	swap(NULL, stack_b);
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}

void	rotate_reverse(char *command, t_node **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
	if (command)
	{
		ft_putstr(command);
		ft_putstr("\n");
	}
}
