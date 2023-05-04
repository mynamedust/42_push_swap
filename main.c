/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:21 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/04 17:10:14 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_validate(char *arg)
{
	int	i;
	int	num;

	if (!arg || !(arg[0]))
		return (0);
	num = 0;
	i = 0;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '-' && arg[i] != ' ')
			return (0);
		if (arg[i] == '-' && (arg[i + 1] < '0' || arg[i + 1] > '9'))
			return (0);
		if (arg[i] == '-' && i != 0 && arg[i - 1] != ' ')
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			num++;
		i++;
	}
	if (num <= 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b = NULL;
	char	*str;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (!arg_validate(argv[i]))
			ft_errprint("Error. Wrong arguments format.\n");
		i++;
	}
	str = ft_argjoin(argv, argc);
	i = listsize(str);
	stack_a = ft_split_to_stack(str, NULL, i);
	free(str);
	numbers_simplify(&stack_a, i);
	sorting(&stack_a, &stack_b, i);
	return (0);
}
