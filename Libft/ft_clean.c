/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:17:45 by cleibeng          #+#    #+#             */
/*   Updated: 2022/06/12 13:53:07 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clean_str(char **str)
{
	free(*str);
	str = NULL;
	return (NULL);
}

void	ft_clean_tab(char	***tab)
{
	int	i;
	int	j;

	j = ft_strlen_tab(*tab);
	i = 0;
	while (i <= j)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}
