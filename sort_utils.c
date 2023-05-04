/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:26:45 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/04 16:52:28 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr_sort(int *arr, int lsize)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < lsize)
	{
		if (i == lsize - 1 || arr[i] < arr[i + 1])
			i++;
		else
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
	}
}

void 	numbers_simplify(t_node **stack, int lsize)
{
	int	arr[lsize];
	int	i;
	t_node	*tmp;

	tmp = *stack;
	i = -1;
	while (++i < lsize)
	{
		arr[i] = tmp->val;
		tmp = tmp->next;
	}
	arr_sort(&arr[0], lsize);
	i = 0;
	while (lsize-- > 0)
	{
		while (arr[i] != (*stack)->val)
			i++;
		(*stack)->val = i;
		(*stack) = (*stack)->next;
		i = 0;
	}
}
