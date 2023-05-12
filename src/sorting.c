/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:10:32 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/12 17:42:14 by almeliky         ###   ########.fr       */
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
	lsize = sizeof(int) * 8;
	while (lsize-- >= 0)
	{
		if (((maxnum >> lsize) & 1) == 1)
			return (lsize);
	}
	return (lsize);
}

void	triple_sort(t_node **stack, int max)
{
	if ((*stack)->val == max)
		rotate("ra", stack);
	else if ((*stack)->next->val == max)
		rotate_reverse("rra", stack);
	if ((*stack)->val > (*stack)->next->val)
		swap("sa", stack);
}

void	rotate_while_push(char stack_name, t_node **stack, int value, int lsize)
{
	if (lsize / 2 < find_position(*stack, value))
	{
		while ((*stack)->val != value)
		{
			if (stack_name == 'a')
				rotate_reverse("rra", stack);
			else
				rotate_reverse("rrb", stack);
		}
	}
	else
	{
		while ((*stack)->val != value)
		{
			if (stack_name == 'a')
				rotate("ra", stack);
			else
				rotate("rb", stack);
		}
	}
}

void	five_sort(t_node **stack_a, t_node **stack_b, int lsize)
{
	int		max;
	int		min;
	
	min = 0;
	max = 4;
	rotate_while_push('a', stack_a, max, lsize);
	push("pb", stack_a, stack_b);
	rotate_while_push('a', stack_a, min, lsize);
	push("pb", stack_a, stack_b);
	triple_sort(stack_a, 3);
	push("pa", stack_b, stack_a);
	push("pa", stack_b, stack_a);
	rotate("ra", stack_a);
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
		if (check_order(*stack_a, lsize))
			return ;
	}
}
