/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:12:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/10 20:03:10 by almeliky         ###   ########.fr       */
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
	ft_putstr(message);
	exit(1);
}

int	ft_atoi(char *str, t_state *st)
{
	int			sign;
	long int	result;
	char		*newstr;

	newstr = str;
	sign = 1;
	result = 0;
	if (!*newstr)
		return (0);
	while (*newstr == 9 || *newstr == 10 || *newstr == 11
		|| *newstr == 12 || *newstr == 13 || *newstr == 0 || *newstr == ' ')
		newstr++;
	if (*newstr == '-')
		sign = -1;
	if (*newstr == '-' || *newstr == '+')
		newstr++;
	while ((*newstr >= '0' && *newstr <= '9') && *newstr)
	{
		result *= 10;
		result += *newstr - '0';
		newstr++;
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			clear_exit("Error. Passed argument must be an integer.\n", st, str);
	}
	return (result * sign);
}

void	clear_stack(t_node **stack)
{
	t_node *start;
	
	if (*stack == NULL)
		return ;
	start = *stack;
	if ((*stack)->prev)
		*stack = (*stack)->prev;
	while (*stack && *stack != start)
	{
		if (*stack && (*stack)->next &&
			(*stack)->next->prev && (*stack)->next->prev == (*stack))
		{
			free((*stack)->next);
			(*stack)->next = NULL;
		}
		if (!((*stack)->prev))
			break;
		(*stack) = (*stack)->prev;
	}
	if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
}

void	clear_exit(char *error, t_state *st, char *str)
{
	if (st->stack_a)
		clear_stack(&(st->stack_a));
	if (st->stack_a)
		clear_stack(&(st->stack_b));
	if (str)
		free(str);
	if (st->argstr)
		free(st->argstr);
	if (error)
		ft_errprint(error);
	exit(0);
}