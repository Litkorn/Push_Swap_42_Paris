/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:14:46 by cleibeng          #+#    #+#             */
/*   Updated: 2022/08/09 17:17:52 by cleibeng         ###   ########.fr       */
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

void	main2(char ***tab, char **argv, t_stack **stack_a)
{
	(*tab) = ft_split(argv[1], ' ');
	if ((*tab)[0] == NULL)
	{
		ft_clean_tab(tab);
		exit (0);
	}
	(*stack_a) = ft_create_stc(*tab);
	ft_clean_tab(tab);
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
		main2(&tab, argv, &stack_a);
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
