/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:16:47 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:26 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char *string;
// 	size_t i;
// 	string = ft_calloc(5, sizeof(char));
// 	for (i = 0; i < 5; i++)
// 		printf("%d", string[i]);
// }