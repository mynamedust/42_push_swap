/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:10:32 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/05 18:56:16 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_node *stack, int lsize)
{
	if (lsize == 1)
		return (1);
	while (--lsize > 0)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	maxbit(t_node *stack, int lsize)
{
	int		maxnum;

	maxnum = stack->val;
	while (--lsize > 0)
	{
		if (maxnum < stack->val)
			maxnum = stack->val;
		stack = stack->next;
	}
	lsize = 8;
	while (lsize-- >= 0)
	{
		if (((maxnum >> lsize) & 1) == 1)
			return (lsize);
	}
	return (lsize);
}

void	sorting(t_node **stack_a, t_node **stack_b, int lsize, int j)
{
	int		max;
	int		i;
	t_node	*start;

	i = 0;
	start = *stack_a;
	max = maxbit(*stack_a, lsize);
	while (i <= max)
	{
		while (j++ < lsize)
		{
			if ((((*stack_a)->val >> i) & 1) == 1)
				rotate("ra", stack_a);
			else
				push("pb", stack_a, stack_b);
		}
		j = 0;
		while (*stack_b != NULL)
			push("pa", stack_b, stack_a);
		i++;
	}
}
