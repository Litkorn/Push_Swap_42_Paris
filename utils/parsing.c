/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:49 by cleibeng          #+#    #+#             */
/*   Updated: 2022/07/19 01:09:28 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

static int	ft_double_check(int argc, t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		i;
	int		k;

	temp = stack_a;
	temp2 = temp->next;
	i = 1;
	while (i < argc)
	{
		k = i;
		while (i < argc && temp2->content != temp->content)
		{
			temp2 = temp2->next;
			i++;
		}
		if (temp2 != NULL)
			return (-1);
		temp = temp->next;
		temp2 = temp->next;
		i = k + 1;
	}
	return (1);
}

static int	ft_int_check(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL && temp->content >= -2147483648
		&& temp->content <= 2147483647)
		temp = temp->next;
	if (temp == NULL)
		return (1);
	return (-1);
}

int	ft_order_check(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (1);
	return (0);
}

void	ft_parse(int i, t_stack *stack_a)
{
	if (ft_int_check(stack_a) != 1 || ft_double_check(i, stack_a) != 1)
	{
		write(2, "Error\n", 6);
		ft_clean_stc(&stack_a);
		exit (1);
	}
	if (ft_order_check(&stack_a) == 1)
	{
		ft_clean_stc(&stack_a);
		exit (0);
	}
}
