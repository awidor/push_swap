/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:50 by awidor            #+#    #+#             */
/*   Updated: 2025/03/24 13:05:21 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if ((unsigned char *)dest > (const unsigned char *)src
		&& (unsigned char *)dest < (const unsigned char *)src + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n);
// #include <stdio.h>

// int	main(void)
// {
// 	char	overlap_memmove[50] = "Youareoverlapping!";
// 	char	overlap_memcpy[50] = "Youareoverlapping!";

// 	ft_memmove(overlap_memmove + 1, overlap_memmove, 7);
// 	ft_memcpy(overlap_memcpy + 1, overlap_memcpy, 7);
// 	printf("%s\n", overlap_memmove);
// 	printf("%s\n", overlap_memcpy);
// 	return (0);
// }
