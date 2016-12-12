/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:17:41 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/12 18:00:17 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	error_msg_exit(const char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}
