/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:16:47 by cleibeng          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:42 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	if ((temp->content < temp->next->next->content)
		&& (temp->next->next->content < temp->next->content))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((temp->content < temp->next->content)
		&& (temp->content > temp->next->next->content))
		ft_rra(stack_a);
	else if ((temp->content > temp->next->content)
		&& (temp->content < temp->next->next->content))
		ft_sa(stack_a);
	else if ((temp->content > temp->next->next->content)
		&& (temp->next->next->content > temp->next->content))
		ft_ra(stack_a);
	else
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	sort_four(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_check_min(stack_a) == 1)
		ft_sa(stack_a);
	else if (ft_check_min(stack_a) == 2)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (ft_check_min(stack_a) == 3)
		ft_rra(stack_a);
	if (ft_order_check(stack_a) == 1)
		ft_clean_stc(stack_a);
	else
	{
		ft_pb(stack_a, &stack_b);
		sort_three(stack_a);
		ft_pa(&stack_b, stack_a);
	}
}

static void	move_min(t_stack **stack_a)
{
	if (ft_check_min(stack_a) > 2)
	{
		while (ft_check_min(stack_a) != 0)
			ft_rra(stack_a);
	}
	else if (ft_check_min(stack_a) <= 2)
	{
		while (ft_check_min(stack_a) != 0)
			ft_ra(stack_a);
	}
}

void	sort_five(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_check_min(stack_a) == 1)
		ft_sa(stack_a);
	if (ft_order_check(stack_a) == 1)
	{
		ft_clean_stc(stack_a);
		exit (0);
	}
	move_min(stack_a);
	if (ft_order_check(stack_a) == 0)
		ft_pb(stack_a, &stack_b);
	sort_four(stack_a);
	ft_printf("pa\n");
	free(stack_b);
}

void	ft_sort_small(int nb, t_stack **stack_a)
{
	if (nb == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_printf("sa\n");
		ft_clean_stc(stack_a);
	}
	else if (nb == 3)
		sort_three(stack_a);
	else if (nb == 4)
		sort_four(stack_a);
	else if (nb == 5)
		sort_five(stack_a);
	ft_clean_stc(stack_a);
}
