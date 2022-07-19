/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:56:08 by cleibeng          #+#    #+#             */
/*   Updated: 2022/07/15 01:24:39 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

//swap 2 first elements of the stack
void	ft_sb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;

	if (*stack && (*stack)->next != NULL)
	{
		temp = *stack;
		temp2 = temp->next;
		temp3 = temp2->next;
		temp->next = temp3;
		temp2->next = temp;
		*stack = temp2;
		ft_printf("sb\n");
	}
}

//take the 1st of a and put it on the top of b
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;

	if (stack_a)
	{
		temp = *stack_b;
		temp2 = *stack_a;
		temp3 = temp2->next;
		*stack_a = temp3;
		temp2->next = temp;
		*stack_b = temp2;
		ft_printf("pb\n");
	}
}

//take the 1st and make it the last
void	ft_rb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;

	temp = *stack;
	temp3 = temp;
	temp2 = temp->next;
	if (temp->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = temp3;
		temp = temp->next;
		temp->next = NULL;
		*stack = temp2;
		ft_printf("rb\n");
	}
}

//take the last and make it the first
void	ft_rrb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_last;
	t_stack	*temp_prev;

	temp = (*stack);
	if (temp && temp->next)
	{
		temp_last = temp;
		while (temp_last->next)
		{
			temp_prev = temp_last;
			temp_last = temp_last->next;
		}
		temp_last->next = temp;
		temp_prev->next = NULL;
		(*stack) = temp_last;
		ft_printf("rrb\n");
	}
}
