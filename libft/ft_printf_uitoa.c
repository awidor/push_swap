/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:33:16 by awidor            #+#    #+#             */
/*   Updated: 2025/07/23 14:09:56 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(unsigned int n)
{
	long	nb;
	size_t	len;

	len = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t		len;
	int long	nb;
	char		*result;

	nb = n;
	len = get_int_len(n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		len--;
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
