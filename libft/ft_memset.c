/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:24:18 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:33 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		byte_ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char test[] = "Not Crazy";
// 	printf("%s", test);
// 	printf("%s", "\n");
// 	ft_memset(test, ' ', 3);
// 	printf("%s", test);
// 	printf("%s", "\n");

// 	return (0);
// }