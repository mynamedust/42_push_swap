/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:06:13 by almeliky          #+#    #+#             */
/*   Updated: 2023/05/05 21:22:50 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node {
	int				val;
	int				listsize;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_state {
	t_node	*stack_a;
	t_node	*stack_b;
	char	*argstr;
}	t_state;


int		ft_strlen(const char *s);
void	ft_putstr(char *s);
int		ft_atoi(char *str, t_state *st);
void	ft_errprint(char *message);
int		arg_validate(char *arg);
char	*ft_argjoin(char **argv, int argc);
t_node	*ft_split_to_stack(t_state *st, char *str, t_node *start, int count);
t_node	*ft_newnode(char *str, t_state *st, int len, int count);
int		listsize(char *str);
int		main(int argc, char **argv);
void	swap(char *command, t_node *stack);
void	s_swap(t_node *stack_a, t_node *stack_b);
void	push(char *command, t_node **stack_a, t_node **stack_b);
void	push_util(t_node **swap, t_node **to);
void	rotate(char *command, t_node **stack);
void	rotate_reverse(char *command, t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	arr_sort(int *arr, int lsize);
void 	numbers_simplify(t_node **stack, int lsize);
void	sorting(t_node **stack_a, t_node **stack_b, int lsize, int j);
int		check_order(t_node *stack, int lsize);
void	clear_exit(char *error, t_state *st, char *str);

#endif