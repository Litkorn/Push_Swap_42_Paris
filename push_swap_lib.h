/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:58 by cleibeng          #+#    #+#             */
/*   Updated: 2022/08/09 14:51:45 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"

//typedef
typedef struct s_stack
{
	long long int	content;
	int				index;
	struct s_stack	*next;
}					t_stack;

//create_list.c
long long int	ft_atoi_push(const char *str);
t_stack			*ft_create_stc(char **argv);
t_stack			*ft_dup_stc(t_stack *stack_a);

//parsing.c
void			ft_parse(int i, t_stack *stack_a);
int				ft_order_check(t_stack **stack_a);

//operations_a.c
void			ft_sa(t_stack **stack);
void			ft_pa(t_stack **stack_b, t_stack **stack_a);
void			ft_ra(t_stack **stack);
void			ft_rra(t_stack **stack);
void			ft_ss(t_stack **stack_a, t_stack **stack_b);

//operations_b.c
void			ft_sb(t_stack **stack);
void			ft_pb(t_stack **stack_a, t_stack **stack_b);
void			ft_rb(t_stack **stack);
void			ft_rrb(t_stack **stack);

//utils.c
int				ft_check_min(t_stack **stack_a);
void			ft_clean_stc(t_stack **stack_a);
int				ft_strlen_stc(t_stack *stack_a);
void			print_stack(t_stack **stack);
int				ft_check_ss(t_stack *stack_a, t_stack *stack_b);

//autre
void			ft_sort_large(t_stack **stack_a);
void			add_index(t_stack **stack_a);
void			ft_sort_small(int nb, t_stack **stack_a);

#endif
