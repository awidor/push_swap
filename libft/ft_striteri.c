/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:01 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:37 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// void	test_ft_striteri(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (c[0] >= 'a' && c[0] <= 'z')
// 	{
// 		c[0] -= 32;
// 	}
// 	printf("%c", c[0]);
// }

// int	main(void)
// {
// 	char	string[] = "hello world";

// 	ft_striteri(string, test_ft_striteri);
// 	return (0);
// }
