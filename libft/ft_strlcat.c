/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:42:32 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:39 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	total_len;

	i = 0;
	src_len = 0;
	dst_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dst_len] != '\0')
		dst_len++;
	total_len = src_len + dst_len;
	if (size <= dst_len)
		return (size + src_len);
	while (i < src_len && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (total_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "Hello World!";
// 	char	dst[20] = "I say ";

// 	printf("%zu\n", ft_strlcat(dst, src, 20));
// 	printf("%s\n", dst);
// }
