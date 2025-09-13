/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:39:44 by awidor            #+#    #+#             */
/*   Updated: 2025/07/23 14:10:04 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned long number, char *hexset)
{
	int	buffer[20];
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (number > 0)
	{
		buffer[i] = number % 16;
		number = number / 16;
		i++;
		count++;
	}
	while (i > 0)
	{
		i--;
		if (write(1, &hexset[buffer[i]], 1) == -1)
			return (-1);
	}
	return (count);
}

int	handle_hex(unsigned long number, unsigned int uppercase)
{
	char	*hexset;
	int		count;

	count = 0;
	if (number == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (uppercase == 1)
		hexset = "0123456789ABCDEF";
	else
		hexset = "0123456789abcdef";
	count = print_hex(number, hexset);
	return (count);
}
