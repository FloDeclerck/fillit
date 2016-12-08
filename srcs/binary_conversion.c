/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmusella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:12:55 by rmusella          #+#    #+#             */
/*   Updated: 2016/12/05 18:17:00 by rmusella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		shift_top_left(int value)
{
	if (value == 0)
		return (0);
	while ((value & LEFT_MASK) == 0)
		value <<= 1;
	while ((value & TOP_MASK) == 0)
		value <<= 4;
	return (value);
}

unsigned short		str_to_bin(char *str)
{
	int		i;
	int		value;

	value = 0x0000;
	i = 0xF;
	while (str && *str)
	{
		if (*str == CHAR_BLOCK)
			value = value | 1 << i;
		str++;
	i--;
	}
	value = shift_top_left(value);
	return (value);
}
