/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:15:30 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/30 20:15:56 by almeliky         ###   ########.fr       */
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
		ft_errprint("Error. Memory alocating error.");
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

t_node	*ft_newnode(char *str, t_node *prev, int len)
{
	char	*number;
	t_node	*newnode;
	int		i;

	i = 0;
	while (str[len] && str[len] != ' ')
		len++;
	number = malloc(len + 1);
	if (!number)
		ft_errprint("Error. Memory allocating failed.");
	number[len] = '\0';
	while (i < len)
	{
		number[i++] = *str;
		str++;
	}
	newnode = malloc(sizeof(t_node));
	if (!newnode)
		ft_errprint("Error. Memory allocating failed.");
	newnode->val = ft_atoi(number);
	newnode->prev = prev;
	free(number);
	return (newnode);
}

t_node	*ft_split_to_stack(char *str, t_node *start)
{
	t_node	*node;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str && *str != 0)
		{
			if (!start)
				node = ft_newnode(str, node, 0);
			else
			{
				node->next = ft_newnode(str, node, 0);
				node = node->next;
			}
		}
		if (!start)
			start = node;
		while (*str && *str != ' ')
			str++;
	}
	node->next = start;
	start->prev = node;
	// free(str);
	return (start);
}