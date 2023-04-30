/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:23:02 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/30 21:48:18 by almeliky         ###   ########.fr       */
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
		ft_putstr("%s\n", command);
}

void	s_swap(t_node *stack_a, t_node *stack_b)
{
	swap(NULL, stack_a);
	swap(NULL, stack_a);
	ft_putstr("ss\n");
}

void	push(char *command, t_node *stack_a, t_node *stack_b)
{
	t_node *swap;
	if (command == "pb")
	{
		stack_a->prev->next = stack_a->next;
		stack_a->next->prev = stack_a->prev;
		swap = stack_b;
		stack_b = stack_a;
		stack_b->next = swap;
		stack_b->prev = swap->prev;
		swap->prev->next = stack_b;
		swap->prev = stack_b;
	}
	else
	{
		stack_b->prev->next = stack_b->next;
		stack_b->next->prev = stack_b->prev;
		swap = stack_a;
		stack_a = stack_b;
		stack_a->next = swap;
		stack_a->prev = swap->prev;
		swap->prev->next = stack_a;
		swap->prev = stack_a;
	}
	if (command == "pb" || command == "pa")
		ft_putstr(command);
}