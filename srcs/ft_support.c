/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:27:17 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/12/08 22:49:32 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_2D(char ***tab)
{
	char	**tmp;

	tmp = *tab;

	while (**tab)
	{
		free(**tab);
		(*tab)++;
	}
	free (tmp);
}


int		up_to_sqrt(const int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}
