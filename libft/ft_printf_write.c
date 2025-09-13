/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:20:24 by awidor            #+#    #+#             */
/*   Updated: 2025/07/23 14:10:10 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(void *ptr)
{
	int	count;

	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2;
	if (ptr == NULL)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}
	count += handle_hex((unsigned long)ptr, 0);
	return (count);
}

int	print_unsigned_int(unsigned int n, int fd)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_uitoa(n);
	if (result == NULL)
		return (-1);
	while (result[i] != '\0')
	{
		if (write(fd, &result[i], 1) == -1)
		{
			free(result);
			return (-1);
		}
		i++;
	}
	free(result);
	return (i);
}

int	counted_ft_putnbr_fd(int n, int fd)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_itoa(n);
	if (result == NULL)
		return (-1);
	while (result[i] != '\0')
	{
		if (write(fd, &result[i], 1) == -1)
		{
			free(result);
			return (-1);
		}
		i++;
	}
	free(result);
	return (i);
}

int	counted_ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
