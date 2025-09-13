/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:18:05 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:30 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n)
{
	long	nb;
	size_t	len;

	len = 0;
	nb = n;
	if (n == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
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
	if (nb < 0)
	{
		nb = nb * -1;
		result[0] = '-';
	}
	while (nb > 0)
	{
		len--;
		result[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}

// #include <limits.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int src = INT_MAX;
// 	char *result;
// 	result = ft_itoa(src);
// 	printf("%s\n", result);
// 	free(result);
// }