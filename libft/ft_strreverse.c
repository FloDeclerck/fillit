/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:53:47 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/16 11:09:18 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strreverse(char *s)
{
	size_t	i;
	size_t	j;
	char	bfr;

	i = 0;
	j = strlen(s) - 1;
	while (i < j)
	{
		bfr = s[i];
		s[i] = s[j];
		s[j] = bfr;
		j--;
		i++;
	}
}
