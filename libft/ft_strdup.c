/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:02:33 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:37 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char test1[] = "I am coping hard rn";
// 	printf("%s\n", test1);
// 	printf("%s\n", ft_strdup(test1));
// }