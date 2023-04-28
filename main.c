/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:59:21 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/28 20:27:10 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	int	i;
	// t_node	*stack_a;

	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
	{
		if (!arg_validate(argv[i]))
			ft_errprint("Error. Wrong arguments format.\n");
		i++;
	}
	printf("111\n");
	printf("222\n");
	printf("%s\n", ft_argjoin(argv, argc));
	// stack_a = ft_split(ft_argjoin(argv, argc));
	// sorting(stack_a);
	return (0);
}