/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:16:33 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:41 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	if (ft_strlen(little) == 0)
	{
		return ((char *)big);
	}
	little_len = 0;
	little_len = ft_strlen(little);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && i + j < len && big[i + j] == little[j])
			j++;
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	big[] = "i am a big string";
// 	char	little[] = "str";

// 	printf("%s", ft_strnstr(big, little, 55));
// }
