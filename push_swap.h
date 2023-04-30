/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:06:13 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/30 20:11:14 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node {
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
void	ft_errprint(char *message);
int		arg_validate(char *arg);
char	*ft_argjoin(char **argv, int argc);
t_node	*ft_newnode(char *str, t_node *prev, int len);
t_node	*ft_split_to_stack(char *str, t_node *start);
int		main(int argc, char **argv);

#endif