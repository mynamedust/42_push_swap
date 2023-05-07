/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:12:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/07 16:01:00 by almeliky         ###   ########.fr       */
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

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	while (*str == 9 || *str == 10 || *str == 11
		|| *str == 12 || *str == 13 || *str == 0 || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		result += *str - '0';
		result *= 10;
		str++;
	}
	result /= 10;
	if (result > 2147483647)
		clear_exit("Error. Passed argument must be an integer.\n", st, str);
	return (result * sign);
}

void	clear_stack(t_node *stack)
{
	t_node *start = NULL;
	
	if (stack == NULL)
		return ;
	start = stack;
	if (stack->prev)
		stack = stack->prev;
	while (stack != start)
	{
		stack= stack->prev;
		if (stack->next && stack->next->prev && stack->next->prev == stack)
		{
			free(stack->next);
			stack->next = NULL;
		}
	}
	if (stack)
		free(stack);
}

void	clear_exit(char *error, t_state *st, char *str)
{
	clear_stack(st->stack_a);
	clear_stack(st->stack_b);
	if (str)
		free(str);
	// if (st->argstr)
	// 	free(st->argstr);
	if (error)
		ft_errprint(error);
	exit(0);
}