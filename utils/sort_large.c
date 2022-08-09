/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:48:07 by cleibeng          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:39 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

static int	ft_next(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;
	int		max;

	max = ft_strlen_stc(*stack_b);
	temp = (*stack_b);
	i = 1;
	while (temp->index < max && (temp) != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i > max / 2)
		return (1);
	return (0);
}

static void	put_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	n_size;
	int	i;

	size = (ft_strlen_stc(*stack_a) / 12) + 22;
	n_size = 1;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= (size * n_size))
		{
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->index
				< size * n_size - (size / 2) && (*stack_b) != NULL)
				ft_rb(stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
		if (i == size * n_size)
			n_size++;
	}
}

static int	rotate_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int	rotate_dir;
	int	temp_size;
	int	sa;

	sa = 0;
	rotate_dir = ft_next(stack_b);
	temp_size = ft_strlen_stc(*stack_b);
	while ((*stack_b) && (*stack_b)->index != temp_size)
	{
		if ((*stack_b)->index == temp_size - 1)
		{
			ft_pa(stack_b, stack_a);
			rotate_dir = ft_next(stack_b);
			sa = 1;
		}
		if (rotate_dir == 1 && (*stack_b))
			ft_rrb(stack_b);
		else if ((*stack_b) != NULL)
			ft_rb(stack_b);
	}
	return (sa);
}

static void	replace_in_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_max;

	size_max = ft_strlen_stc(*stack_b);
	while (ft_strlen_stc(*stack_a) < size_max)
	{
		if (rotate_in_b(stack_a, stack_b) == 1)
		{
			ft_pa(stack_b, stack_a);
			if ((*stack_b) && (*stack_b)->next != NULL
				&& (*stack_b)->index < (*stack_b)->next->index)
				ft_ss(stack_a, stack_b);
			else
				ft_sa(stack_a);
		}
		else
			ft_pa(stack_b, stack_a);
	}
}

void	ft_sort_large(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	add_index(stack_a);
	put_in_b(stack_a, &stack_b);
	replace_in_a(stack_a, &stack_b);
	ft_clean_stc(stack_a);
}
