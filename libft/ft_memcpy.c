/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:46:50 by awidor            #+#    #+#             */
/*   Updated: 2025/03/24 13:05:25 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char test[] = "Hello!";
// 	char test2[] = "invisiNO NOT ANYMORE";

// 	printf("%s", (char *)ft_memcpy(test2, test, 6));
// }