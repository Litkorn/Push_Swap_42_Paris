/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:37:08 by cleibeng          #+#    #+#             */
/*   Updated: 2022/07/08 16:30:43 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_lib.h"

long long int	ft_atoi_push(const char *str)
{
	int				i;
	int				n;
	long long int	a;

	i = 0;
	n = 1;
	a = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	if (str[i - 1] < '0' || str[i - 1] > '9')
		return (2147483650);
	return (a * n);
}

static t_stack	*create_stc_part2(t_stack *stack_a, char **argv)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		i;

	i = 0;
	temp = stack_a;
	temp2 = temp->next;
	while (argv[i] != NULL)
	{
		temp2 = malloc(sizeof(t_stack));
		if (!temp2)
			return (NULL);
		temp2->content = ft_atoi_push(argv[i]);
		temp2->index = 0;
		temp2->next = NULL;
		temp->next = temp2;
		temp = temp->next;
		i++;
	}
	return (stack_a);
}

t_stack	*ft_create_stc(char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	temp = stack_a;
	temp->content = ft_atoi_push(argv[0]);
	temp->index = 0;
	temp->next = NULL;
	return (create_stc_part2(stack_a, &argv[1]));
}

static t_stack	*dup_stc_part2(t_stack *stack_a, t_stack *stack_a2)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;

	temp = stack_a;
	temp2 = stack_a2;
	temp3 = NULL;
	temp = temp->next;
	while (temp != NULL)
	{
		temp3 = malloc(sizeof(t_stack));
		if (!temp3)
			return (NULL);
		temp3->content = temp->content;
		temp3->index = 0;
		temp3->next = NULL;
		temp2->next = temp3;
		temp2 = temp2->next;
		temp = temp->next;
	}
	return (stack_a2);
}

t_stack	*ft_dup_stc(t_stack *stack_a)
{
	t_stack	*stack_a2;

	stack_a2 = malloc(sizeof(t_stack));
	if (!stack_a2)
		return (NULL);
	stack_a2->content = stack_a->content;
	stack_a2->index = 0;
	stack_a2->next = NULL;
	return (dup_stc_part2(stack_a, stack_a2));
}
