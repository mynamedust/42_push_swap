/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:12:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/05 21:51:50 by almeliky         ###   ########.fr       */
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

void	clear_exit(char *error, t_state *st, char *str)
{
	t_node *start = NULL;

	start = st->stack_a;
	if (st->stack_a->prev)
		st->stack_a = st->stack_a->prev;
	while (st->stack_a != start)
	{
		printf("sdfsd\n");
		st->stack_a = st->stack_a->prev;
		if (st->stack_a->next && st->stack_a->next->prev && st->stack_a->next->prev == st->stack_a)
		{
			free(st->stack_a->next);
			st->stack_a->next = NULL;
		}
	}
	// if (st->stack_a)
	// 	free(st->stack_a);
	// while (st->stack_b && st->stack_b->prev)
	// {
	// 	free(st->stack_b->next);
	// 	st->stack_b = st->stack_b->prev;
	// }
	// if (st->stack_b)
	// 	free(st->stack_b);
	if (str)
		free(str);
	if (st->argstr)
		free(st->argstr);
	if (error)
		ft_errprint(error);
	exit(0);
}