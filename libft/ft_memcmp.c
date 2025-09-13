/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:06:07 by awidor            #+#    #+#             */
/*   Updated: 2025/03/24 13:03:48 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_byte = ((const unsigned char *)s1);
	const unsigned char	*s2_byte = ((const unsigned char *)s2);

	i = 0;
	while (i < n)
	{
		if (s1_byte[i] != s2_byte[i])
		{
			return (s1_byte[i] - s2_byte[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "Hell3";
// 	char str2[] = "Hell1";

// 	int result = ft_memcmp(str1, str2, 5);
// 	printf("%d", result);
// }