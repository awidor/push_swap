/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:54:10 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:38 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*result;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len + 1);
	if (result == NULL)
		return (NULL);
	while (i < total_len && s1[j] != '\0')
		result[i++] = s1[j++];
	j = 0;
	while (i < total_len && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Hello ";
// 	char	s2[] = "World";

// 	printf("%s\n", ft_strjoin(s1, s2));
// }
