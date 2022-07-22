/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:14:46 by cleibeng          #+#    #+#             */
/*   Updated: 2022/07/22 06:13:27 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

static void	clean_main(char ***tab, t_stack **stack)
{
	if (tab != NULL)
		ft_clean_tab(tab);
	if (*stack)
		ft_clean_stc(stack);
	ft_printf("Error: malloc failed :(\n");
	exit (1);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		i;
	t_stack	*stack_a;

	tab = NULL;
	stack_a = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		stack_a = ft_create_stc(tab);
		ft_clean_tab(&tab);
	}
	else
		stack_a = ft_create_stc(&argv[1]);
	if (argc == 2 && (stack_a == NULL || tab == NULL))
		clean_main(&tab, &stack_a);
	i = ft_strlen_stc(stack_a);
	ft_parse(i, stack_a);
	if (i <= 5)
		ft_sort_small(i, &stack_a);
	else
		ft_sort_large(&stack_a);
	return (0);
}
