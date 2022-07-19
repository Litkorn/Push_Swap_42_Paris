/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:32:10 by cleibeng          #+#    #+#             */
/*   Updated: 2022/07/18 21:06:02 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

int	ft_strlen_stc(t_stack *stack_a)
{
	t_stack	*temp;
	size_t	i;

	temp = stack_a;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_clean_stc(t_stack **stack_a)
{
	t_stack	*temp;

	while ((*stack_a) != NULL)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		(*stack_a) = temp;
	}
}

int	ft_check_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->content > stack_a->next->content
		&& stack_b->content > stack_b->next->content)
		return (1);
	return (0);
}

int	ft_check_min(t_stack **stack_a)
{
	int		i;
	int		index;
	int		h;
	t_stack	*temp;

	index = 0;
	h = 0;
	temp = (*stack_a);
	i = temp->content;
	while (temp != NULL)
	{
		if (temp->content < i)
		{
			i = temp->content;
			h = index;
		}
		index++;
		temp = temp->next;
	}
	temp = NULL;
	return (h);
}

void	add_index(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		i;

	temp = (*stack_a);
	temp2 = (*stack_a);
	while (temp != NULL)
	{
		i = 1;
		while (temp2 != NULL)
		{
			if (temp2->content < temp->content)
				i++;
			temp2 = temp2->next;
		}
		temp->index = i;
		temp = temp->next;
		temp2 = (*stack_a);
	}
}
