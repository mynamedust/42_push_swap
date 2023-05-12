/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:15:30 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/12 16:05:20 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_argjoin(char **argv, int argc)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (++i < argc)
		len += ft_strlen(argv[i]) + 2;
	newstr = malloc(len + 1);
	if (!newstr)
		ft_errprint("Error\n");
	newstr[len] = '\0';
	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		newstr[len++] = ' ';
		while (argv[i][j])
			newstr[len++] = argv[i][j++];
		newstr[len++] = ' ';
		i++;
	}
	return (newstr);
}

t_node	*ft_newnode(char *str, t_state *st, int len, int count)
{
	char	*number;
	t_node	*newnode;
	int		i;

	i = 0;
	while (str[len] && str[len] != ' ')
		len++;
	number = malloc(len + 1);
	if (!number)
		clear_exit("Error\n", st, NULL);
	number[len] = '\0';
	while (i < len)
	{
		number[i++] = *str;
		str++;
	}
	i = ft_atoi(number, st);
	newnode = malloc(sizeof(t_node));
	if (!newnode)
		clear_exit("Error\n", st, number);
	newnode->val = i;
	newnode->prev = st->stack_a;
	newnode->listsize = count;
	free(number);
	return (newnode);
}

int	listsize(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str && *str != ' ')
			count++;
		while (*str && *str != ' ')
			str++;
	}
	return (count);
}

t_node	*ft_split_to_stack(t_state *st, char *str, t_node *start, int count)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str && *str != 0)
		{
			if (!start)
				st->stack_a = ft_newnode(str, st, 0, count);
			else
			{
				st->stack_a->next = ft_newnode(str, st, 0, count);
				st->stack_a = st->stack_a->next;
			}
		}
		if (!start)
			start = st->stack_a;
		while (*str && *str != ' ')
			str++;
	}
	st->stack_a->next = start;
	start->prev = st->stack_a;
	return (start);
}