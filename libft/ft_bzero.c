/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awidor <awidor@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:38:44 by awidor            #+#    #+#             */
/*   Updated: 2025/03/21 17:05:25 by awidor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	byte_ptr = (unsigned char *)s;
	while (i < n)
	{
		byte_ptr[i] = '\0';
		i++;
	}
}
